/*
 * Stellarium
 * Copyright (C) 2002 Fabien Chereau
 * Copyright (C) 2012 Timothy Reaves
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */

#include <vector>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QDir>

#include "ConstellationMgr.hpp"
#include "Constellation.hpp"
#include "StarMgr.hpp"
#include "StelUtils.hpp"
#include "StelApp.hpp"
#include "StelTextureMgr.hpp"
#include "StelProjector.hpp"
#include "StelObjectMgr.hpp"
#include "StelLocaleMgr.hpp"
#include "StelSkyCultureMgr.hpp"
#include "StelModuleMgr.hpp"
#include "StelFileMgr.hpp"
#include "StelCore.hpp"
#include "StelPainter.hpp"
#include "StelSkyDrawer.hpp"

static int CONSTELLATION_ART_SCALE = 1; //was 2

using namespace std;

// constructor which loads all data from appropriate files
ConstellationMgr::ConstellationMgr(StarMgr *_hip_stars)
	: hipStarMgr(_hip_stars),
	  artFadeDuration(1.),
	  artIntensity(0),
	  artDisplayed(0),
	  boundariesDisplayed(0),
	  linesDisplayed(0),
	  namesDisplayed(0),
	  constellationLineThickness(1.f)
{
	setObjectName("ConstellationMgr");
	Q_ASSERT(hipStarMgr);
	isolateSelected = false;
	asterFont.setPixelSize(15);
}

ConstellationMgr::~ConstellationMgr()
{
	std::vector<Constellation *>::iterator iter;

	for (iter = asterisms.begin(); iter != asterisms.end(); iter++)
	{
		delete(*iter);
	}

	vector<vector<Vec3f> *>::iterator iter1;
	for (iter1 = allBoundarySegments.begin(); iter1 != allBoundarySegments.end(); ++iter1)
	{
		delete (*iter1);
	}
	allBoundarySegments.clear();
}

void ConstellationMgr::init()
{
	QSettings* conf = StelApp::getInstance().getSettings();
	Q_ASSERT(conf);

	lastLoadedSkyCulture = "dummy";
	asterFont.setPixelSize(conf->value("viewing/constellation_font_size", 14).toInt());
	setFlagLines(conf->value("viewing/flag_constellation_drawing").toBool());
	setFlagLabels(conf->value("viewing/flag_constellation_name").toBool());
	setFlagBoundaries(conf->value("viewing/flag_constellation_boundaries",false).toBool());
	setArtIntensity(conf->value("viewing/constellation_art_intensity", 0.5f).toFloat());
	setArtFadeDuration(conf->value("viewing/constellation_art_fade_duration",2.f).toFloat());
	setFlagArt(conf->value("viewing/flag_constellation_art").toBool());
	setFlagIsolateSelected(conf->value("viewing/flag_constellation_isolate_selected",
					   conf->value("viewing/flag_constellation_pick", false).toBool() ).toBool());
	setConstellationLineThickness(conf->value("viewing/constellation_line_thickness", 1.f).toFloat());

	StelObjectMgr *objectManager = GETSTELMODULE(StelObjectMgr);
	objectManager->registerStelObjectMgr(this);
	connect(objectManager, SIGNAL(selectedObjectChanged(StelModule::StelModuleSelectAction)), 
			this, SLOT(selectedObjectChange(StelModule::StelModuleSelectAction)));
	StelApp *app = &StelApp::getInstance();
	connect(app, SIGNAL(languageChanged()), this, SLOT(updateI18n()));
	connect(app, SIGNAL(skyCultureChanged(const QString&)), this, SLOT(updateSkyCulture(const QString&)));
	connect(app, SIGNAL(colorSchemeChanged(const QString&)), this, SLOT(setStelStyle(const QString&)));

	QString displayGroup = N_("Display Options");
	addAction("actionShow_Constellation_Lines", displayGroup, N_("Constellation lines"), "linesDisplayed", "C");
	addAction("actionShow_Constellation_Art", displayGroup, N_("Constellation art"), "artDisplayed", "R");
	addAction("actionShow_Constellation_Labels", displayGroup, N_("Constellation labels"), "namesDisplayed", "V");
	addAction("actionShow_Constellation_Boundaries", displayGroup, N_("Constellation boundaries"), "boundariesDisplayed", "B");
}

/*************************************************************************
 Reimplementation of the getCallOrder method
*************************************************************************/
double ConstellationMgr::getCallOrder(StelModuleActionName actionName) const
{
	if (actionName==StelModule::ActionDraw)
		return StelApp::getInstance().getModuleMgr().getModule("GridLinesMgr")->getCallOrder(actionName)+10;
	return 0;
}

void ConstellationMgr::updateSkyCulture(const QString& skyCultureDir)
{
	// Check if the sky culture changed since last load, if not don't load anything
	if (lastLoadedSkyCulture == skyCultureDir)
		return;

	// Find constellation art.  If this doesn't exist, warn, but continue using ""
	// the loadLinesAndArt function knows how to handle this (just loads lines).
	QString conArtFile = StelFileMgr::findFile("skycultures/"+skyCultureDir+"/constellationsart.fab");
	if (conArtFile.isEmpty())
	{
		qDebug() << "No constellationsart.fab file found for sky culture " << QDir::toNativeSeparators(skyCultureDir);
	}

	// first of all, remove constellations from the list of selected objects in StelObjectMgr, since we are going to delete them
	deselectConstellations();

	QString fic = StelFileMgr::findFile("skycultures/"+skyCultureDir+"/constellationship.fab");
	if (fic.isEmpty())
		qWarning() << "ERROR loading constellation lines and art from file: " << fic;
	else
		loadLinesAndArt(fic, conArtFile, skyCultureDir);

	// load constellation names
	fic = StelFileMgr::findFile("skycultures/" + skyCultureDir + "/constellation_names.eng.fab");
	if (fic.isEmpty())
		qWarning() << "ERROR loading constellation names from file: " << fic;
	else
		loadNames(fic);

	// Translate constellation names for the new sky culture
	updateI18n();

	// load constellation boundaries
	fic = StelFileMgr::findFile("skycultures/" + skyCultureDir + "/constellations_boundaries.dat");
	if (fic.isEmpty())
		qWarning() << "ERROR loading constellation boundaries file: " << fic;
	else
		loadBoundaries(fic);

	lastLoadedSkyCulture = skyCultureDir;
}

void ConstellationMgr::setStelStyle(const QString& section)
{
	QSettings* conf = StelApp::getInstance().getSettings();

	// Load colors from config file
	QString defaultColor = conf->value(section+"/default_color").toString();
	setLinesColor(StelUtils::strToVec3f(conf->value(section+"/const_lines_color", defaultColor).toString()));
	setBoundariesColor(StelUtils::strToVec3f(conf->value(section+"/const_boundary_color", "0.8,0.3,0.3").toString()));
	setLabelsColor(StelUtils::strToVec3f(conf->value(section+"/const_names_color", defaultColor).toString()));
}

void ConstellationMgr::selectedObjectChange(StelModule::StelModuleSelectAction action)
{
	StelObjectMgr* omgr = GETSTELMODULE(StelObjectMgr);
	Q_ASSERT(omgr);
	const QList<StelObjectP> newSelected = omgr->getSelectedObject();
	if (newSelected.empty())
	{
		// Even if do not have anything selected, KEEP constellation selection intact
		// (allows viewing constellations without distraction from star pointer animation)
		// setSelected(NULL);
		return;
	}

	const QList<StelObjectP> newSelectedConst = omgr->getSelectedObject("Constellation");
	if (!newSelectedConst.empty())
	{
		// If removing this selection
		if(action == StelModule::RemoveFromSelection)
		{
			unsetSelectedConst((Constellation *)newSelectedConst[0].data());
		}
		else
		{
			// Add constellation to selected list (do not select a star, just the constellation)
			setSelectedConst((Constellation *)newSelectedConst[0].data());
		}
	}
	else
	{
		const QList<StelObjectP> newSelectedStar = omgr->getSelectedObject("Star");
		if (!newSelectedStar.empty())
		{
//			if (!added)
//				setSelected(NULL);
			setSelected(newSelectedStar[0].data());
		}
		else
		{
//			if (!added)
				setSelected(NULL);
		}
	}
}

void ConstellationMgr::deselectConstellations(void)
{
	selected.clear();
	StelObjectMgr* omgr = GETSTELMODULE(StelObjectMgr);
	Q_ASSERT(omgr);
	const QList<StelObjectP> currSelection = omgr->getSelectedObject();
	if (currSelection.empty())
	{
		return;
	}

	QList<StelObjectP> newSelection;
	foreach(const StelObjectP& obj, currSelection)
	{
		if (obj->getType() != "Constellation")
		{
			newSelection.push_back(obj);
		}
	}
	omgr->setSelectedObject(newSelection, StelModule::ReplaceSelection);
}

void ConstellationMgr::setLinesColor(const Vec3f& color)
{
	if (color != Constellation::lineColor)
	{
		Constellation::lineColor = color;
		emit linesColorChanged(color);
	}
}

Vec3f ConstellationMgr::getLinesColor() const
{
	return Constellation::lineColor;
}

void ConstellationMgr::setBoundariesColor(const Vec3f& color)
{
	if (Constellation::boundaryColor != color)
	{
		Constellation::boundaryColor = color;
		emit boundariesColorChanged(color);
	}
}

Vec3f ConstellationMgr::getBoundariesColor() const
{
	return Constellation::boundaryColor;
}

void ConstellationMgr::setLabelsColor(const Vec3f& color)
{
	if (Constellation::labelColor != color)
	{
		Constellation::labelColor = color;
		emit namesColorChanged(color);
	}
}

Vec3f ConstellationMgr::getLabelsColor() const
{
	return Constellation::labelColor;
}

void ConstellationMgr::setFontSize(const float newFontSize)
{
	if (asterFont.pixelSize() != newFontSize)
	{
		asterFont.setPixelSize(newFontSize);
		emit fontSizeChanged(newFontSize);
	}
}

float ConstellationMgr::getFontSize() const
{
	return asterFont.pixelSize();
}

void ConstellationMgr::setConstellationLineThickness(const double thickness)
{
	constellationLineThickness = thickness;
	if (constellationLineThickness<=0.f) // The line can not be negative or zero thickness
		constellationLineThickness = 1.f;
}

void ConstellationMgr::loadLinesAndArt(const QString &fileName, const QString &artfileName, const QString& cultureName)
{
	QFile in(fileName);
	if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qWarning() << "Can't open constellation data file" << QDir::toNativeSeparators(fileName)  << "for culture" << cultureName;
		Q_ASSERT(0);
	}

	int totalRecords=0;
	QString record;
	QRegExp commentRx("^(\\s*#.*|\\s*)$");
	while (!in.atEnd())
	{
		record = QString::fromUtf8(in.readLine());
		if (!commentRx.exactMatch(record))
			totalRecords++;
	}
	in.seek(0);

	// delete existing data, if any
	vector < Constellation * >::iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
		delete(*iter);

	asterisms.clear();
	Constellation *cons = NULL;

	// read the file, adding a record per non-comment line
	int currentLineNumber = 0;	// line in file
	int readOk = 0;			// count of records processed OK
	while (!in.atEnd())
	{
		record = QString::fromUtf8(in.readLine());
		currentLineNumber++;
		if (commentRx.exactMatch(record))
			continue;

		cons = new Constellation;
		if(cons->read(record, hipStarMgr))
		{
			cons->artFader.setMaxValue(artIntensity);
			cons->setFlagArt(artDisplayed);
			cons->setFlagBoundaries(boundariesDisplayed);
			cons->setFlagLines(linesDisplayed);
			cons->setFlagLabels(namesDisplayed);
			asterisms.push_back(cons);
			++readOk;
		}
		else
		{
			qWarning() << "ERROR reading constellation rec at line " << currentLineNumber << "for culture" << cultureName;
			delete cons;
		}
	}
	in.close();
	qDebug() << "Loaded" << readOk << "/" << totalRecords << "constellation records successfully for culture" << cultureName;

	// Set current states
	setFlagArt(artDisplayed);
	setFlagLines(linesDisplayed);
	setFlagLabels(namesDisplayed);
	setFlagBoundaries(boundariesDisplayed);

	// It's possible to have no art - just constellations
	if (artfileName.isNull() || artfileName.isEmpty())
		return;
	QFile fic(artfileName);
	if (!fic.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qWarning() << "Can't open constellation art file" << QDir::toNativeSeparators(fileName)  << "for culture" << cultureName;
		return;
	}

	totalRecords=0;
	while (!fic.atEnd())
	{
		record = QString::fromUtf8(fic.readLine());
		if (!commentRx.exactMatch(record))
			totalRecords++;
	}
	fic.seek(0);

	// Read the constellation art file with the following format :
	// ShortName texture_file x1 y1 hp1 x2 y2 hp2
	// Where :
	// shortname is the international short name (i.e "Lep" for Lepus)
	// texture_file is the graphic file of the art texture
	// x1 y1 are the x and y texture coordinates in pixels of the star of hipparcos number hp1
	// x2 y2 are the x and y texture coordinates in pixels of the star of hipparcos number hp2
	// The coordinate are taken with (0,0) at the top left corner of the image file
	QString shortname;
	QString texfile;
	unsigned int x1, y1, x2, y2, x3, y3, hp1, hp2, hp3;
	QString tmpstr;

	currentLineNumber = 0;	// line in file
	readOk = 0;		// count of records processed OK

	while (!fic.atEnd())
	{
		++currentLineNumber;
		record = QString::fromUtf8(fic.readLine());
		if (commentRx.exactMatch(record))
			continue;

		// prevent leaving zeros on numbers from being interpretted as octal numbers
		record.replace(" 0", " ");
		QTextStream rStr(&record);
		rStr >> shortname >> texfile >> x1 >> y1 >> hp1 >> x2 >> y2 >> hp2 >> x3 >> y3 >> hp3;
		x1 /= CONSTELLATION_ART_SCALE;
		y1 /= CONSTELLATION_ART_SCALE;
		x2 /= CONSTELLATION_ART_SCALE;
		y2 /= CONSTELLATION_ART_SCALE;
		x3 /= CONSTELLATION_ART_SCALE;
		y3 /= CONSTELLATION_ART_SCALE;
		if (rStr.status()!=QTextStream::Ok)
		{
			qWarning() << "ERROR parsing constellation art record at line" << currentLineNumber << "of art file for culture" << cultureName;
			continue;
		}

		// Draw loading bar
// 		lb.SetMessage(q_("Loading Constellation Art: %1/%2").arg(currentLineNumber).arg(totalRecords));
// 		lb.Draw((float)(currentLineNumber)/totalRecords);

		cons = NULL;
		cons = findFromAbbreviation(shortname);
		if (!cons)
		{
			qWarning() << "ERROR in constellation art file at line" << currentLineNumber << "for culture" << cultureName
					   << "constellation" << shortname << "unknown";
		}
		else
		{
			QString texturePath = StelFileMgr::findFile("skycultures/"+cultureName+"/"+texfile);
			if (texturePath.isEmpty())
			{
				qWarning() << "ERROR: could not find texture, " << QDir::toNativeSeparators(texfile);
			}

			cons->artTexture = StelApp::getInstance().getTextureManager().createTexture(texturePath);

			int texSizeX = 0, texSizeY = 0;
			if (cons->artTexture==NULL || !cons->artTexture->getDimensions(texSizeX, texSizeY))
			{
				qWarning() << "Texture dimension not available";
			}

			StelCore* core = StelApp::getInstance().getCore();
			Vec3d s1 = hipStarMgr->searchHP(hp1)->getJ2000EquatorialPos(core);
			Vec3d s2 = hipStarMgr->searchHP(hp2)->getJ2000EquatorialPos(core);
			Vec3d s3 = hipStarMgr->searchHP(hp3)->getJ2000EquatorialPos(core);

			// To transform from texture coordinate to 2d coordinate we need to find X with XA = B
			// A formed of 4 points in texture coordinate, B formed with 4 points in 3d coordinate
			// We need 3 stars and the 4th point is deduced from the other to get an normal base
			// X = B inv(A)
			Vec3d s4 = s1 + ((s2 - s1) ^ (s3 - s1));
			Mat4d B(s1[0], s1[1], s1[2], 1, s2[0], s2[1], s2[2], 1, s3[0], s3[1], s3[2], 1, s4[0], s4[1], s4[2], 1);
			Mat4d A(x1, texSizeY - y1, 0.f, 1.f, x2, texSizeY - y2, 0.f, 1.f, x3, texSizeY - y3, 0.f, 1.f, x1, texSizeY - y1, texSizeX, 1.f);
			Mat4d X = B * A.inverse();

			// Tesselate on the plan assuming a tangential projection for the image
			static const int nbPoints=5;
			QVector<Vec2f> texCoords;
			texCoords.reserve(nbPoints*nbPoints*6);
			for (int j=0;j<nbPoints;++j)
			{
				for (int i=0;i<nbPoints;++i)
				{
					texCoords << Vec2f(((float)i)/nbPoints, ((float)j)/nbPoints);
					texCoords << Vec2f(((float)i+1.f)/nbPoints, ((float)j)/nbPoints);
					texCoords << Vec2f(((float)i)/nbPoints, ((float)j+1.f)/nbPoints);
					texCoords << Vec2f(((float)i+1.f)/nbPoints, ((float)j)/nbPoints);
					texCoords << Vec2f(((float)i+1.f)/nbPoints, ((float)j+1.f)/nbPoints);
					texCoords << Vec2f(((float)i)/nbPoints, ((float)j+1.f)/nbPoints);
				}
			}

			QVector<Vec3d> contour;
			contour.reserve(texCoords.size());
			foreach (const Vec2f& v, texCoords)
				contour << X * Vec3d(v[0]*texSizeX, v[1]*texSizeY, 0.);

			cons->artPolygon.vertex=contour;
			cons->artPolygon.texCoords=texCoords;
			cons->artPolygon.primitiveType=StelVertexArray::Triangles;

			Vec3d tmp(X * Vec3d(0.5*texSizeX, 0.5*texSizeY, 0.));
			tmp.normalize();
			Vec3d tmp2(X * Vec3d(0., 0., 0.));
			tmp2.normalize();
			cons->boundingCap.n=tmp;
			cons->boundingCap.d=tmp*tmp2;
			++readOk;
		}
	}

	qDebug() << "Loaded" << readOk << "/" << totalRecords << "constellation art records successfully for culture" << cultureName;
	fic.close();
}

void ConstellationMgr::draw(StelCore* core)
{
	const StelProjectorP prj = core->getProjection(StelCore::FrameJ2000);
	StelPainter sPainter(prj);
	sPainter.setFont(asterFont);
	drawLines(sPainter, core);
	drawNames(sPainter);
	drawArt(sPainter);
	drawBoundaries(sPainter);
}

// Draw constellations art textures
void ConstellationMgr::drawArt(StelPainter& sPainter) const
{
	glBlendFunc(GL_ONE, GL_ONE);
	sPainter.enableTexture2d(true);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);

	vector < Constellation * >::const_iterator iter;
	SphericalRegionP region = sPainter.getProjector()->getViewportConvexPolygon();
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->drawArtOptim(sPainter, *region);
	}

	glDisable(GL_CULL_FACE);
}

// Draw constellations lines
void ConstellationMgr::drawLines(StelPainter& sPainter, const StelCore* core) const
{
	sPainter.enableTexture2d(false);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if (constellationLineThickness>1.f)
		glLineWidth(constellationLineThickness); // set line thickness
	// OpenGL ES 2.0 doesn't have GL_LINE_SMOOTH. But it looks much better.
	#ifdef GL_LINE_SMOOTH
	if (QOpenGLContext::currentContext()->format().renderableType()==QSurfaceFormat::OpenGL)
		glEnable(GL_LINE_SMOOTH);
	#endif

	const SphericalCap& viewportHalfspace = sPainter.getProjector()->getBoundingCap();
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->drawOptim(sPainter, core, viewportHalfspace);
	}
	if (constellationLineThickness>1.f)
		glLineWidth(1.f); // restore line thickness
	// OpenGL ES 2.0 doesn't have GL_LINE_SMOOTH. But it looks much better.
	#ifdef GL_LINE_SMOOTH
	if (QOpenGLContext::currentContext()->format().renderableType()==QSurfaceFormat::OpenGL)
		glDisable(GL_LINE_SMOOTH);
	#endif
}

// Draw the names of all the constellations
void ConstellationMgr::drawNames(StelPainter& sPainter) const
{
	glEnable(GL_BLEND);
	sPainter.enableTexture2d(true);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); iter++)
	{
		// Check if in the field of view
		if (sPainter.getProjector()->projectCheck((*iter)->XYZname, (*iter)->XYname))
			(*iter)->drawName(sPainter);
	}
}

Constellation *ConstellationMgr::isStarIn(const StelObject* s) const
{
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		// Check if the star is in one of the constellation
		if ((*iter)->isStarIn(s))
		{
			return (*iter);
		}
	}
	return NULL;
}

Constellation* ConstellationMgr::findFromAbbreviation(const QString& abbreviation) const
{
	// search in uppercase only
	QString tname = abbreviation.toUpper();

	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		if ((*iter)->abbreviation == tname)
			return (*iter);
	}
	return NULL;
}

// Can't find constellation from a position because it's not well localized
QList<StelObjectP> ConstellationMgr::searchAround(const Vec3d&, double, const StelCore*) const
{
	return QList<StelObjectP>();
}

void ConstellationMgr::loadNames(const QString& namesFile)
{
	// Constellation not loaded yet
	if (asterisms.empty()) return;

	// clear previous names
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->englishName.clear();
	}

	// Open file
	QFile commonNameFile(namesFile);
	if (!commonNameFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Cannot open file" << QDir::toNativeSeparators(namesFile);
		return;
	}

	// Now parse the file
	// lines to ignore which start with a # or are empty
	QRegExp commentRx("^(\\s*#.*|\\s*)$");

	// lines which look like records - we use the RE to extract the fields
	// which will be available in recRx.capturedTexts()
	QRegExp recRx("^\\s*(\\w+)\\s+\"(.*)\"\\s+_[(]\"(.*)\"[)]\\n");

	// Some more variables to use in the parsing
	Constellation *aster;
	QString record, shortName;

	// keep track of how many records we processed.
	int totalRecords=0;
	int readOk=0;
	int lineNumber=0;
	while (!commonNameFile.atEnd())
	{
		record = QString::fromUtf8(commonNameFile.readLine());
		lineNumber++;

		// Skip comments
		if (commentRx.exactMatch(record))
			continue;

		totalRecords++;

		if (!recRx.exactMatch(record))
		{
			qWarning() << "ERROR - cannot parse record at line" << lineNumber << "in constellation names file" << QDir::toNativeSeparators(namesFile);
		}
		else
		{
			shortName = recRx.capturedTexts().at(1);
			aster = findFromAbbreviation(shortName);
			// If the constellation exists, set the English name
			if (aster != NULL)
			{
				aster->nativeName = recRx.capturedTexts().at(2);
				aster->englishName = recRx.capturedTexts().at(3);
				readOk++;
			}
			else
			{
				qWarning() << "WARNING - constellation abbreviation" << shortName << "not found when loading constellation names";
			}
		}
	}
	commonNameFile.close();
	qDebug() << "Loaded" << readOk << "/" << totalRecords << "constellation names";
}

void ConstellationMgr::updateI18n()
{
	const StelTranslator& trans = StelApp::getInstance().getLocaleMgr().getSkyTranslator();
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->nameI18 = trans.qtranslate((*iter)->englishName);
	}
}

// update faders
void ConstellationMgr::update(double deltaTime)
{
	vector < Constellation * >::const_iterator iter;
	const int delta = (int)(deltaTime*1000);
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->update(delta);
	}
}

void ConstellationMgr::setArtIntensity(const double intensity)
{
	if (artIntensity != intensity)
		artIntensity = intensity;

	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->artFader.setMaxValue(artIntensity);
	}
	emit artIntensityChanged(intensity);
}

double ConstellationMgr::getArtIntensity() const
{
	return artIntensity;
}

void ConstellationMgr::setArtFadeDuration(const float duration)
{
	if (artFadeDuration != duration)
		artFadeDuration = duration;

	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->artFader.setDuration((int) (duration * 1000.f));
	}
	emit artFadeDurationChanged(duration);
}

float ConstellationMgr::getArtFadeDuration() const
{
	return artFadeDuration;
}

void ConstellationMgr::setFlagLines(const bool displayed)
{
	if(linesDisplayed != displayed)
	{
		linesDisplayed = displayed;
		if (selected.begin() != selected.end()  && isolateSelected)
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = selected.begin(); iter != selected.end(); ++iter)
			{
				(*iter)->setFlagLines(linesDisplayed);
			}
		}
		else
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
			{
				(*iter)->setFlagLines(linesDisplayed);
			}
		}
		emit linesDisplayedChanged(displayed);
	}
}

bool ConstellationMgr::getFlagLines(void) const
{
	return linesDisplayed;
}

void ConstellationMgr::setFlagBoundaries(const bool displayed)
{
	if (boundariesDisplayed != displayed)
	{
		boundariesDisplayed = displayed;
		if (selected.begin() != selected.end() && isolateSelected)
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = selected.begin(); iter != selected.end(); ++iter)
			{
				(*iter)->setFlagBoundaries(boundariesDisplayed);
			}
		}
		else
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
			{
				(*iter)->setFlagBoundaries(boundariesDisplayed);
			}
		}
		emit boundariesDisplayedChanged(displayed);
	}
}

bool ConstellationMgr::getFlagBoundaries(void) const
{
	return boundariesDisplayed;
}

void ConstellationMgr::setFlagArt(const bool displayed)
{
	if (artDisplayed != displayed)
	{
		artDisplayed = displayed;
		if (selected.begin() != selected.end() && isolateSelected)
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = selected.begin(); iter != selected.end(); ++iter)
			{
				(*iter)->setFlagArt(artDisplayed);
			}
		}
		else
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
			{
				(*iter)->setFlagArt(artDisplayed);
			}
		}
		emit artDisplayedChanged(displayed);
	}
}

bool ConstellationMgr::getFlagArt(void) const
{
	return artDisplayed;
}

void ConstellationMgr::setFlagLabels(bool displayed)
{
	if (namesDisplayed != displayed)
	{
		namesDisplayed = displayed;
		if (selected.begin() != selected.end() && isolateSelected)
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = selected.begin(); iter != selected.end(); ++iter)
				(*iter)->setFlagLabels(namesDisplayed);
		}
		else
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
				(*iter)->setFlagLabels(namesDisplayed);
		}
		emit namesDisplayedChanged(displayed);
	}
}

bool ConstellationMgr::getFlagLabels(void) const
{
	return namesDisplayed;
}

void ConstellationMgr::setFlagIsolateSelected(const bool isolate)
{
	if (isolateSelected != isolate)
	{
		isolateSelected = isolate;

		// when turning off isolated selection mode, clear exisiting isolated selections.
		if (!isolateSelected)
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
			{
				(*iter)->setFlagLines(getFlagLines());
				(*iter)->setFlagLabels(getFlagLabels());
				(*iter)->setFlagArt(getFlagArt());
				(*iter)->setFlagBoundaries(getFlagBoundaries());
			}
		}
		emit isolateSelectedChanged(isolate);
	}
}

bool ConstellationMgr::getFlagIsolateSelected(void) const
{
	return isolateSelected;
}

StelObject* ConstellationMgr::getSelected(void) const {
	return *selected.begin();  // TODO return all or just remove this method
}

void ConstellationMgr::setSelected(const QString& abbreviation)
{
	Constellation * c = findFromAbbreviation(abbreviation);
	if(c != NULL) setSelectedConst(c);
}

StelObjectP ConstellationMgr::setSelectedStar(const QString& abbreviation)
{
	Constellation * c = findFromAbbreviation(abbreviation);
	if(c != NULL)
	{
		setSelectedConst(c);
		return c->getBrightestStarInConstellation();
	}
	return NULL;
}

void ConstellationMgr::setSelectedConst(Constellation * c)
{
	// update states for other constellations to fade them out
	if (c != NULL)
	{
		selected.push_back(c);

		// Propagate current settings to newly selected constellation
		c->setFlagLines(getFlagLines());
		c->setFlagLabels(getFlagLabels());
		c->setFlagArt(getFlagArt());
		c->setFlagBoundaries(getFlagBoundaries());

		if (isolateSelected)
		{
			vector < Constellation * >::const_iterator iter;
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
			{

				bool match = 0;
				vector < Constellation * >::const_iterator s_iter;
				for (s_iter = selected.begin(); s_iter != selected.end(); ++s_iter)
				{
					if( (*iter)==(*s_iter) )
					{
						match=true; // this is a selected constellation
						break;
					}
				}

				if(!match)
				{
					// Not selected constellation
					(*iter)->setFlagLines(false);
					(*iter)->setFlagLabels(false);
					(*iter)->setFlagArt(false);
					(*iter)->setFlagBoundaries(false);
					}
					}
			Constellation::singleSelected = true;  // For boundaries
			}
		else
			Constellation::singleSelected = false; // For boundaries
	}
	else
	{
		if (selected.begin() == selected.end()) return;

		// Otherwise apply standard flags to all constellations
		vector < Constellation * >::const_iterator iter;
		for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
		{
			(*iter)->setFlagLines(getFlagLines());
			(*iter)->setFlagLabels(getFlagLabels());
			(*iter)->setFlagArt(getFlagArt());
			(*iter)->setFlagBoundaries(getFlagBoundaries());
		}

		// And remove all selections
		selected.clear();


	}
}

//! Remove a constellation from the selected constellation list
void ConstellationMgr::unsetSelectedConst(Constellation * c)
{
	if (c != NULL)
	{

		vector < Constellation * >::const_iterator iter;
		int n=0;
		for (iter = selected.begin(); iter != selected.end(); ++iter)
		{
			if( (*iter)->getEnglishName() == c->getEnglishName() )
			{
				selected.erase(selected.begin()+n, selected.begin()+n+1);
				iter--;
				n--;
			}
			n++;
		}

		// If no longer any selection, restore all flags on all constellations
		if (selected.begin() == selected.end())
		{

			// Otherwise apply standard flags to all constellations
			for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
			{
				(*iter)->setFlagLines(getFlagLines());
				(*iter)->setFlagLabels(getFlagLabels());
				(*iter)->setFlagArt(getFlagArt());
				(*iter)->setFlagBoundaries(getFlagBoundaries());
			}

			Constellation::singleSelected = false; // For boundaries

		}
		else if(isolateSelected)
		{

			// No longer selected constellation
			c->setFlagLines(false);
			c->setFlagLabels(false);
			c->setFlagArt(false);
			c->setFlagBoundaries(false);

			Constellation::singleSelected = true;  // For boundaries
		}
	}
}

bool ConstellationMgr::loadBoundaries(const QString& boundaryFile)
{
	Constellation *cons = NULL;
	unsigned int i, j;

	// delete existing boundaries if any exist
	vector<vector<Vec3f> *>::iterator iter;
	for (iter = allBoundarySegments.begin(); iter != allBoundarySegments.end(); ++iter)
	{
		delete (*iter);
	}
	allBoundarySegments.clear();

	qDebug() << "Loading constellation boundary data ... ";

	// Modified boundary file by Torsten Bronger with permission
	// http://pp3.sourceforge.net
	QFile dataFile(boundaryFile);
	if (!dataFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qWarning() << "Boundary file " << QDir::toNativeSeparators(boundaryFile) << " not found";
		return false;
	}

	QTextStream istr(&dataFile);
	float DE, RA;
	Vec3f XYZ;
	unsigned num, numc;
	vector<Vec3f> *points = NULL;
	QString consname;
	i = 0;
	while (!istr.atEnd())
	{
		points = new vector<Vec3f>;

		num = 0;
		istr >> num;
		if(num == 0) continue;  // empty line

		for (j=0;j<num;j++)
		{
			istr >> RA >> DE;

			RA*=M_PI/12.;     // Convert from hours to rad
			DE*=M_PI/180.;    // Convert from deg to rad

			// Calc the Cartesian coord with RA and DE
			StelUtils::spheToRect(RA,DE,XYZ);
			points->push_back(XYZ);
		}

		// this list is for the de-allocation
		allBoundarySegments.push_back(points);

		istr >> numc;
		// there are 2 constellations per boundary

		for (j=0;j<numc;j++)
		{
			istr >> consname;
			// not used?
			if (consname == "SER1" || consname == "SER2") consname = "SER";

			cons = findFromAbbreviation(consname);
			if (!cons)
				qWarning() << "ERROR while processing boundary file - cannot find constellation: " << consname;
			else
				cons->isolatedBoundarySegments.push_back(points);
		}

		if (cons) cons->sharedBoundarySegments.push_back(points);
		i++;

	}
	dataFile.close();
	qDebug() << "Loaded" << i << "constellation boundary segments";
	delete points;

	return true;
}

void ConstellationMgr::drawBoundaries(StelPainter& sPainter) const
{
	sPainter.enableTexture2d(false);
	glDisable(GL_BLEND);
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		(*iter)->drawBoundaryOptim(sPainter);
	}
}

StelObjectP ConstellationMgr::searchByNameI18n(const QString& nameI18n) const
{
	QString objw = nameI18n.toUpper();

	vector <Constellation*>::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		QString objwcap = (*iter)->nameI18.toUpper();
		if (objwcap==objw) return *iter;
	}
	return NULL;
}

StelObjectP ConstellationMgr::searchByName(const QString& name) const
{
	QString objw = name.toUpper();
	vector <Constellation*>::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		QString objwcap = (*iter)->englishName.toUpper();
		if (objwcap==objw) return *iter;

		objwcap = (*iter)->abbreviation.toUpper();
		if (objwcap==objw) return *iter;
	}
	return NULL;
}

QStringList ConstellationMgr::listMatchingObjectsI18n(const QString& objPrefix, int maxNbItem, bool useStartOfWords) const
{
	QStringList result;
	if (maxNbItem==0) return result;

	QString cn;
	bool find;
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		cn = (*iter)->getNameI18n();
		find = false;
		if (useStartOfWords)
		{
			if (objPrefix.toUpper()==cn.mid(0, objPrefix.size()).toUpper())
				find = true;
		}
		else
		{
			if (cn.contains(objPrefix,Qt::CaseInsensitive))
				find = true;
		}
		if (find)
		{
			result << cn;
			if (result.size()==maxNbItem)
				return result;
		}
	}
	return result;
}

QStringList ConstellationMgr::listMatchingObjects(const QString& objPrefix, int maxNbItem, bool useStartOfWords) const
{
	QStringList result;
	if (maxNbItem==0) return result;

	QString cn;
	bool find;
	vector < Constellation * >::const_iterator iter;
	for (iter = asterisms.begin(); iter != asterisms.end(); ++iter)
	{
		cn = (*iter)->getEnglishName();
		find = false;
		if (useStartOfWords)
		{
			if (objPrefix.toUpper()==cn.mid(0, objPrefix.size()).toUpper())
				find = true;
		}
		else
		{
			if (cn.contains(objPrefix,Qt::CaseInsensitive))
				find = true;
		}
		if (find)
		{
			result << cn;
			if (result.size()==maxNbItem)
				return result;
		}
	}
	return result;
}

QStringList ConstellationMgr::listAllObjects(bool inEnglish) const
{
	QStringList result;
	if (inEnglish)
	{
		foreach(Constellation* constellation, asterisms)
		{
			result << constellation->getEnglishName();
		}
	}
	else
	{
		foreach(Constellation* constellation, asterisms)
		{
			result << constellation->getNameI18n();
		}
	}
	return result;
}
