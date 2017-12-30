/*
 * Stellarium
 * Copyright (C) 2008 Fabien Chereau
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


#include "ViewDialog.hpp"
#include "ui_viewDialog.h"
#include "AddRemoveLandscapesDialog.hpp"
#include "AtmosphereDialog.hpp"
#include "StelApp.hpp"
#include "StelCore.hpp"
#include "StelSkyCultureMgr.hpp"
#include "StelFileMgr.hpp"
#include "StelLocaleMgr.hpp"
#include "StelProjector.hpp"
#include "LandscapeMgr.hpp"
#include "StelModuleMgr.hpp"
#include "StarMgr.hpp"
#include "StelSkyDrawer.hpp"
#include "SolarSystem.hpp"
#include "NebulaMgr.hpp"
#include "MeteorMgr.hpp"
#include "MilkyWay.hpp"
#include "ConstellationMgr.hpp"
#include "StelStyle.hpp"
#include "StelSkyLayerMgr.hpp"
#include "StelGuiBase.hpp"
#include "StelGui.hpp"
#include "StelGuiItems.hpp"
#include "StelActionMgr.hpp"

#include <QDebug>
#include <QFrame>
#include <QFile>
#include <QFileInfo>
#include <QSettings>
#include <QTimer>
#include <QDialog>

ViewDialog::ViewDialog(QObject* parent) : StelDialog(parent)
{
	ui = new Ui_viewDialogForm;
	addRemoveLandscapesDialog = NULL;
	atmosphereDialog=NULL;
}

ViewDialog::~ViewDialog()
{
	delete ui;
	ui=NULL;
	delete addRemoveLandscapesDialog;
	addRemoveLandscapesDialog = NULL;
	delete atmosphereDialog;
	atmosphereDialog = NULL;
}

void ViewDialog::retranslate()
{
	if (dialog)
	{
		ui->retranslateUi(dialog);
		setZhrFromControls();
		populateLists();

		//Hack to shrink the tabs to optimal size after language change
		//by causing the list items to be laid out again.
		ui->stackListWidget->setWrapping(false);
	}
}

void ViewDialog::styleChanged()
{
	if (dialog)
	{
		populateLists();
	}
}

void ViewDialog::connectCheckBox(QCheckBox* checkBox, const QString& actionId)
{
	StelAction* action = StelApp::getInstance().getStelActionManager()->findAction(actionId);
	Q_ASSERT(action);
	checkBox->setChecked(action->isChecked());
	connect(action, SIGNAL(toggled(bool)), checkBox, SLOT(setChecked(bool)));
	connect(checkBox, SIGNAL(toggled(bool)), action, SLOT(setChecked(bool)));
}

void ViewDialog::createDialogContent()
{
	ui->setupUi(dialog);
	connect(&StelApp::getInstance(), SIGNAL(languageChanged()), this, SLOT(retranslate()));

	// Set the Sky tab activated by default
	ui->stackedWidget->setCurrentIndex(0);
	ui->stackListWidget->setCurrentRow(0);

	//ui->viewTabWidget->removeTab(4);

	connect(ui->closeStelWindow, SIGNAL(clicked()), this, SLOT(close()));

	populateLists();
	connect(ui->culturesListWidget, SIGNAL(currentTextChanged(const QString&)), this, SLOT(skyCultureChanged(const QString&)));
	connect(ui->projectionListWidget, SIGNAL(currentTextChanged(const QString&)), this, SLOT(projectionChanged(const QString&)));
	connect(ui->landscapesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(landscapeChanged(QListWidgetItem*)));

	// Connect and initialize checkboxes and other widgets

	// Stars section
	ui->starTwinkleCheckBox->setChecked(StelApp::getInstance().getCore()->getSkyDrawer()->getFlagTwinkle());
	connect(ui->starTwinkleCheckBox, SIGNAL(toggled(bool)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setFlagTwinkle(bool)));

	ui->starScaleRadiusDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getAbsoluteStarScale());
	connect(ui->starScaleRadiusDoubleSpinBox, SIGNAL(valueChanged(double)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setAbsoluteStarScale(double)));

	ui->starRelativeScaleDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getRelativeStarScale());
	connect(ui->starRelativeScaleDoubleSpinBox, SIGNAL(valueChanged(double)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setRelativeStarScale(double)));

	MilkyWay* mw = GETSTELMODULE(MilkyWay);
	ui->milkyWayBrightnessDoubleSpinBox->setValue(mw->getIntensity());
	connect(ui->milkyWayBrightnessDoubleSpinBox, SIGNAL(valueChanged(double)), mw, SLOT(setIntensity(double)));

	ui->starTwinkleAmountDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getTwinkleAmount());
	connect(ui->starTwinkleAmountDoubleSpinBox, SIGNAL(valueChanged(double)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setTwinkleAmount(double)));

	ui->adaptationCheckbox->setChecked(StelApp::getInstance().getCore()->getSkyDrawer()->getFlagLuminanceAdaptation());
	connect(ui->adaptationCheckbox, SIGNAL(toggled(bool)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setFlagLuminanceAdaptation(bool)));

	// Limit Magnitudes
	const StelSkyDrawer* drawer = StelApp::getInstance().getCore()->getSkyDrawer();
	ui->starLimitMagnitudeCheckBox->setChecked(drawer->getFlagStarMagnitudeLimit());
	ui->nebulaLimitMagnitudeCheckBox->setChecked(drawer->getFlagNebulaMagnitudeLimit());
	ui->starLimitMagnitudeDoubleSpinBox->setValue(drawer->getCustomStarMagnitudeLimit());
	ui->nebulaLimitMagnitudeDoubleSpinBox->setValue(drawer->getCustomNebulaMagnitudeLimit());
	
	connect(ui->starLimitMagnitudeCheckBox, SIGNAL(toggled(bool)),
	        drawer, SLOT(setFlagStarMagnitudeLimit(bool)));
	connect(ui->nebulaLimitMagnitudeCheckBox, SIGNAL(toggled(bool)),
	        drawer, SLOT(setFlagNebulaMagnitudeLimit(bool)));
	connect(ui->starLimitMagnitudeDoubleSpinBox, SIGNAL(valueChanged(double)),
	        drawer, SLOT(setCustomStarMagnitudeLimit(double)));
	connect(ui->nebulaLimitMagnitudeDoubleSpinBox,
	        SIGNAL(valueChanged(double)),
	        drawer,
	        SLOT(setCustomNebulaMagnitudeLimit(double)));

	// Planets section
	SolarSystem* ssmgr = GETSTELMODULE(SolarSystem);
	ui->showPlanetCheckBox->setChecked(ssmgr->getFlagPlanets());
	connect(ui->showPlanetCheckBox, SIGNAL(toggled(bool)), ssmgr, SLOT(setFlagPlanets(bool)));

	ui->planetMarkerCheckBox->setChecked(ssmgr->getFlagHints());
	connect(ui->planetMarkerCheckBox, SIGNAL(toggled(bool)), ssmgr, SLOT(setFlagHints(bool)));

	ui->planetScaleMoonCheckBox->setChecked(ssmgr->getFlagMoonScale());
	connect(ui->planetScaleMoonCheckBox, SIGNAL(toggled(bool)), ssmgr, SLOT(setFlagMoonScale(bool)));

	ui->planetOrbitCheckBox->setChecked(ssmgr->getFlagOrbits());
	connect(ui->planetOrbitCheckBox, SIGNAL(toggled(bool)), ssmgr, SLOT(setFlagOrbits(bool)));

	ui->planetLightSpeedCheckBox->setChecked(ssmgr->getFlagLightTravelTime());
	connect(ui->planetLightSpeedCheckBox, SIGNAL(toggled(bool)), ssmgr, SLOT(setFlagLightTravelTime(bool)));

	// Shooting stars section
	MeteorMgr* mmgr = GETSTELMODULE(MeteorMgr);
	Q_ASSERT(mmgr);
	updateZhrControls(mmgr->getZHR());
	connect(mmgr, SIGNAL(zhrChanged(int)),
					this, SLOT(updateZhrControls(int)));
	connect(ui->zhrNone, SIGNAL(clicked()), this, SLOT(setZhrFromControls()));
	connect(ui->zhr10, SIGNAL(clicked()), this, SLOT(setZhrFromControls()));
	connect(ui->zhr80, SIGNAL(clicked()), this, SLOT(setZhrFromControls()));
	connect(ui->zhr1000, SIGNAL(clicked()), this, SLOT(setZhrFromControls()));
	connect(ui->zhr10000, SIGNAL(clicked()), this, SLOT(setZhrFromControls()));
	connect(ui->zhr144000, SIGNAL(clicked()), this, SLOT(setZhrFromControls()));

	// Labels section
	StarMgr* smgr = GETSTELMODULE(StarMgr);
	ui->starLabelCheckBox->setChecked(smgr->getFlagLabels());
	connect(ui->starLabelCheckBox, SIGNAL(toggled(bool)), smgr, SLOT(setFlagLabels(bool)));

	connectCheckBox(ui->nebulaLabelCheckBox, "actionShow_Nebulas");
	connectCheckBox(ui->planetLabelCheckBox, "actionShow_Planets_Labels");

	NebulaMgr* nmgr = GETSTELMODULE(NebulaMgr);

	ui->starsLabelsHorizontalSlider->setValue((int)(smgr->getLabelsAmount()*10.f));
	connect(ui->starsLabelsHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(starsLabelsValueChanged(int)));
	ui->planetsLabelsHorizontalSlider->setValue((int)(ssmgr->getLabelsAmount()*10.f));
	connect(ui->planetsLabelsHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(planetsLabelsValueChanged(int)));
	ui->nebulasLabelsHorizontalSlider->setValue((int)(nmgr->getHintsAmount()*10.f));
	connect(ui->nebulasLabelsHorizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(nebulasLabelsValueChanged(int)));

	// Landscape section
	LandscapeMgr* lmgr = GETSTELMODULE(LandscapeMgr);
	connectCheckBox(ui->showGroundCheckBox, "actionShow_Ground");
	connectCheckBox(ui->showFogCheckBox, "actionShow_Fog");
	connectCheckBox(ui->showAtmosphereCheckBox, "actionShow_Atmosphere");

	ui->landscapePositionCheckBox->setChecked(lmgr->getFlagLandscapeSetsLocation());
	connect(ui->landscapePositionCheckBox, SIGNAL(toggled(bool)), lmgr, SLOT(setFlagLandscapeSetsLocation(bool)));

	ui->landscapeBrightnessCheckBox->setChecked(lmgr->getFlagLandscapeNightBrightness());
	connect(ui->landscapeBrightnessCheckBox, SIGNAL(toggled(bool)), lmgr, SLOT(setFlagLandscapeNightBrightness(bool)));

	ui->lightPollutionSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getBortleScale());
	connect(ui->lightPollutionSpinBox, SIGNAL(valueChanged(int)), lmgr, SLOT(setAtmosphereBortleLightPollution(int)));
	connect(ui->lightPollutionSpinBox, SIGNAL(valueChanged(int)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setBortleScale(int)));

	ui->autoChangeLandscapesCheckBox->setChecked(lmgr->getFlagLandscapeAutoSelection());
	connect(ui->autoChangeLandscapesCheckBox, SIGNAL(toggled(bool)), lmgr, SLOT(setFlagLandscapeAutoSelection(bool)));
	
	// GZ: changes for refraction
	//ui->pressureDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getAtmospherePressure());
	//connect(ui->pressureDoubleSpinBox, SIGNAL(valueChanged(double)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setAtmospherePressure(double)));
	//ui->temperatureDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getAtmosphereTemperature());
	//connect(ui->temperatureDoubleSpinBox, SIGNAL(valueChanged(double)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setAtmosphereTemperature(double)));
	//ui->extinctionDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getExtinctionCoefficient());
	//connect(ui->extinctionDoubleSpinBox, SIGNAL(valueChanged(double)), StelApp::getInstance().getCore()->getSkyDrawer(), SLOT(setExtinctionCoefficient(double)));
	//// instead
	connect(ui->pushButtonAtmosphereDetails, SIGNAL(clicked()), this, SLOT(showAtmosphereDialog()));
	// GZ: Done


	ui->useAsDefaultLandscapeCheckBox->setChecked(lmgr->getCurrentLandscapeID()==lmgr->getDefaultLandscapeID());
	ui->useAsDefaultLandscapeCheckBox->setEnabled(lmgr->getCurrentLandscapeID()!=lmgr->getDefaultLandscapeID());
	connect(ui->useAsDefaultLandscapeCheckBox, SIGNAL(clicked()), this, SLOT(setCurrentLandscapeAsDefault()));

	connect(GETSTELMODULE(LandscapeMgr), SIGNAL(landscapesChanged()), this, SLOT(populateLists()));
	connect(ui->pushButtonAddRemoveLandscapes, SIGNAL(clicked()), this, SLOT(showAddRemoveLandscapesDialog()));

	// Grid and lines
	connectCheckBox(ui->showEquatorLineCheckBox, "actionShow_Equator_Line");
	connectCheckBox(ui->showEclipticLineCheckBox, "actionShow_Ecliptic_Line");
	connectCheckBox(ui->showMeridianLineCheckBox, "actionShow_Meridian_Line");
	connectCheckBox(ui->showHorizonLineCheckBox, "actionShow_Horizon_Line");
	connectCheckBox(ui->showEquatorialGridCheckBox, "actionShow_Equatorial_Grid");
	connectCheckBox(ui->showGalacticGridCheckBox, "actionShow_Galactic_Grid");
	connectCheckBox(ui->showGalacticPlaneLineCheckBox, "actionShow_Galactic_Plane_Line");
	connectCheckBox(ui->showAzimuthalGridCheckBox, "actionShow_Azimuthal_Grid");
	connectCheckBox(ui->showEquatorialJ2000GridCheckBox, "actionShow_Equatorial_J2000_Grid");
	connectCheckBox(ui->showEclipticGridJ2000CheckBox, "actionShow_Ecliptic_J2000_Grid");
	connectCheckBox(ui->showCardinalPointsCheckBox, "actionShow_Cardinal_Points");

	// Constellations
	ConstellationMgr* cmgr = GETSTELMODULE(ConstellationMgr);
	connectCheckBox(ui->showConstellationLinesCheckBox, "actionShow_Constellation_Lines");
	connectCheckBox(ui->showConstellationLabelsCheckBox, "actionShow_Constellation_Labels");
	connectCheckBox(ui->showConstellationBoundariesCheckBox, "actionShow_Constellation_Boundaries");
	connectCheckBox(ui->showConstellationArtCheckBox, "actionShow_Constellation_Art");
	ui->constellationArtBrightnessSpinBox->setValue(cmgr->getArtIntensity());
	connect(ui->constellationArtBrightnessSpinBox, SIGNAL(valueChanged(double)), cmgr, SLOT(setArtIntensity(double)));

	// Starlore
	connect(ui->useAsDefaultSkyCultureCheckBox, SIGNAL(clicked()), this, SLOT(setCurrentCultureAsDefault()));
	const bool b = StelApp::getInstance().getSkyCultureMgr().getCurrentSkyCultureID()==StelApp::getInstance().getSkyCultureMgr().getDefaultSkyCultureID();
	ui->useAsDefaultSkyCultureCheckBox->setChecked(b);
	ui->useAsDefaultSkyCultureCheckBox->setEnabled(!b);

	// Sky layers
	populateSkyLayersList();
	connect(this, SIGNAL(visibleChanged(bool)), this, SLOT(populateSkyLayersList()));
	connect(ui->skyLayerListWidget, SIGNAL(currentTextChanged(const QString&)), this, SLOT(skyLayersSelectionChanged(const QString&)));
	connect(ui->stackListWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(changePage(QListWidgetItem *, QListWidgetItem*)));
	connect(ui->skyLayerEnableCheckBox, SIGNAL(stateChanged(int)), this, SLOT(skyLayersEnabledChanged(int)));

	QTimer* refreshTimer = new QTimer(this);
	connect(refreshTimer, SIGNAL(timeout()), this, SLOT(updateFromProgram()));
	refreshTimer->start(200);
}

void ViewDialog::populateLists()
{
	// Fill the culture list widget from the available list
	QListWidget* l = ui->culturesListWidget;
	l->blockSignals(true);
	l->clear();
	l->addItems(StelApp::getInstance().getSkyCultureMgr().getSkyCultureListI18());
	l->setCurrentItem(l->findItems(StelApp::getInstance().getSkyCultureMgr().getCurrentSkyCultureNameI18(), Qt::MatchExactly).at(0));
	l->blockSignals(false);
	updateSkyCultureText();

	const StelCore* core = StelApp::getInstance().getCore();	
	StelGui* gui = dynamic_cast<StelGui*>(StelApp::getInstance().getGui());
	Q_ASSERT(gui);

	// Fill the projection list
	l = ui->projectionListWidget;
	l->blockSignals(true);
	l->clear();
	const QStringList mappings = core->getAllProjectionTypeKeys();
	foreach (QString s, mappings)
	{
		l->addItem(core->projectionTypeKeyToNameI18n(s));
	}
	l->setCurrentItem(l->findItems(core->projectionTypeKeyToNameI18n(core->getCurrentProjectionTypeKey()), Qt::MatchExactly).at(0));
	l->blockSignals(false);
	ui->projectionTextBrowser->document()->setDefaultStyleSheet(QString(gui->getStelStyle().htmlStyleSheet));
	ui->projectionTextBrowser->setHtml(core->getProjection(StelCore::FrameJ2000)->getHtmlSummary());

	// Fill the landscape list
	l = ui->landscapesListWidget;
	l->blockSignals(true);
	l->clear();
	LandscapeMgr* lmgr = GETSTELMODULE(LandscapeMgr);
	QStringList landscapeList = lmgr->getAllLandscapeNames();
	foreach (const QString landscapeId, landscapeList)
	{
		QString label = q_(landscapeId);
		QListWidgetItem* item = new QListWidgetItem(label);
		item->setData(Qt::UserRole, landscapeId);
		l->addItem(item);
	}
	QString selectedLandscapeId = lmgr->getCurrentLandscapeName();
	for (int i = 0; i < l->count(); i++)
	{
		if (l->item(i)->data(Qt::UserRole).toString() == selectedLandscapeId)
		{
			l->setCurrentRow(i);
			break;
		}
	}
	l->blockSignals(false);	
	ui->landscapeTextBrowser->document()->setDefaultStyleSheet(QString(gui->getStelStyle().htmlStyleSheet));
	ui->landscapeTextBrowser->setHtml(lmgr->getCurrentLandscapeHtmlDescription());
	ui->useAsDefaultLandscapeCheckBox->setChecked(lmgr->getDefaultLandscapeID()==lmgr->getCurrentLandscapeID());
	ui->useAsDefaultLandscapeCheckBox->setEnabled(lmgr->getDefaultLandscapeID()!=lmgr->getCurrentLandscapeID());
}

void ViewDialog::populateSkyLayersList()
{
	ui->skyLayerListWidget->clear();
	StelSkyLayerMgr* skyLayerMgr = GETSTELMODULE(StelSkyLayerMgr);
	ui->skyLayerListWidget->addItems(skyLayerMgr->getAllKeys());
}

void ViewDialog::skyLayersSelectionChanged(const QString& s)
{
	StelSkyLayerMgr* skyLayerMgr = GETSTELMODULE(StelSkyLayerMgr);
	StelSkyLayerP l = skyLayerMgr->getSkyLayer(s);

	if (l.isNull())
		return;

	QString html = "<html><head></head><body>";
	html += "<h2>" + l->getShortName()+ "</h2>";
	html += "<p>" + l->getLayerDescriptionHtml() + "</p>";
	if (!l->getShortServerCredits().isEmpty())
		html += "<h3>" + q_("Contact") + ": " + l->getShortServerCredits() + "</h3>";
	html += "</body></html>";
	ui->skyLayerTextBrowser->setHtml(html);
	ui->skyLayerEnableCheckBox->setChecked(skyLayerMgr->getShowLayer(s));
}

void ViewDialog::skyLayersEnabledChanged(int state)
{
	StelSkyLayerMgr* skyLayerMgr = GETSTELMODULE(StelSkyLayerMgr);
	skyLayerMgr->showLayer(ui->skyLayerListWidget->currentItem()->text(), state);
}

void ViewDialog::skyCultureChanged(const QString& cultureName)
{
	StelApp::getInstance().getSkyCultureMgr().setCurrentSkyCultureNameI18(cultureName);
	updateSkyCultureText();
	const bool b = StelApp::getInstance().getSkyCultureMgr().getCurrentSkyCultureID()==StelApp::getInstance().getSkyCultureMgr().getDefaultSkyCultureID();
	ui->useAsDefaultSkyCultureCheckBox->setChecked(b);
	ui->useAsDefaultSkyCultureCheckBox->setEnabled(!b);
}

void ViewDialog::updateSkyCultureText()
{
	StelApp& app = StelApp::getInstance();
	QString skyCultureId = app.getSkyCultureMgr().getCurrentSkyCultureID();
	QString lang = app.getLocaleMgr().getAppLanguage();
	if (!QString("pt_BR zh_CN zh_HK zh_TW").contains(lang))
	{
		lang = lang.split("_").at(0);
	}
	QString descPath = StelFileMgr::findFile("skycultures/" + skyCultureId + "/description."+lang+".utf8");
	if (descPath.isEmpty())
	{
		descPath = StelFileMgr::findFile("skycultures/" + skyCultureId + "/description.en.utf8");
		if (descPath.isEmpty())
			qWarning() << "WARNING: can't find description for skyculture" << skyCultureId;
	}

	QStringList searchPaths;
	searchPaths << StelFileMgr::findFile("skycultures/" + skyCultureId);

	ui->skyCultureTextBrowser->setSearchPaths(searchPaths);
	StelGui* gui = dynamic_cast<StelGui*>(app.getGui());
	Q_ASSERT(gui);
	ui->skyCultureTextBrowser->document()->setDefaultStyleSheet(QString(gui->getStelStyle().htmlStyleSheet));

	if (descPath.isEmpty())
	{
		ui->skyCultureTextBrowser->setHtml(q_("No description"));
	}
	else
	{
		QFile f(descPath);
		f.open(QIODevice::ReadOnly);
		QString htmlFile = QString::fromUtf8(f.readAll());
		ui->skyCultureTextBrowser->setHtml(htmlFile);
	}
}

void ViewDialog::projectionChanged(const QString& projectionNameI18n)
{
	StelCore* core = StelApp::getInstance().getCore();
	core->setCurrentProjectionTypeKey(core->projectionNameI18nToTypeKey(projectionNameI18n));
	StelGui* gui = dynamic_cast<StelGui*>(StelApp::getInstance().getGui());
	Q_ASSERT(gui);
	ui->projectionTextBrowser->document()->setDefaultStyleSheet(QString(gui->getStelStyle().htmlStyleSheet));
	ui->projectionTextBrowser->setHtml(core->getProjection(StelCore::FrameJ2000)->getHtmlSummary());
}

void ViewDialog::landscapeChanged(QListWidgetItem* item)
{
	LandscapeMgr* lmgr = GETSTELMODULE(LandscapeMgr);
	lmgr->setCurrentLandscapeName(item->data(Qt::UserRole).toString());
	StelGui* gui = dynamic_cast<StelGui*>(StelApp::getInstance().getGui());
	Q_ASSERT(gui);
	ui->landscapeTextBrowser->document()->setDefaultStyleSheet(QString(gui->getStelStyle().htmlStyleSheet));
	ui->landscapeTextBrowser->setHtml(lmgr->getCurrentLandscapeHtmlDescription());
	ui->useAsDefaultLandscapeCheckBox->setChecked(lmgr->getDefaultLandscapeID()==lmgr->getCurrentLandscapeID());
	ui->useAsDefaultLandscapeCheckBox->setEnabled(lmgr->getDefaultLandscapeID()!=lmgr->getCurrentLandscapeID());
	//StelSkyDrawer *drawer=StelApp::getInstance().getSkyDrawer();
	// GZ: Reset values that might have changed.
	ui->showFogCheckBox->setChecked(lmgr->getFlagFog());
	ui->lightPollutionSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getBortleScale());
}

void ViewDialog::showAddRemoveLandscapesDialog()
{
	if(addRemoveLandscapesDialog == NULL)
		addRemoveLandscapesDialog = new AddRemoveLandscapesDialog();

	addRemoveLandscapesDialog->setVisible(true);
}

void ViewDialog::showAtmosphereDialog()
{
	if(atmosphereDialog == NULL)
		atmosphereDialog = new AtmosphereDialog();
	//ui->temperatureDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getAtmosphereTemperature());
	//ui->extinctionDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getExtinctionCoefficient());
	//ui->pressureDoubleSpinBox->setValue(StelApp::getInstance().getCore()->getSkyDrawer()->getAtmospherePressure());

	atmosphereDialog->setVisible(true);
}


void ViewDialog::setZhrFromControls()
{
	MeteorMgr* mmgr = GETSTELMODULE(MeteorMgr);
	int zhr=-1;
	if (ui->zhrNone->isChecked())
	{
		mmgr->setFlagShow(false);
		zhr = 0;
	}
	else
	{
		mmgr->setFlagShow(true);
	}
	if (ui->zhr10->isChecked())
		zhr = 10;
	if (ui->zhr80->isChecked())
		zhr = 80;
	if (ui->zhr1000->isChecked())
		zhr = 1000;
	if (ui->zhr10000->isChecked())
		zhr = 10000;
	if (ui->zhr144000->isChecked())
		zhr = 144000;
	if (zhr!=mmgr->getZHR())
	{
		mmgr->setZHR(zhr);
	}
	
	updateZhrDescription(zhr);
}

void ViewDialog::updateZhrControls(int zhr)
{
	// As the radio buttons are tied to the clicked() signal,
	// it won't be triggered by setting the value programmatically.
	switch(zhr)
	{
		case 0: ui->zhrNone->setChecked(true); break;
		case 80: ui->zhr80->setChecked(true); break;
		case 1000: ui->zhr1000->setChecked(true); break;
		case 10000: ui->zhr10000->setChecked(true); break;
		case 144000: ui->zhr144000->setChecked(true); break;
		default: ui->zhr10->setChecked(true); break;
	}
	
	updateZhrDescription(zhr);
}

void ViewDialog::updateZhrDescription(int zhr)
{
	switch (zhr)
	{
		case 0:
			ui->zhrLabel->setText("<small><i>"+q_("No shooting stars")+"</i></small>");
			break;
		case 10:
			ui->zhrLabel->setText("<small><i>"+q_("Normal rate")+"</i></small>");
			break;
		case 80:
			ui->zhrLabel->setText("<small><i>"+q_("Standard Perseids rate")+"</i></small>");
			break;
		case 1000:
			ui->zhrLabel->setText("<small><i>"+q_("Meteor storm rate")+"</i></small>");
			break;
		case 10000:
			ui->zhrLabel->setText("<small><i>"+q_("Exceptional Leonid rate")+"</i></small>");
			break;
		case 144000:
			ui->zhrLabel->setText("<small><i>"+q_("Highest rate ever (1966 Leonids)")+"</i></small>");
			break;
		default:
			ui->zhrLabel->setText(QString("<small><i>")+"Error"+"</i></small>");
	}
}

void ViewDialog::starsLabelsValueChanged(int v)
{
	StarMgr* smgr = GETSTELMODULE(StarMgr);
	float a= ((float)v)/10.f;
	smgr->setLabelsAmount(a);
}

void ViewDialog::setCurrentLandscapeAsDefault(void)
{
	LandscapeMgr* lmgr = GETSTELMODULE(LandscapeMgr);
	Q_ASSERT(lmgr);
	lmgr->setDefaultLandscapeID(lmgr->getCurrentLandscapeID());
	ui->useAsDefaultLandscapeCheckBox->setChecked(true);
	ui->useAsDefaultLandscapeCheckBox->setEnabled(false);
}

void ViewDialog::setCurrentCultureAsDefault(void)
{
	StelApp::getInstance().getSkyCultureMgr().setDefaultSkyCultureID(StelApp::getInstance().getSkyCultureMgr().getCurrentSkyCultureID());
	ui->useAsDefaultSkyCultureCheckBox->setChecked(true);
	ui->useAsDefaultSkyCultureCheckBox->setEnabled(false);
}

void ViewDialog::planetsLabelsValueChanged(int v)
{
	SolarSystem* ssmgr = GETSTELMODULE(SolarSystem);
	float a= ((float)v)/10.f;
	ssmgr->setLabelsAmount(a);
}

void ViewDialog::nebulasLabelsValueChanged(int v)
{
	NebulaMgr* nmgr = GETSTELMODULE(NebulaMgr);
	float a= ((float)v)/10.f;
	nmgr->setHintsAmount(a);
	nmgr->setLabelsAmount(a);
}

// Update the widget to make sure it is synchrone if a value was changed programmatically
void ViewDialog::updateFromProgram()
{
	if (!dialog->isVisible())
		return;

	// Check that the useAsDefaultSkyCultureCheckBox needs to be updated
	bool b = StelApp::getInstance().getSkyCultureMgr().getCurrentSkyCultureID()==StelApp::getInstance().getSkyCultureMgr().getDefaultSkyCultureID();
	if (b!=ui->useAsDefaultSkyCultureCheckBox->isChecked())
	{
		ui->useAsDefaultSkyCultureCheckBox->setChecked(b);
		ui->useAsDefaultSkyCultureCheckBox->setEnabled(!b);
	}

	LandscapeMgr* lmgr = GETSTELMODULE(LandscapeMgr);
	Q_ASSERT(lmgr);
	b = lmgr->getCurrentLandscapeID()==lmgr->getDefaultLandscapeID();
	if (b!=ui->useAsDefaultLandscapeCheckBox->isChecked())
	{
		ui->useAsDefaultLandscapeCheckBox->setChecked(b);
		ui->useAsDefaultLandscapeCheckBox->setEnabled(!b);
	}
}

void ViewDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
	if (!current)
		current = previous;
	ui->stackedWidget->setCurrentIndex(ui->stackListWidget->row(current));
}
