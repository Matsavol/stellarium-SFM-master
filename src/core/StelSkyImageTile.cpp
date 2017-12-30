/*
 * Copyright (C) 2008 Fabien Chereau
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

#include "StelTextureMgr.hpp"
#include "StelSkyImageTile.hpp"
#include "StelApp.hpp"
#include "StelFileMgr.hpp"
#include "StelUtils.hpp"
#include "StelTexture.hpp"
#include "StelProjector.hpp"
#include "StelToneReproducer.hpp"
#include "StelCore.hpp"
#include "StelSkyDrawer.hpp"
#include "StelPainter.hpp"

#include <QDebug>

#include <stdio.h>

StelSkyImageTile::StelSkyImageTile()
{
	initCtor();
}

void StelSkyImageTile::initCtor()
{
	minResolution = -1;
	luminance = -1;
	alphaBlend = false;
	noTexture = false;
	texFader = NULL;
}

// Constructor
StelSkyImageTile::StelSkyImageTile(const QString& url, StelSkyImageTile* parent) : MultiLevelJsonBase(parent)
{
	initCtor();
	if (parent!=NULL)
	{
		luminance = parent->luminance;
		alphaBlend = parent->alphaBlend;
	}
	initFromUrl(url);
}

// Constructor from a map used for JSON files with more than 1 level
StelSkyImageTile::StelSkyImageTile(const QVariantMap& map, StelSkyImageTile* parent) : MultiLevelJsonBase(parent)
{
	initCtor();
	if (parent!=NULL)
	{
		luminance = parent->luminance;
		alphaBlend = parent->alphaBlend;
	}
	initFromQVariantMap(map);
}

// Destructor
StelSkyImageTile::~StelSkyImageTile()
{
}

void StelSkyImageTile::draw(StelCore* core, StelPainter& sPainter, float)
{
	const StelProjectorP prj = core->getProjection(StelCore::FrameJ2000);

	const float limitLuminance = core->getSkyDrawer()->getLimitLuminance();
	QMultiMap<double, StelSkyImageTile*> result;
	getTilesToDraw(result, core, prj->getViewportConvexPolygon(0, 0), limitLuminance, true);

	int numToBeLoaded=0;
	foreach (StelSkyImageTile* t, result)
		if (t->isReadyToDisplay()==false)
			++numToBeLoaded;
	updatePercent(result.size(), numToBeLoaded);

	// Draw in the good order
	sPainter.enableTexture2d(true);
	glBlendFunc(GL_ONE, GL_ONE);
	QMap<double, StelSkyImageTile*>::Iterator i = result.end();
	while (i!=result.begin())
	{
		--i;
		i.value()->drawTile(core, sPainter);
	}

	deleteUnusedSubTiles();
}

// Return the list of tiles which should be drawn.
void StelSkyImageTile::getTilesToDraw(QMultiMap<double, StelSkyImageTile*>& result, StelCore* core, const SphericalRegionP& viewPortPoly, float limitLuminance, bool recheckIntersect)
{

#ifndef NDEBUG
	// When this method is called, we can assume that:
	// - the parent tile min resolution was reached
	// - the parent tile is intersecting FOV
	// - the parent tile is not scheduled for deletion
	const StelSkyImageTile* parent = qobject_cast<StelSkyImageTile*>(QObject::parent());
	if (parent!=NULL)
	{
		Q_ASSERT(isDeletionScheduled()==false);
		const double degPerPixel = 1./core->getProjection(StelCore::FrameJ2000)->getPixelPerRadAtCenter()*180./M_PI;
		Q_ASSERT(degPerPixel<parent->minResolution);

		Q_ASSERT(parent->isDeletionScheduled()==false);
	}
#endif

	// An error occured during loading
	if (errorOccured)
		return;

	// The JSON file is currently being downloaded
	if (downloading)
	{
		//qDebug() << "Downloading " << contructorUrl;
		return;
	}

	if (luminance>0 && luminance<limitLuminance)
	{
		// Schedule a deletion
		scheduleChildsDeletion();
		return;
	}

	// Check that we are in the screen
	bool fullInScreen = true;
	bool intersectScreen = false;
	if (recheckIntersect)
	{
		if (skyConvexPolygons.isEmpty())
		{
			// If no polygon is defined, we assume that the tile covers the whole sky
			fullInScreen=false;
			intersectScreen=true;
		}
		else
		{
			foreach (const SphericalRegionP& poly, skyConvexPolygons)
			{
				if (viewPortPoly->contains(poly))
				{
					intersectScreen = true;
				}
				else
				{
					fullInScreen = false;
					if (viewPortPoly->intersects(poly))
						intersectScreen = true;
				}
			}
		}
	}
	// The tile is outside screen
	if (fullInScreen==false && intersectScreen==false)
	{
		// Schedule a deletion
		scheduleChildsDeletion();
		return;
	}

	// The tile is in screen, and it is a precondition that its resolution is higher than the limit
	// make sure that it's not going to be deleted
	cancelDeletion();

	if (noTexture==false)
	{
		if (!tex)
		{
			// The tile has an associated texture, but it is not yet loaded: load it now
			StelTextureMgr& texMgr=StelApp::getInstance().getTextureManager();
			tex = texMgr.createTextureThread(absoluteImageURI, StelTexture::StelTextureParams(true));
			if (!tex)
			{
				qWarning() << "WARNING : Can't create tile: " << absoluteImageURI;
				errorOccured = true;
				return;
			}
		}

		// The tile is in screen and has a texture: every test passed :) The tile will be displayed
		result.insert(minResolution, this);
	}

	// Check if we reach the resolution limit
	const double degPerPixel = 1./core->getProjection(StelCore::FrameJ2000)->getPixelPerRadAtCenter()*180./M_PI;
	if (degPerPixel < minResolution)
	{
		if (subTiles.isEmpty() && !subTilesUrls.isEmpty())
		{
			// Load the sub tiles because we reached the maximum resolution and they are not yet loaded
			foreach (QVariant s, subTilesUrls)
			{
				StelSkyImageTile* nt;
				if (s.type()==QVariant::Map)
					nt = new StelSkyImageTile(s.toMap(), this);
				else
				{
					Q_ASSERT(s.type()==QVariant::String);
					nt = new StelSkyImageTile(s.toString(), this);
				}
				subTiles.append(nt);
			}
		}
		// Try to add the subtiles
		foreach (MultiLevelJsonBase* tile, subTiles)
		{
			qobject_cast<StelSkyImageTile*>(tile)->getTilesToDraw(result, core, viewPortPoly, limitLuminance, !fullInScreen);
		}
	}
	else
	{
		// The subtiles should not be displayed because their resolution is too high
		scheduleChildsDeletion();
	}
}

// Draw the image on the screen.
// Assume GL_TEXTURE_2D is enabled
bool StelSkyImageTile::drawTile(StelCore* core, StelPainter& sPainter)
{
	if (!tex->bind())
		return false;

	if (!texFader)
	{
		texFader = new QTimeLine(1000, this);
		texFader->start();
	}

	// Draw the real texture for this image
	float ad_lum = (luminance>0) ? core->getToneReproducer()->adaptLuminanceScaled(luminance) : 1.f;
	ad_lum=std::min(1.f, ad_lum);
	Vec4f color;
	if (alphaBlend==true || texFader->state()==QTimeLine::Running)
	{
		if (!alphaBlend)
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Normal transparency mode
		else
			glBlendFunc(GL_ONE, GL_ONE);
		glEnable(GL_BLEND);
		color.set(ad_lum,ad_lum,ad_lum, texFader->currentValue());
	}
	else
	{
		glDisable(GL_BLEND);
		color.set(ad_lum,ad_lum,ad_lum, 1.f);
	}

	const bool withExtinction=(core->getSkyDrawer()->getFlagHasAtmosphere() && core->getSkyDrawer()->getExtinction().getExtinctionCoefficient()>=0.01f);
	
	sPainter.enableTexture2d(true);
	foreach (const SphericalRegionP& poly, skyConvexPolygons)
	{
		Vec4f extinctedColor = color;
		if (withExtinction)
		{
			Vec3d bary= poly->getPointInside(); // This is a J000.0 vector that points "somewhere" in the first triangle.
			Vec3d altAz = core->j2000ToAltAz(bary, StelCore::RefractionOff);
			float extinctionMagnitude=0.0f;
			altAz.normalize();
			core->getSkyDrawer()->getExtinction().forward(altAz, &extinctionMagnitude);
			// compute a simple factor from magnitude loss.
			float extinctionFactor=std::pow(0.4f , extinctionMagnitude); // drop of one magnitude: factor 2.5 or 40%
			extinctedColor[0]*=fabs(extinctionFactor);
			extinctedColor[1]*=fabs(extinctionFactor);
			extinctedColor[2]*=fabs(extinctionFactor);
		}
		sPainter.setColor(extinctedColor[0], extinctedColor[1], extinctedColor[2], extinctedColor[3]);
		sPainter.drawSphericalRegion(poly.data(), StelPainter::SphericalPolygonDrawModeTextureFill);
		
	}

#ifdef DEBUG_STELSKYIMAGE_TILE
	if (debugFont==NULL)
	{
		debugFont = &StelApp::getInstance().getFontManager().getStandardFont(StelApp::getInstance().getLocaleMgr().getSkyLanguage(), 12);
	}
	color.set(1.0,0.5,0.5,1.0);
	foreach (const SphericalRegionP& poly, skyConvexPolygons)
	{
		Vec3d win;
		Vec3d bary = poly->getPointInside();
		sPainter.getProjector()->project(bary,win);
		sPainter.drawText(debugFont, win[0], win[1], getAbsoluteImageURI());
		sPainter.enableTexture2d(false);
		sPainter.drawSphericalRegion(poly.get(), StelPainter::SphericalPolygonDrawModeBoundary, &color);
		sPainter.enableTexture2d(true);
	}
#endif

	return true;
}

// Return true if the tile is fully loaded and can be displayed
bool StelSkyImageTile::isReadyToDisplay() const
{
	return tex && tex->canBind();
}

// Load the tile from a valid QVariantMap
void StelSkyImageTile::loadFromQVariantMap(const QVariantMap& map)
{
	if (map.contains("imageCredits"))
	{
		QVariantMap dsCredits = map.value("imageCredits").toMap();
		dataSetCredits.shortCredits = dsCredits.value("short").toString();
		dataSetCredits.fullCredits = dsCredits.value("full").toString();
		dataSetCredits.infoURL = dsCredits.value("infoUrl").toString();
	}
	if (map.contains("serverCredits"))
	{
		QVariantMap sCredits = map.value("serverCredits").toMap();
		serverCredits.shortCredits = sCredits.value("short").toString();
		serverCredits.fullCredits = sCredits.value("full").toString();
		serverCredits.infoURL = sCredits.value("infoUrl").toString();
	}
	if (map.contains("description"))
	{
		htmlDescription = map.value("description").toString();
		if (parent()==NULL)
		{
			htmlDescription+= "<h3>URL: "+contructorUrl+"</h3>";
		}
	}
	else
	{
		if (parent()==NULL)
		{
			htmlDescription= "<h3>URL: "+contructorUrl+"</h3>";
		}
	}

	shortName = map.value("shortName").toString();
	if (shortName.isEmpty())
		shortName = "no name";
	bool ok=false;
	if (!map.contains("minResolution"))
		throw std::runtime_error(qPrintable(QString("minResolution is mandatory")));
	minResolution = map.value("minResolution").toFloat(&ok);
	if (!ok)
	{
		throw std::runtime_error(qPrintable(QString("minResolution expect a double value, found: \"%1\"").arg(map.value("minResolution").toString())));
	}

	if (map.contains("luminance"))
	{
		luminance = map.value("luminance").toFloat(&ok);
		if (!ok)
			throw std::runtime_error("luminance expect a float value");
		qWarning() << "luminance in preview JSON files is deprecated. Replace with maxBrightness.";
	}

	if (map.contains("maxBrightness"))
	{
		// maxBrightness is the maximum nebula brightness in Vmag/arcmin^2
		luminance = map.value("maxBrightness").toFloat(&ok);
		if (!ok)
			throw std::runtime_error("maxBrightness expect a float value");
		luminance = StelApp::getInstance().getCore()->getSkyDrawer()->surfacebrightnessToLuminance(luminance);
	}

	if (map.contains("alphaBlend"))
	{
		alphaBlend = map.value("alphaBlend").toBool();
	}

	// Load the convex polygons (if any)
	QVariantList polyList = map.value("skyConvexPolygons").toList();
	if (polyList.empty())
		polyList = map.value("worldCoords").toList();
	else
		qWarning() << "skyConvexPolygons in preview JSON files is deprecated. Replace with worldCoords.";

	// Load the matching textures positions (if any)
	QVariantList texCoordList = map.value("textureCoords").toList();
	if (!texCoordList.isEmpty() && polyList.size()!=texCoordList.size())
			throw std::runtime_error("the number of convex polygons does not match the number of texture space polygon");

	for (int i=0;i<polyList.size();++i)
	{
		const QVariant& polyRaDec = polyList.at(i);
		QVector<Vec3d> vertices;
		foreach (const QVariant& vRaDec, polyRaDec.toList())
		{
			const QVariantList vl = vRaDec.toList();
			Vec3d v;
			StelUtils::spheToRect(vl.at(0).toFloat(&ok)*M_PI/180.f, vl.at(1).toFloat(&ok)*M_PI/180.f, v);
			if (!ok)
				throw std::runtime_error("wrong Ra and Dec, expect a double value");
			vertices.append(v);
		}
		Q_ASSERT(vertices.size()==4);

		if (!texCoordList.isEmpty())
		{
			const QVariant& polyXY = texCoordList.at(i);
			QVector<Vec2f> texCoords;
			foreach (const QVariant& vXY, polyXY.toList())
			{
				const QVariantList vl = vXY.toList();
				texCoords.append(Vec2f(vl.at(0).toFloat(&ok), vl.at(1).toFloat(&ok)));
				if (!ok)
					throw std::runtime_error("wrong X and Y, expect a double value");
			}
			Q_ASSERT(texCoords.size()==4);

			SphericalTexturedConvexPolygon* pol = new SphericalTexturedConvexPolygon(vertices, texCoords);
			Q_ASSERT(pol->checkValid());
			skyConvexPolygons.append(SphericalRegionP(pol));
		}
		else
		{
			SphericalConvexPolygon* pol = new SphericalConvexPolygon(vertices);
			Q_ASSERT(pol->checkValid());
			skyConvexPolygons.append(SphericalRegionP(pol));
		}
	}

	if (map.contains("imageUrl"))
	{
		QString imageUrl = map.value("imageUrl").toString();
		if (baseUrl.startsWith("http://"))
		{
			absoluteImageURI = baseUrl+imageUrl;
		}
		else
		{
            absoluteImageURI = StelFileMgr::findFile(QString(INSTALL_DATADIR_NOSTR)+baseUrl+imageUrl); //restored back
			if (absoluteImageURI.isEmpty())
			{
				// Maybe the user meant a file in stellarium local files
                absoluteImageURI = imageUrl;
			}
		}
	}
	else
		noTexture = true;

	// This is a list of URLs to the child tiles or a list of already loaded map containing child information
	// (in this later case, the StelSkyImageTile objects will be created later)
	subTilesUrls = map.value("subTiles").toList();
	for (QVariantList::Iterator i=subTilesUrls.begin(); i!=subTilesUrls.end();++i)
	{
		if (i->type()==QVariant::Map)
		{
			// Check if the JSON object is a reference, i.e. if it contains a $ref key
			QVariantMap m = i->toMap();
			if (m.size()==1 && m.contains("$ref"))
			{
				*i=QString(m["$ref"].toString());
			}
		}
	}
// 	if (subTilesUrls.size()>10)
// 	{
// 		qWarning() << "Large tiles number for " << shortName << ": " << subTilesUrls.size();
// 	}
}

// Convert the image informations to a map following the JSON structure.
QVariantMap StelSkyImageTile::toQVariantMap() const
{
	QVariantMap res;

	// Image credits
	QVariantMap imCredits;
	if (!dataSetCredits.shortCredits.isEmpty())
		imCredits["short"]=dataSetCredits.shortCredits;
	if (!dataSetCredits.fullCredits.isEmpty())
		imCredits["full"]=dataSetCredits.fullCredits;
	if (!dataSetCredits.infoURL.isEmpty())
		imCredits["infoUrl"]=dataSetCredits.infoURL;
	if (!imCredits.empty())
		res["imageCredits"]=imCredits;

	// Server credits
	QVariantMap serCredits;
	if (!serverCredits.shortCredits.isEmpty())
		imCredits["short"]=serverCredits.shortCredits;
	if (!serverCredits.fullCredits.isEmpty())
		imCredits["full"]=serverCredits.fullCredits;
	if (!serverCredits.infoURL.isEmpty())
		imCredits["infoUrl"]=serverCredits.infoURL;
	if (!serCredits.empty())
		res["serverCredits"]=serCredits;

	// Misc
	if (!shortName.isEmpty())
		res["shortName"] = shortName;
	if (minResolution>0)
		 res["minResolution"]=minResolution;
	if (luminance>0)
		res["maxBrightness"]=StelApp::getInstance().getCore()->getSkyDrawer()->luminanceToSurfacebrightness(luminance);
	if (alphaBlend)
		res["alphaBlend"]=true;
	if (noTexture==false)
		res["imageUrl"]=absoluteImageURI;

	// Polygons
	// TODO

	// textures positions
	// TODO

	if (!subTilesUrls.empty())
	{
		res["subTiles"] = subTilesUrls;
	}

	return res;
}
