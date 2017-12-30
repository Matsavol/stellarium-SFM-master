/*
 * Stellarium
 * Copyright (C) 2002 Fabien Chereau
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

#ifndef _STELUTILS_HPP_
#define _STELUTILS_HPP_

#include "VecMath.hpp"

#include <QVariantMap>
#include <QDateTime>
#include <QString>

// astonomical unit (km)
#define AU 149597870.691
// Parsec (km)
#define PARSEC 30.857e12
// speed of light (km/sec)
#define SPEED_OF_LIGHT 299792.458

//! @namespace StelUtils contains general purpose utility functions.
namespace StelUtils
{
	//! Return the full name of stellarium, i.e. "stellarium 0.9.0"
	QString getApplicationName();

	//! Return the version of stellarium, i.e. "0.9.0"
	QString getApplicationVersion();

	//! Convert an angle in hms format to radian.
	//! @param h hour component
	//! @param m minute component
	//! @param s second component
	//! @return angle in radian
	double hmsToRad(const unsigned int h, const unsigned int m, const double s);

	//! Convert an angle in +-dms format to radian.
	//! @param d degree component
	//! @param m arcmin component
	//! @param s arcsec component
	//! @return angle in radian
	double dmsToRad(const int d, const unsigned int m, const double s);

	//! Convert an angle in radian to hms format.
	//! @param rad input angle in radian
	//! @param h hour component
	//! @param m minute component
	//! @param s second component
	void radToHms(double rad, unsigned int& h, unsigned int& m, double& s);

	//! Convert an angle in radian to +-dms format.
	//! @param rad input angle in radian
	//! @param sign true if positive, false otherwise
	//! @param d degree component
	//! @param m minute component
	//! @param s second component
	void radToDms(double rad, bool& sign, unsigned int& d, unsigned int& m, double& s);

	//! Convert an angle in radian to a hms formatted string.
	//! If the second, minute part is == 0, it is not output
	//! @param angle input angle in radian
	QString radToHmsStrAdapt(const double angle);

	//! Convert an angle in radian to a hms formatted string.
	//! @param angle input angle in radian
	//! @param decimal output decimal second value
	QString radToHmsStr(const double angle, const bool decimal=false);

	//! Convert an angle in radian to a dms formatted string.
	//! If the second, minute part is == 0, it is not output
	//! @param angle input angle in radian
	//! @param useD Define if letter "d" must be used instead of deg sign
	QString radToDmsStrAdapt(const double angle, const bool useD=false);

	//! Convert an angle in radian to a dms formatted string.
	//! @param angle input angle in radian
	//! @param useD Define if letter "d" must be used instead of deg sign
	//! @param decimal output decimal second value
	QString radToDmsStr(const double angle, const bool decimal=false, const bool useD=false);

	//! Convert a dms formatted string to an angle in radian
	//! @param dsm The input string
	double dmsStrToRad(const QString& s);

	//! Obtains a Vec3f from a string.
	//! @param s the string describing the Vector with the form "x,y,z"
	//! @return The corresponding vector
	//! @deprecated Use the >> operator from Vec3f class
	Vec3f strToVec3f(const QStringList& s);
	Vec3f strToVec3f(const QString& s);

	//! Converts a Vec3f to HTML color notation.
	//! @param v The vector
	//! @return The string in HTML color notation "#rrggbb".
	QString vec3fToHtmlColor(const Vec3f& v);

	//! Converts a color in HTML notation to a Vec3f.
	//! @param c The HTML spec color string
	Vec3f htmlColorToVec3f(const QString& c);

	//! Convert from spherical coordinates to Rectangular direction.
	//! @param lng longitude in radian
	//! @param lat latitude in radian
	//! @param v the resulting 3D unit vector
	void spheToRect(const double lng, const double lat, Vec3d& v);

	//! Convert from spherical coordinates to Rectangular direction.
	//! @param lng longitude in radian
	//! @param lat latitude in radian
	//! @param v the resulting 3D unti vector
	void spheToRect(const float lng, const float lat, Vec3f& v);

	//! Convert from spherical coordinates to Rectangular direction.
	//! @param lng double* to store longitude in radian
	//! @param lat double* to store latitude in radian
	//! @param v the input 3D vector
	void rectToSphe(double *lng, double *lat, const Vec3d& v);

	//! Convert from spherical coordinates to Rectangular direction.
	//! @param lng float* to store longitude in radian
	//! @param lat float* to store latitude in radian
	//! @param v the input 3D vector
	void rectToSphe(float *lng, float *lat, const Vec3d& v);

	//! Convert from spherical coordinates to Rectangular direction.
	//! @param lng float* to store longitude in radian
	//! @param lat float* to store latitude in radian
	//! @param v the input 3D vector
	void rectToSphe(float *lng, float *lat, const Vec3f& v);

	// GZ: some additions. I need those just for quick conversions for text display.
	//! Coordinate Transformation from equatorial to ecliptical
	void ctRadec2Ecl(const double raRad, const double decRad, const double eclRad, double *lambdaRad, double *betaRad);
	// GZ: done

	//! Convert a string longitude, latitude, RA or Declination angle
	//! to radians.
	//! @param str the angle in format something like these:
	//! - +53d  51'21.6"
	//! - +53d51'21.6"
	//! - -1d  10'31.8"
	//! - +46d6'31"
	//! - 50D46'0"N
	//! - 123D47'59"W
	//! - 123.567 N
	//! - 123.567W
	//! - -123.567
	//! - 12h 14m 6s
	//! The degree separator may be a degree symbol (\\xBA) in addition
	//! to a 'd' or 'D'.
	//! @return the angle in radians.
	//! Latitude: North are positive, South are negative.
	//! Longitude: East is positive, West is negative.
	//! Note: if there is a N, S, E or W suffix, any leading + or -
	//! characters are ignored.
	double getDecAngle(const QString& str);

	//! Check if a number is a power of 2.
	bool isPowerOfTwo(const int value);

	//! Return the first power of two bigger than the given value.
	int getBiggerPowerOfTwo(int value);

	//! Return the inverse sinus hyperbolic of z.
	double asinh(const double z);

	///////////////////////////////////////////////////
	// New Qt based General Calendar Functions.
	//! Make from julianDay a year, month, day for the Julian Date julianDay represents.
	void getDateFromJulianDay(const double julianDay, int *year, int *month, int *day);

	//! Make from julianDay an hour, minute, second.
	void getTimeFromJulianDay(const double julianDay, int *hour, int *minute, int *second);

	//! Parse an ISO8601 date string.
	//! Also handles negative and distant years.
	bool getDateTimeFromISO8601String(const QString& iso8601Date, int* y, int* m, int* d, int* h, int* min, float* s);
	
	//! Format the given Julian Day in (UTC) ISO8601 date string.
	//! Also handles negative and distant years.
	QString julianDayToISO8601String(const double jd);

	//! Return the Julian Date matching the ISO8601 date string.
	//! Also handles negative and distant years.
	double getJulianDayFromISO8601String(const QString& iso8601Date, bool* ok);
	
	//! Format the date and day-of-week per the format in fmt
	//! (see QDateTime::toString()). Uses the @b system locale, not
	//! the one set in Stellarium.
	//! @return QString representing the formatted date
	QString localeDateString(const int year, const int month, const int day, const int dayOfWeek, const QString fmt);

	//! Format the date and day-of-week per the @b system locale's
	//! QLocale::ShortFormat.
	//! @return QString representing the formatted date
	QString localeDateString(const int year, const int month, const int day, const int dayOfWeek);

	//! Get the current Julian Date from system time.
	//! @return the current Julian Date
	double getJDFromSystem();

	//! Convert a time of day to the fraction of a Julian Day.
	//! Note that a Julian Day starts at 12:00, not 0:00, and
	//! so 12:00 == 0.0 and 0:00 == 0.5
	double qTimeToJDFraction(const QTime& time);

	//! Convert a fraction of a Julian Day to a QTime
	QTime jdFractionToQTime(const double jd);

	//! Return number of hours offset from GMT, using Qt functions.
	float getGMTShiftFromQT(const double jd);

	//! Convert a QT QDateTime class to julian day.
	//! @param dateTime the UTC QDateTime to convert
	//! @result the matching decimal Julian Day
	double qDateTimeToJd(const QDateTime& dateTime);

	//! Convert a julian day to a QDateTime.
	//! @param jd to convert
	//! @result the matching UTC QDateTime
	QDateTime jdToQDateTime(const double& jd);

	//! Compute Julian day number from calendar date.
	//! Uses QDate functionality if possible, but also works for negative JD.
	//! Dates before 1582-10-15 are in the Julian Calendar.
	//! @param newjd pointer to JD
	//! @param y Calendar year.
	//! @param m month, 1=January ... 12=December
	//! @param d day
	//! @param h hour
	//! @param min minute
	//! @param s second
	//! @result true in all conceivable cases.
	bool getJDFromDate(double* newjd, const int y, const int m, const int d, const int h, const int min, const int s);

	int numberOfDaysInMonthInYear(const int month, const int year);
	bool changeDateTimeForRollover(int oy, int om, int od, int oh, int omin, int os,
					int* ry, int* rm, int* rd, int* rh, int* rmin, int* rs);

	//! Output a QVariantMap to qDebug().  Formats like a tree where there are nested objects.
	void debugQVariantMap(const QVariant& m, const QString& indent="", const QString& key="");


	/// Compute acos(x)
	//! The taylor serie is not accurate around x=1 and x=-1
	inline float fastAcos(const float x)
	{
		return static_cast<float>(M_PI_2) - (x + x*x*x * (1.f/6.f + x*x * (3.f/40.f + 5.f/112.f * x*x)) );
	}

	//! Compute exp(x) for small exponents x
	inline float fastExp(const float x)
	{
		return (x>=0)?
			(1.f + x*(1.f+ x/2.f*(1.f+ x/3.f*(1.f+x/4.f*(1.f+x/5.f))))):
				1.f / (1.f -x*(1.f -x/2.f*(1.f- x/3.f*(1.f-x/4.f*(1.f-x/5.f)))));
	}

	//! Get a night mode version of a color.  That is find the brightness of a color and set that in the
	//! red channel only
	inline Vec3f getNightColor(const Vec3f& dayColor)
	{
		float max = 0.0;
		for(int i=0; i<3; i++)
		{
			max = dayColor[i] > max ? dayColor[i] : max;
		}
		return Vec3f(max, 0, 0);
	}

	//! Calculate and getting sidereal period in days from semi-major axis (in AU)
	double calculateSiderealPeriod(const double SemiMajorAxis);

	QString hoursToHmsStr(const double hours);

	//! Get the number of seconds since program start.
	//!
	//! @note This is implemented in platform-specific ways to be as precise 
	//!       as possible, but there is a fallback for other platforms that 
	//!       might not be precise at all.
	//!       This is currently used e.g. to measure FPS, but it should never 
	//!       be used for critical functionality.
	long double secondsSinceStart();

	//! Get Delta-T estimation for a given date.
	//! Note that this method is valid for the year range:
	//! -1999 to +3000, outside of which "0" will be returned.
	// GZ: I don't see this returning 0. There is always a rough estimate beyond that.
	//! Implementation of algorithm by Espenak & Meeus (2006) for DeltaT computation
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByEspenakMeeus(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Schoch (1931) for DeltaT computation,
	//! outdated but may be useful for science-historical purposes.
	//! Source: Schoch, C. (1931). Die sekulare Accelaration des Mondes und der Sonne.
	//! Astronomische Abhandlungen, Ergnzungshefte zu den Astronomischen Nachrichten,
	//! Band 8, B2. Kiel.
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTBySchoch(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Clemence (1948) for DeltaT computation,
	//! outdated but may be useful for science-historical purposes.
	//! Source: On the system of astronomical constants.
	//! Clemence, G. M.
	//! Astronomical Journal, Vol. 53, p. 169
	//! 1948AJ.....53..169C [http://adsabs.harvard.edu/abs/1948AJ.....53..169C]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByClemence(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by IAU (1952) for DeltaT computation,
	//! outdated but may be useful for science-historical purposes.
	//! Source: Spencer Jones, H., "The Rotation of the Earth, and the Secular Accelerations of the Sun, Moon and Planets",
	//! Monthly Notices of the Royal Astronomical Society, 99 (1939), 541-558
	//! http://adsabs.harvard.edu/abs/1939MNRAS..99..541S
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByIAU(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Astronomical Ephemeris (1960) for DeltaT computation.
	//! Sources: Spencer Jones, H., "The Rotation of the Earth, and the Secular Accelerations of the Sun, Moon and Planets",
	//! Monthly Notices of the Royal Astronomical Society, 99 (1939), 541-558
	//! http://adsabs.harvard.edu/abs/1939MNRAS..99..541S
	//! or Explanatory Supplement to the Astr. Ephemeris, 1961, p.87.
	//! Also used by Mucke&Meeus, Canon of Solar Eclipses, Vienna 1983.
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByAstronomicalEphemeris(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Tuckerman (1962, 1964) & Goldstine (1973) for DeltaT computation
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByTuckermanGoldstine(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Muller & Stephenson (1975) for DeltaT computation.
	//! Source: The accelerations of the earth and moon from early astronomical observations
	//! Muller, P. M.; Stephenson, F. R.
	//! Growth rhythms and the history of the earth's rotation; Proceedings of the Interdisciplinary
	//! Winter Conference on Biological Clocks and Changes in the Earth's Rotation: Geophysical and
	//! Astronomical Consequences, Newcastle-upon-Tyne, England, January 8-10, 1974. (A76-18126 06-46)
	//! London, Wiley-Interscience, 1975, p. 459-533; Discussion, p. 534.
	//! 1975grhe.conf..459M [http://adsabs.harvard.edu/abs/1975grhe.conf..459M]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByMullerStephenson(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Stephenson (1978) for DeltaT computation.
	//! Source: Pre-Telescopic Astronomical Observations
	//! Stephenson, F. R.
	//! Tidal Friction and the Earth's Rotation, Proceedings of a Workshop, held in Bielefeld,
	//! September 26-30, 1977, Edited by P. Brosche, and J. Sundermann. Berlin: Springer-Verlag, 1978, p.5
	//! 1978tfer.conf....5S [http://adsabs.harvard.edu/abs/1978tfer.conf....5S]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByStephenson1978(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Stephenson (1997) for DeltaT computation.
	//! Source: Book "Historical Eclipses and Earth's Rotation" by F. R. Stephenson (1997)
	//! http://ebooks.cambridge.org/ebook.jsf?bid=CBO9780511525186
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByStephenson1997(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Schmadel & Zech (1979) for DeltaT computation.
	//! Outdated, but may be useful for science-historical purposes.
	//! Source: Polynomial approximations for the correction delta T E.T.-U.T. in the period 1800-1975
	//! Schmadel, L. D.; Zech, G.
	//! Acta Astronomica, vol. 29, no. 1, 1979, p. 101-104.
	//! 1979AcA....29..101S [http://adsabs.harvard.edu/abs/1979AcA....29..101S]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTBySchmadelZech1979(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Morrison & Stephenson (1982) for DeltaT computation
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByMorrisonStephenson1982(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Stephenson & Morrison (1984) for DeltaT computation
	//! Source: Long-term changes in the rotation of the earth - 700 B.C. to A.D. 1980.
	//! Stephenson, F. R.; Morrison, L. V.
	//! Philosophical Transactions, Series A (ISSN 0080-4614), vol. 313, no. 1524, Nov. 27, 1984, p. 47-70.
	//! 1984RSPTA.313...47S [http://adsabs.harvard.edu/abs/1984RSPTA.313...47S]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds or Zero if date outside years -391..1600
	double getDeltaTByStephensonMorrison1984(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Stephenson & Morrison (1995) for DeltaT computation
	//! Source: Long-Term Fluctuations in the Earth's Rotation: 700 BC to AD 1990.
	//! Stephenson, F. R.; Morrison, L. V.
	//! Philosophical Transactions: Physical Sciences and Engineering, Volume 351, Issue 1695, pp. 165-202
	//! 1995RSPTA.351..165S [http://adsabs.harvard.edu/abs/1995RSPTA.351..165S]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByStephensonMorrison1995(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Stephenson & Houlden (1986) for DeltaT computation
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds or 0 if year > 1600
	double getDeltaTByStephensonHoulden(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Espenak (1987, 1989) for DeltaT computation.
	//! This relation should not be used before around 1950 or after around 2100 (Espenak, pers. comm.).
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByEspenak(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Borkowski (1988) for DeltaT computation.
	//! Source: ELP 2000-85 and the dynamic time-universal time relation
	//! Borkowski, K. M.
	//! Astronomy and Astrophysics (ISSN 0004-6361), vol. 205, no. 1-2, Oct. 1988, p. L8-L10.
	//! 1988A&A...205L...8B [http://adsabs.harvard.edu/abs/1988A&A...205L...8B]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByBorkowski(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Schmadel & Zech (1988) for DeltaT computation.
	//! Source: Empirical Transformations from U.T. to E.T. for the Period 1800-1988
	//! Schmadel, L. D.; Zech, G.
	//! Astronomische Nachrichten 309, 219-221
	//! 1988AN....309..219S [http://adsabs.harvard.edu/abs/1988AN....309..219S]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTBySchmadelZech1988(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Chapront-Touzé & Chapront (1991) for DeltaT computation
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds or 0 if year not in -391..1600
	double getDeltaTByChaprontTouze(const double jDay);	

	//! Get Delta-T estimation for a given date.
	//! Implementation of the "historical" part of the algorithm by JPL Horizons for DeltaT computation.
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds or 0 if year not in -2999..1620 (!)
	double getDeltaTByJPLHorizons(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Morrison & Stephenson (2004, 2005) for DeltaT computation.
	//! Sources: Historical values of the Earth's clock error ΔT and the calculation of eclipses
	//! Morrison, L. V.; Stephenson, F. R.
	//! Journal for the History of Astronomy (ISSN 0021-8286), Vol. 35, Part 3, No. 120, p. 327 - 336 (2004)
	//! 2004JHA....35..327M [http://adsabs.harvard.edu/abs/2004JHA....35..327M]
	//! Addendum: Historical values of the Earth's clock error
	//! Morrison, L. V.; Stephenson, F. R.
	//! Journal for the History of Astronomy (ISSN 0021-8286), Vol. 36, Part 3, No. 124, p. 339 (2005)
	//! 2005JHA....36..339M [http://adsabs.harvard.edu/abs/2005JHA....36..339M]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByMorrisonStephenson2004(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Reijs (2006) for DeltaT computation
	//! Details: http://www.iol.ie/~geniet/eng/DeltaTeval.htm
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByReijs(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Chapront, Chapront-Touze & Francou (1997) & Meeus (1998) for DeltaT computation
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByChaprontMeeus(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Meeus & Simons (2000) for DeltaT computation.
	//! Source: Polynomial approximations to Delta T, 1620-2000 AD
	//! Meeus, J.; Simons, L.
	//! Journal of the British Astronomical Association, vol.110, no.6, 323
	//! 2000JBAA..110..323M [http://adsabs.harvard.edu/abs/2000JBAA..110..323M]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds or 0 if year not in 1620..2000
	double getDeltaTByMeeusSimons(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Montenbruck & Pfleger (2000) for DeltaT computation,
	//! a data fit through the table of values found in Meeus, Astronomical algorithms (1991).
	//! Book "Astronomy on the Personal Computer" by O. Montenbruck & T. Pfleger (4th ed., 2000)
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds or 0 if not 1825<=year<2005
	double getDeltaTByMontenbruckPfleger(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Reingold & Dershowitz (1997, 2001, 2002, 2007) for DeltaT computation.
	//! This is again mostly a data fit based on the table in Meeus, Astronomical Algorithms (1991).
	//! This is the version given in the 3rd edition (2007) which added the fit for 1700..1799 omitted from previous editions.
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByReingoldDershowitz(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Banjevic (2006) for DeltaT computation.
	//! Source: Ancient eclipses and dating the fall of Babylon
	//! Banjevic, B.
	//! Publications of the Astronomical Observatory of Belgrade, Vol. 80, p. 251-257 (2006)
	//! 2006POBeo..80..251B [http://adsabs.harvard.edu/abs/2006POBeo..80..251B]
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByBanjevic(const double jDay);

	//! Get Delta-T estimation for a given date.
	//! Implementation of algorithm by Islam, Sadiq & Qureshi (2008 + revisited 2013) for DeltaT computation.
	//! Source: Error Minimization of Polynomial Approximation of DeltaT
	//! Islam, S. & Sadiq, M. & Qureshi, M. S.
	//! Journal of Astrophysics & Astronomy, Vol. 29, p. 363–366 (2008)
	//! http://www.ias.ac.in/jaa/dec2008/JAA610.pdf
	//! Note: These polynomials are based on the uncorrected deltaT table from the Astronomical Almanac, thus
	//! ndot = -26.0 arcsec/cy^2. Meeus & Simons (2000) corrected the deltaT table for years before 1955.5 using
	//! ndot = -25.7376 arcsec/cy^2. Therefore the accuracies stated by Meeus & Simons are correct and cannot be
	//! compared with accuracies from Islam & Sadiq & Qureshi.
	//! @param jDay the date and time expressed as a julian day
	//! @return Delta-T in seconds
	double getDeltaTByIslamSadiqQureshi(const double jDay);

	//! Get Secular Acceleration estimation for a given year.
	//! Method described is here: http://eclipse.gsfc.nasa.gov/SEcat5/secular.html
	//! For adapting from -26 to -25.858, use -0.91072 * (-25.858 + 26.0) = -0.12932224
	//! For adapting from -26 to -23.895, use -0.91072 * (-23.895 + 26.0) = -1.9170656
	//! @param jDay the JD
	//! @param ndot value n-dot which use in the algorithm
	//! @return SecularAcceleration in seconds
	//! @note n-dot for secular acceleration of the Moon in ELP2000-82B is -23.8946 "/cy/cy
	double getMoonSecularAcceleration(const double jDay, const double ndot);

	//! Get the standard error (sigma) for the value of DeltaT
	//! @param jDay the JD
	//! @return sigma in seconds
	double getDeltaTStandardError(const double jDay);

	//! Uncompress gzip or zlib compressed data.
	QByteArray uncompress(const QByteArray& data);
}

#endif // _STELUTILS_HPP_
