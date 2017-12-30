/*
 * The big star catalogue extension to Stellarium:
 * Author and Copyright: Johannes Gajdosik, 2006, 2007
 * The implementation of most functions in this file
 * (getInfoString,getShortInfoString,...) is taken from
 * Stellarium, Copyright (C) 2002 Fabien Chereau,
 * and therefore the copyright of these belongs to Fabien Chereau.
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

#include "StarWrapper.hpp"
#include "ZoneArray.hpp"

#include "StelUtils.hpp"
#include "StelTranslator.hpp"

#include <QTextStream>
#include <limits>

template<typename T> inline bool isNan(T value)
{
	return value != value;
}

template<typename T> inline bool isInf(T value)
{
	return std::numeric_limits<T>::has_infinity && value == std::numeric_limits<T>::infinity();
}

QString StarWrapperBase::getInfoString(const StelCore *core, const InfoStringGroup& flags) const
{
	QString str;
	QTextStream oss(&str);

	if (flags&Type)
	{
		oss << q_("Type: <b>%1</b>").arg(q_("star")) << "<br />";
	}

	if (flags&Magnitude)
	{
		if (core->getSkyDrawer()->getFlagHasAtmosphere())
			oss << q_("Magnitude: <b>%1</b> (extincted to: <b>%2</b>)").arg(QString::number(getVMagnitude(core), 'f', 2))
				   .arg(QString::number(getVMagnitudeWithExtinction(core), 'f', 2)) << "<br>";
		else
			oss << q_("Magnitude: <b>%1</b>").arg(QString::number(getVMagnitude(core), 'f', 2)) << "<br>";
	}
	
	if (flags&Extra)
	{
		oss << q_("Color Index (B-V): <b>%2</b>").arg(QString::number(getBV(), 'f', 2)) << "<br>";
	}
	
	oss << getPositionInfoString(core, flags);

	StelObject::postProcessInfoString(str, flags);

	return str;
}


QString StarWrapper1::getEnglishName(void) const
{
	if (s->hip)
		return QString("HIP %1").arg(s->hip);
	return StarWrapperBase::getEnglishName();
}

QString StarWrapper1::getInfoString(const StelCore *core, const InfoStringGroup& flags) const
{
	QString str;

	QTextStream oss(&str);
	const QString varType = StarMgr::getGcvsVariabilityType(s->hip);
	const float maxVMag = StarMgr::getGcvsMaxMagnitude(s->hip);
	const float magFlag = StarMgr::getGcvsMagnitudeFlag(s->hip);
	const float minVMag = StarMgr::getGcvsMinMagnitude(s->hip);
	const float min2VMag = StarMgr::getGcvsMinMagnitude(s->hip, false);
	const QString photoVSys = StarMgr::getGcvsPhotometricSystem(s->hip);
	const double vEpoch = StarMgr::getGcvsEpoch(s->hip);
	const double vPeriod = StarMgr::getGcvsPeriod(s->hip);
	const int vMm = StarMgr::getGcvsMM(s->hip);
	if (s->hip)
	{
		if ((flags&Name) || (flags&CatalogNumber))
			oss << "<h2>";

		const QString commonNameI18 = StarMgr::getCommonName(s->hip);
		const QString sciName = StarMgr::getSciName(s->hip);
		const QString addSciName = StarMgr::getSciAdditionalName(s->hip);
		const QString varSciName = StarMgr::getGcvsName(s->hip);

		bool nameWasEmpty=true;
		if (flags&Name)
		{
			if (commonNameI18!="" || sciName!="" || addSciName!="" || varSciName!="")
			{
				oss << commonNameI18 << (commonNameI18 == "" ? "" : " ");
				if (commonNameI18!="" && (sciName!="" || varSciName!=""))
					oss << "(";
				oss << (sciName=="" ? "" : sciName);
				oss << (addSciName=="" ? "" : QString(" - %1").arg(addSciName));
				if (varSciName!="" && varSciName!=sciName)
					oss << (sciName=="" ? "" : " - ") << varSciName;
				if (commonNameI18!="" && (sciName!="" || varSciName!=""))
					oss << ")";
				nameWasEmpty=false;
			}
		}
		if ((flags&CatalogNumber) && (flags&Name) && !nameWasEmpty)
			oss << " - ";

		if (flags&CatalogNumber || (nameWasEmpty && (flags&Name)))
			oss << "HIP " << s->hip;
		if (s->componentIds)
			oss << " " << StarMgr::convertToComponentIds(s->componentIds);

		if ((flags&Name) || (flags&CatalogNumber))
			oss << "</h2>";
	}

	bool ebsFlag = false;
	if (flags&Type)
	{
		QString varstartype = "";
		QString startype = "";
		if(!varType.isEmpty())
		{
			if (QString("FU GCAS I IA IB IN INA INB INT IT IN(YY) IS ISA ISB RCB RS SDOR UV UVN WR").contains(varType))
				varstartype = q_("eruptive variable star");
			else if (QString("ACYG BCEP BCEPS CEP CEP(B) CW CWA CWB DCEP DCEPS DSCT DSCTC GDOR L LB LC M PVTEL RPHS RR RR(B) RRAB RRC RV RVA RVB SR SRA SRB SRC SRD SXPHE ZZ ZZA ZZB").contains(varType))
				varstartype = q_("pulsating variable star");
			else if (QString("ACV, ACVO, BY, ELL, FKCOM, PSR, SXARI").contains(varType))
				varstartype = q_("rotating variable star");
			else if (QString("N NA NB NC NL NR SN SNI SNII UG UGSS UGSU UGZ ZAND").contains(varType))
				varstartype = q_("cataclysmic variable star");
			else if (QString("E EA EB EW GS PN RS WD WR AR D DM DS DW K KE KW SD E: E:/WR E/D E+LPB: EA/D EA/D+BY EA/RS EA/SD EA/SD: EA/GS EA/GS+SRC EA/DM EA/WR EA+LPB EA+LPB: EA+DSCT EA+BCEP: EA+ZAND EA+ACYG EA+SRD EB/GS EB/DM EB/KE EB/KE: EW/KE EA/AR/RS EA/GS/D EA/D/WR").contains(varType))
			{
				varstartype = q_("eclipsing binary system");
				ebsFlag = true;
			}
			else
				varstartype = q_("variable star");
		}

		if (s->componentIds)
			startype = q_("double star");
		else
			startype = q_("star");

		if (!varType.isEmpty())
		{
			if (s->componentIds)
				oss << q_("Type: <b>%1, %2</b>").arg(varstartype).arg(startype);
			else
				oss << q_("Type: <b>%1</b>").arg(varstartype);
			oss << " (" << varType << ")<br />";
		} else
			oss << q_("Type: <b>%1</b>").arg(startype) << "<br />";

	}

	if (flags&Magnitude)
	{
		if (core->getSkyDrawer()->getFlagHasAtmosphere())
			oss << q_("Magnitude: <b>%1</b> (extincted to: <b>%2</b>)").arg(QString::number(getVMagnitude(core), 'f', 2))
				   .arg(QString::number(getVMagnitudeWithExtinction(core), 'f', 2)) << "<br>";
		else
			oss << q_("Magnitude: <b>%1</b>").arg(QString::number(getVMagnitude(core), 'f', 2)) << "<br>";
	}

	if ((flags&AbsoluteMagnitude) && s->plx && !isNan(s->plx) && !isInf(s->plx))
		oss << q_("Absolute Magnitude: %1").arg(getVMagnitude(core)+5.*(1.+std::log10(0.00001*s->plx)), 0, 'f', 2) << "<br>";

	if (flags&Extra)
	{
		oss << q_("Color Index (B-V): <b>%2</b>").arg(QString::number(s->getBV(), 'f', 2)) << "<br>";
	}
	
	if (flags&Extra)
	{
		if (!varType.isEmpty())
		{
			float minimumM1 = minVMag;
			float minimumM2 = min2VMag;
			if (magFlag==1) // Amplitude
			{
				minimumM1 += maxVMag;
				minimumM2 += maxVMag;
			}

			if (min2VMag==99.f)
				oss << q_("Magnitude range: <b>%1</b>%2<b>%3</b> (Photometric system: %4)").arg(QString::number(maxVMag, 'f', 2)).arg(QChar(0x00F7)).arg(QString::number(minimumM1, 'f', 2)).arg(photoVSys) << "<br />";
			else
				oss << q_("Magnitude range: <b>%1</b>%2<b>%3/%4</b> (Photometric system: %5)").arg(QString::number(maxVMag, 'f', 2)).arg(QChar(0x00F7)).arg(QString::number(minimumM1, 'f', 2)).arg(QString::number(minimumM2, 'f', 2)).arg(photoVSys) << "<br />";
		}
	}

	oss << getPositionInfoString(core, flags);

	if ((flags&Distance) && s->plx && !isNan(s->plx) && !isInf(s->plx))
		oss << q_("Distance: %1 Light Years").arg((AU/(SPEED_OF_LIGHT*86400*365.25)) / (s->plx*((0.00001/3600)*(M_PI/180))), 0, 'f', 2) << "<br>";

	if (flags&Extra)
	{
		if (s->spInt)
			oss << q_("Spectral Type: %1").arg(StarMgr::convertToSpectralType(s->spInt)) << "<br />";

		if (s->plx)
			oss << q_("Parallax: %1\"").arg(0.00001*s->plx, 0, 'f', 5) << "<br />";

		if (vEpoch>0)
		{
			double vsEpoch = 2400000+vEpoch;
			if (ebsFlag)
				oss << q_("Epoch for minimum light: %1 JD").arg(QString::number(vsEpoch, 'f', 5)) << "<br />";
			else
				oss << q_("Epoch for maximum light: %1 JD").arg(QString::number(vsEpoch, 'f', 5)) << "<br />";
		}

		if (vPeriod>0)
			oss << q_("Period: %1 days").arg(vPeriod) << "<br />";

		if (vEpoch>0 && vPeriod>0)
		{
			// Calculate next minimum or maximum light
			double vsEpoch = 2400000+vEpoch;
			int npDelta = (core->getJDay()-vsEpoch)/vPeriod;
			double npDate = vsEpoch + ((npDelta+1)*vPeriod);
			QString nextDate = StelUtils::julianDayToISO8601String(npDate).replace("T", " ");
			if (ebsFlag)
				oss << q_("Next minimum light: %1 UTC").arg(nextDate) << "<br />";
			else
				oss << q_("Next maximum light: %1 UTC").arg(nextDate) << "<br />";
		}

		if (vMm>0)
		{
			if (ebsFlag)
				oss << q_("Duration of eclipse: %1%").arg(vMm) << "<br />";
			else
				oss << q_("Rising time: %1%").arg(vMm) << "<br />";
		}
	}

	StelObject::postProcessInfoString(str, flags);

	return str;
}

StelObjectP Star1::createStelObject(const SpecialZoneArray<Star1> *a,
									const SpecialZoneData<Star1> *z) const {
  return StelObjectP(new StarWrapper1(a,z,this), true);
}

StelObjectP Star2::createStelObject(const SpecialZoneArray<Star2> *a,
									const SpecialZoneData<Star2> *z) const {
  return StelObjectP(new StarWrapper2(a,z,this), true);
}

StelObjectP Star3::createStelObject(const SpecialZoneArray<Star3> *a,
									const SpecialZoneData<Star3> *z) const {
  return StelObjectP(new StarWrapper3(a,z,this), true);
}

