/*
 * Copyright (C) 2009, 2012 Matthew Gates
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

#ifndef _SATELLITES_HPP_
#define _SATELLITES_HPP_

#include "StelObjectModule.hpp"
#include "Satellite.hpp"
#include "StelFader.hpp"
#include "StelLocation.hpp"

#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QUrl>
#include <QVariantMap>
#include <QByteArray>

class Planet;
class QNetworkAccessManager;
class QNetworkReply;
class QSettings;
class QTimer;

//! Data structure containing unvalidated TLE set as read from a TLE list file.
struct TleData
{
	//! NORAD catalog number, as extracted from the TLE set.
	QString id;
	//! Human readable name, as extracted from the TLE title line.
	QString name;
	QString first;
	QString second;
	//! Flag indicating whether this satellite should be added.
	//! See Satellites::autoAddEnabled.
	bool addThis;
};

typedef QList<TleData> TleDataList;
typedef QHash<QString, TleData> TleDataHash ;

//! TLE update source, used only internally for now.
struct TleSource
{
	TleSource() : reply(NULL), addNew(false) {;}
	~TleSource();
	//! URL from where the source list should be downloaded.
	QUrl url;
	//! The downloaded data, set after finishing download.
	QByteArray data;
	QNetworkReply* reply;
	//! Flag indicating whether new satellites in this list should be added.
	//! See Satellites::autoAddEnabled.
	bool addNew;
};


/*! @mainpage notitle
@section overview Plugin Overview

The %Satellites plugin displays the positions of artifical satellites in Earth
orbit based on a catalog of orbital data.

The Satellites class is the main class of the plug-in. It manages a collection
of Satellite objects and takes care of loading, saving and updating the
satellite catalog. It allows automatic updates from online sources and manages
a list of update file URLs.

To calculate satellite positions, the plugin uses an implementation of
the SGP4/SDP4 algorithms (J.L. Canales' gsat library).

@section satprop Satellite Properties

@subsection ident Name and identifiers
Each satellite has a name. It's displayed as a label of the satellite hint and in the list of satellites. Names are not unique though, so they are used only
for presentation purposes.

In the @ref satcat satellites are uniquely identified by their NORAD number, which is encoded in TLEs.

@subsection groups Grouping
A satellite can belong to one or more groups such as "amateur", "geostationary" or "navigation". They have no other function but to help the user organize the satellite collection.

Group names are arbitrary strings defined in the @ref satcat for each satellite and are more similar to the concept of "tags" than a hierarchical grouping. A satellite may not belong to any group at all.

By convention, group names are in lowercase. The GUI translates some of the groups used in the default catalog.

@section satcat Satellite Catalog
The satellite catalog is stored on the disk in [JSON](http://www.json.org/)
format, in a file named "satellites.json". A default copy is embedded in the
plug-in at compile time. A working copy is kept in the user data directory.

@section config Configuration
The plug-ins' configuration data is stored in Stellarium's main configuration
file.
*/


//! @class Satellites
//! Main class of the %Satellites plugin.
//! @author Matthew Gates
//! @author Bogdan Marinov
class Satellites : public StelObjectModule
{
	Q_OBJECT
	Q_PROPERTY(bool displayed
	           READ getFlagDisplayed
	           WRITE setFlagDisplayed)
	Q_PROPERTY(bool labelsVisible
	           READ getFlagLabels
	           WRITE setFlagLabels)
	Q_PROPERTY(bool autoAddEnabled
	           READ isAutoAddEnabled
	           WRITE enableAutoAdd
	           NOTIFY settingsChanged)
	Q_PROPERTY(bool autoRemoveEnabled
	           READ isAutoRemoveEnabled
	           WRITE enableAutoRemove
	           NOTIFY settingsChanged)
	Q_PROPERTY(bool hintsVisible
	           READ getFlagHintsVisible
	           WRITE setFlagHintsVisible)
	
public:
	//! @enum UpdateState
	//! Used for keeping track of the download/update status
	enum UpdateState
	{
		Updating,             //!< Update in progress
		CompleteNoUpdates,    //!< Update completed, there we no updates
		CompleteUpdates,      //!< Update completed, there were updates
		DownloadError,        //!< Error during download phase
		OtherError            //!< Other error
	};

	//! Flags used to filter the satellites list according to their status.
	enum Status
	{
		Visible,
		NotVisible,
		Both,
		NewlyAdded,
		OrbitError
	};

	Satellites();
	virtual ~Satellites();

	///////////////////////////////////////////////////////////////////////////
	// Methods defined in the StelModule class
	virtual void init();
	virtual void deinit();
	virtual void update(double deltaTime);
	virtual void draw(StelCore* core);
	virtual void drawPointer(StelCore* core, StelPainter& painter);
	virtual double getCallOrder(StelModuleActionName actionName) const;

	///////////////////////////////////////////////////////////////////////////
	// Methods defined in StelObjectManager class
	//! Used to get a list of objects which are near to some position.
	//! @param v a vector representing the position in th sky around which to search for nebulae.
	//! @param limitFov the field of view around the position v in which to search for satellites.
	//! @param core the StelCore to use for computations.
	//! @return an list containing the satellites located inside the limitFov circle around position v.
	virtual QList<StelObjectP> searchAround(const Vec3d& v, double limitFov, const StelCore* core) const;

	//! Return the matching satellite object's pointer if exists or NULL.
	//! @param nameI18n The case in-sensistive satellite name
	virtual StelObjectP searchByNameI18n(const QString& nameI18n) const;

	//! Return the matching satellite if exists or NULL.
	//! @param name The case in-sensistive standard program name
	virtual StelObjectP searchByName(const QString& name) const;
	
	//! Return the satellite with the given catalog number.
	//! Used as a helper function by searchByName() and
	//! searchByNameI18n().
	//! @param noradNumber search string in the format "NORAD XXXX".
	//! @returns a null pointer if no such satellite is found.
	StelObjectP searchByNoradNumber(const QString& noradNumber) const;

	//! Find and return the list of at most maxNbItem objects auto-completing the passed object I18n name.
	//! @param objPrefix the case insensitive first letters of the searched object
	//! @param maxNbItem the maximum number of returned object names
	//! @param useStartOfWords the autofill mode for returned objects names
	//! @return a list of matching object name by order of relevance, or an empty list if nothing match
	virtual QStringList listMatchingObjectsI18n(const QString& objPrefix, int maxNbItem=5, bool useStartOfWords=false) const;

	//! Find and return the list of at most maxNbItem objects auto-completing the passed object English name.
	//! @param objPrefix the case insensitive first letters of the searched object
	//! @param maxNbItem the maximum number of returned object names
	//! @param useStartOfWords the autofill mode for returned objects names
	//! @return a list of matching object name by order of relevance, or an empty list if nothing match
	virtual QStringList listMatchingObjects(const QString& objPrefix, int maxNbItem=5, bool useStartOfWords=false) const;

	virtual QStringList listAllObjects(bool inEnglish) const;

	virtual QString getName() const { return "Satellites"; }

	//! Implment this to tell the main Stellarium GUi that there is a GUI element to configure this
	//! plugin. 
	/// virtual bool configureGui(bool show=true);

	//! Set up the plugin with default values.  This means clearing out the Satellites section in the
	//! main config.ini (if one already exists), and populating it with default values.  It also 
	//! creates the default satellites.json file from the resource embedded in the plugin lib/dll file.
	void restoreDefaults(void);

	//! Read (or re-read) the plugin's settings from the configuration file.
	//! This will be called from init() and also when restoring defaults
	//! (i.e. from the configuration dialog / restore defaults button).
	void loadSettings();

	//! Save the plugin's settings to the main configuration file.
	void saveSettings();

	//! Get the groups used in the currently loaded satellite collection.
	//! See @ref groups for details. Use getGroupIdList() if you need a list.
	QSet<QString> getGroups() const;
	//! Get a sorted list of group names.
	//! See @ref groups for details. Use getGroups() if you don't need a list.
	QStringList getGroupIdList() const;
	//! Add this group to the global list.
	void addGroup(const QString& groupId);

	//! get satellite objects filtered by group.  If an empty string is used for the
	//! group name, return all satallites
	QHash<QString,QString> getSatellites(const QString& group=QString(), Status vis=Both);
	//! Get a model representing the list of satellites.
    // SatellitesListModel* getSatellitesListModel();

	//! Get a satellite object by its identifier (i.e. NORAD number).
	SatelliteP getById(const QString& id);
	
	//! Returns a list of all satellite IDs.
	QStringList listAllIds();
	
	//! Add to the current collection the satellites described by the data list.
	//! The changes are not saved to file.
	//! Calls add(TleData).
	void add(const TleDataList& newSatellites);
	
	//! Remove the selected satellites.
	//! The changes are not saved to file.
	void remove(const QStringList& idList);

	//! get whether or not the plugin will try to update TLE data from the internet
	//! @return true if updates are set to be done, false otherwise
	bool getUpdatesEnabled(void) {return updatesEnabled;}

	//! get the date and time the TLE elements were updated
	QDateTime getLastUpdate(void) {return lastUpdate;}

	//! get the update frequency in hours
	int getUpdateFrequencyHours(void) {return updateFrequencyHours;}

	//! get the number of seconds till the next update
	int getSecondsToUpdate(void);

	//! get the update frequency in hours
	//void setUpdateFrequencyHours(int hours);

	//! Get the current updateState
	UpdateState getUpdateState(void) {return updateState;}

	//! Get a list of URLs which are sources of TLE data.
	//! @returns a list of URL strings, some with prefixes - see #updateUrls
	//! for details.
	QStringList getTleSources(void) {return updateUrls;}

	//! Set the list of URLs which are sources of TLE data.
	//! In addition to replacing the current list of sources, it also
	//! saves them to the configuration file. Allows marking sources for
	//! auto-addition by adding a prefix to the URL string.
	//! @see updateUrls
	//! @param tleSources a list of valid URLs (http://, ftp://, file://),
	//! allowed prefixes are "0,", "1," or no prefix.
	void setTleSources(QStringList tleSources);
	
	//! Saves the current list of update URLs to the configuration file.
	void saveTleSources(const QStringList& urls);
	
	//! Reads update file(s) in celestrak's .txt format, and updates
	//! the TLE elements for exisiting satellites from them.
	//! Indirectly emits signals updateStateChanged() and tleUpdateComplete(),
	//! as it calls updateSatellites().
	//! See updateFromOnlineSources() for the other kind of update operation.
	//! @param paths a list of paths to update files
	//! @param deleteFiles if set, the update files are deleted after
	//!        they are used, else they are left alone
	void updateFromFiles(QStringList paths, bool deleteFiles=false);
	
	//! Updates the loaded satellite collection from the provided data.
	//! Worker function called by updateFromFiles() and saveDownloadedUpdate().
	//! (Respecitvely, user-initiated update from file(s) and user- or auto-
	//! initiated update from online source(s).)
	//! Emits updateStateChanged() and tleUpdateComplete().
	//! @note Instead of splitting this method off updateFromFiles() and passing
	//! the auto-add flag through data structures, another possiblity was to
	//! modify updateFromFiles to use the same prefix trick (adding "1,"
	//! to file paths). I decided against it because I thought it would be more
	//! complex. :) --BM
	//! @param[in,out] newTleSets a hash with satellite IDs as keys; it's
	//! modified by the method!
	void updateSatellites(TleDataHash& newTleSets);
	
	//! Reads a TLE list from a file to the supplied hash.
	//! If an entry with the same ID exists in the given hash, its contents
	//! are overwritten with the new values.
	//! @param data the content of the text file.
	//! @param[in,out] tleList a hash with satellite IDs as keys.
	//! @param[in] addFlagValue value to be set to TleData::addThis for all.
	//! @todo If this can accept a QIODevice, it will be able to read directly
	//! QNetworkReply-s... --BM
	static void parseTleFile(const QByteArray& data,
	                         TleDataHash& tleList,
	                         bool addFlagValue = false);

	//! Reads qs.mag file and its parsing for getting id and standard magnitude
	//! for satellites.
	//! @note We are having permissions for use this file from Mike McCants.
	//! @param name of file
	void parseQSMagFile(QString qsMagFile);
	
	bool getFlagDisplayed() {return fader;}
	//! get the label font size.
	//! @return the pixel size of the font
	int getLabelFontSize() {return labelFont.pixelSize();}
	bool getFlagLabels();
	bool getFlagHintsVisible();
	//! Get the current status of the orbit line rendering flag.
	bool getOrbitLinesFlag();
	bool isAutoAddEnabled() const { return autoAddEnabled; }
	bool isAutoRemoveEnabled() const { return autoRemoveEnabled; }	

signals:
	//! Emitted when some of the plugin settings have been changed.
	//! Used to communicate with the configuration window.
	void settingsChanged();
	
	//! emitted when the update status changes, e.g. when 
	//! an update starts, completes and so on.  Note that
	//! on completion of an update, tleUpdateComplete is also
	//! emitted with the number of updates done.
	//! @param state the new update state.
	void updateStateChanged(Satellites::UpdateState state);

	//! Emitted after an update has run.
	//! @param updated the number of updated satellites;
	//! @param total the total number of satellites in the catalog;
	//! @param added the number of newly added satellites;
	//! @param missing the number of satellites that were not found in the
	//! update source(s) (and were removed, if autoRemoveEnabled is set).
	void tleUpdateComplete(int updated, int total, int added, int missing);

public slots:
	// FIXME: Put back the getter functions - for scripts? --BM
	
	//! Set whether the plugin will try to download updates from the Internet.
	//! Emits settingsChanged() if the value changes.
	//! @param b if true, updates will be enabled, else they will be disabled.
	void enableInternetUpdates(bool enabled = true);
	
	//! Emits settingsChanged() if the value changes.
	void enableAutoAdd(bool enabled = true);
	
	//! Emits settingsChanged() if the value changes.
	void enableAutoRemove(bool enabled = true);
	
	//! Set whether satellitew should be displayed.
	//! Emits settingsChanged() if the value changes.
	void setFlagDisplayed(bool b);
	
	//! Set whether text labels should be displayed next to satellites.
	//! Emits settingsChanged() if the value changes.
	//! @todo Decide how to sync with "actionShow_Satellite_Labels".
	void setFlagLabels(bool b);

	//! Emits settingsChanged() if the value changes.
	void setFlagHintsVisible(bool b);
	
	//! set the label font size.
	//! @param size the pixel size of the font
	//! Emits settingsChanged() if the value changes.
	void setLabelFontSize(int size);
	
	//! Set the Internet update frequency.
	//! Emits settingsChanged() if the value changes.
	void setUpdateFrequencyHours(int hours);
	
	//! Start an Internet update.
	//! This method starts the process of an Internet update: it tries to
	//! download TLE lists from online recources and then use them to 
	//! update the orbital data (and names, etc.) of the included satellites.
	//! This only initialized the download. The rest of the work is done by
	//! saveDownloadedUpdate() and updateSatellites().
	//! Update sources are described in updateUrls (see for accessor details).
	//! If autoAddEnabled is true when this function is called, new satellites
	//! in the chosen update sources will be added during the update. 
	//! If autoRemoveEnabled is true when this function is called, any existing
	//! satellite that can't be found in the downloaded update lists will be
	//! removed.
	//! See updateFromFiles() for the other type of update operation.
	void updateFromOnlineSources();

	//! Choose whether or not to draw orbit lines.  Each satellite has its own setting
	//! as well, but this can be used to turn on/off all those satellites which elect to
	//! have orbit lines all in one go.
	//! @param b - true to turn on orbit lines, false to turn off
	void setOrbitLinesFlag(bool b);

	void recalculateOrbitLines(void);

	//! Display a message on the screen for a few seconds.
	//! This is used for plugin-specific warnings and such.
	void displayMessage(const QString& message, const QString hexColor="#999999");
	//! Hide all messages.
	void hideMessages();

	//! Save the current satellite catalog to disk.
	void saveCatalog(QString path=QString());

private slots:

private:
	//! Add to the current collection the satellite described by the data.
	//! @warning Use only in other methods! Does not update satelliteListModel!
	//! @todo This probably could be done easier if Satellite had a constructor
	//! accepting TleData... --BM
	//! @returns true if the addition was successful.
	bool add(const TleData& tleData);
	
	//! Delete Satellites section in main config.ini, then create with default values.
	void restoreDefaultSettings();
	//! Replace the catalog file with the default one.
	void restoreDefaultCatalog();
	//! Load the satellites from the catalog file.
	//! Removes existing satellites first if there are any.
	//! this will be done once at init, and also if the defaults are reset.
	void loadCatalog();
	//! Creates a backup of the satellites.json file called satellites.json.old
	//! @param deleteOriginal if true, the original file is removed, else not
	//! @return true on OK, false on failure
	bool backupCatalog(bool deleteOriginal=false);
	//! Read the version number from the "creator" value in the catalog file.
	//! @return version string, e.g. "0.6.1"
	const QString readCatalogVersion();
	//! Replace the qs.mag file with the default one.
	void restoreDefaultQSMagFile();

	//! Checks valid range dates of life of satellites
	bool isValidRangeDates() const;

	//! Save a structure representing a satellite catalog to a JSON file.
	//! If no path is specified, catalogPath is used.
	bool saveDataMap(QString path=QString());
	//! Parse a satellite catalog structure into internal satellite data.
	void setDataMap(const QVariantMap& map);
	
	//! Sets lastUpdate to the current date/time and saves it to the settings.
	void markLastUpdate();

	//! Check format of the catalog of satellites
	//! @return valid boolean, e.g. "true"
	bool checkJsonFileFormat();
	
	//! A fake method for strings marked for translation.
	//! Use it instead of translations.h for N_() strings, except perhaps for
	//! keyboard action descriptions. (It's better for them to be in a single
	//! place.)
	static void translations();

	//! Path to the qs.mag file.
	QString qsMagFilePath;
	//! Path to the satellite catalog file.
	QString catalogPath;
	//! Plug-in data directory.
	//! Intialized by init(). Contains the catalog file (satellites.json),
	//! temporary TLE lists downloaded during an online update, or whatever
	//! other modifiable files the plug-in needs.
	QDir dataDir;
	
	QList<SatelliteP> satellites;
	
	QHash<QString, double> qsMagList;
	//! Union of the groups used by all loaded satellites - see @ref groups.
	//! For simplicity, it can only grow until the plug-in is unloaded -
	//! a group is not removed even if there are no more satellites tagged with
	//! it.
	QSet<QString> groups;
	
	LinearFader fader;
	LinearFader hintsFader;
	StelTextureSP texPointer;
	
	// FIXME: Possible bug with the Solar System recreated by the SSEditor.
	QSharedPointer<Planet> earth;
	Vec3f defaultHintColor;
	Vec3f defaultOrbitColor;
	QFont labelFont;
	
	//! @name Updater module
	//@{
	UpdateState updateState;
	//! List of TLE source lists for automatic updates.
	//! Use getTleSources() to get the value, setTleSources() to set it (and
	//! save it to configuration).
	//! URLs prefixed with "1," indicate that satellites from this source will
	//! be auto-added if autoAddEnabled is true. URLs prefixed with "0," or
	//! without a prefix are used only to update existing satellites. This
	//! system was introduced to avoid using a custom type as a parameter in
	//! setTleSources(), which in turn allows it to be used in scripts.
	QStringList updateUrls;
	//! Temporary stores update URLs and files during an online update.
	//! In use only between updateFromOnlineSources() and the final call to
	//! saveDownloadedUpdate(). @b DO @b NOT use elsewhere!
	//! As a side effect it prevents problems if the user calls
	//! setTleSources() while an update is in progress.
	QList<TleSource> updateSources;
	// class StelProgressController* progressBar;
	int numberDownloadsComplete;
	QTimer* updateTimer;
	//! Flag enabling automatic Internet updates.
	bool updatesEnabled;
	//! Flag enabling the automatic addition of new satellites on update.
	//! This will apply only for the selected update sources.
	bool autoAddEnabled;
	//! Flag enabling the automatic removal of missing satellites on update.
	bool autoRemoveEnabled;
	QDateTime lastUpdate;
	int updateFrequencyHours;
	//@}
	
	//! @name Screen message infrastructure
	//@{
	QTimer* messageTimer;
	QList<int> messageIDs;
	//@}

private slots:
	//! check to see if an update is required.  This is called periodically by a timer
	//! if the last update was longer than updateFrequencyHours ago then the update is
	//! done.
	void checkForUpdate(void);
	//! Save the downloaded file and finish the update if it's the last one.
	//! Calls updateSatellites() and indirectly emits updateStateChanged()
	//! and updateFinished().
	//! Ends the update process started with updateFromOnlineSources().
	//! @todo I've kept the previous behaviour, which was to save the update to
	//! temporary files and then read them. If we give up on the idea to
	//! re-use them later when adding manually satellites, parseTleFile()
	//! can be modified to read directly form QNetworkReply-s. --BM
	void saveDownloadedUpdate();
	void updateObserverLocation(StelLocation loc);

};

#endif /*_SATELLITES_HPP_*/

