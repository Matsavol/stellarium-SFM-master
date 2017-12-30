/*
 * Stellarium
 * Copyright (C) 2007 Fabien Chereau
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

#ifndef _STELMAINGRAPHICSVIEW_HPP_
#define _STELMAINGRAPHICSVIEW_HPP_

#ifdef USE_QUICKVIEW
#include "StelQuickView.hpp"
typedef StelQuickView StelMainView;
#else

#include <QDeclarativeView>
#include <QCoreApplication>
#include <QEventLoop>

class QGLWidget;
class QMoveEvent;
class QResizeEvent;
class StelGuiBase;
class StelQGLWidget;
class QMoveEvent;

//! @class StelMainView
//! Reimplement a QGraphicsView for Stellarium.
//! It is the class creating the singleton GL Widget, the main StelApp instance as well as the main GUI.
class StelMainView : public QDeclarativeView
{
	friend class StelGuiItem;
	Q_OBJECT
	Q_PROPERTY(bool fullScreen READ isFullScreen WRITE setFullScreen)

public:
	StelMainView(QWidget* parent = NULL);
	virtual ~StelMainView();

	//! Start the main initialization of Stellarium
	void init(class QSettings* conf);
	void deinit();

	//! Set the application title for the current language.
	//! This is useful for e.g. chinese.
	void initTitleI18n();

	//! Get the StelMainView singleton instance.
	static StelMainView& getInstance() {Q_ASSERT(singleton); return *singleton;}

	//! Delete openGL textures (to call before the GLContext disappears)
	void deinitGL();
	//! Return focus to the sky item.  To be used when we close a dialog.
	void focusSky();
	//! Return the parent gui widget, this should be used as parent to all
	//! the StelDialog instances.
	QGraphicsWidget* getGuiWidget() const {return guiWidget;}
public slots:

	//!	Set whether fullscreen is activated or not
	void setFullScreen(bool);

	///////////////////////////////////////////////////////////////////////////
	// Specific methods
	//! Save a screen shot.
	//! The format of the file, and hence the filename extension
	//! depends on the architecture and build type.
	//! @arg filePrefix changes the beginning of the file name
	//! @arg shotDir changes the directory where the screenshot is saved
	//! If shotDir is "" then StelFileMgr::getScreenshotDir() will be used
	void saveScreenShot(const QString& filePrefix="stellarium-", const QString& saveDir="");

	//! Get whether colors are inverted when saving screenshot
	bool getFlagInvertScreenShotColors() const {return flagInvertScreenShotColors;}
	//! Set whether colors should be inverted when saving screenshot
	void setFlagInvertScreenShotColors(bool b) {flagInvertScreenShotColors=b;}

	//! Get the state of the mouse cursor timeout flag
	bool getFlagCursorTimeout() {return flagCursorTimeout;}
	//! Get the mouse cursor timeout in seconds
	float getCursorTimeout() const {return cursorTimeout;}
	//! Get the state of the mouse cursor timeout flag
	void setFlagCursorTimeout(bool b) {flagCursorTimeout=b;}
	//! Set the mouse cursor timeout in seconds
	void setCursorTimeout(float t) {cursorTimeout=t;}

	//! Set the minimum frames per second. Usually this minimum will be switched to after there are no
	//! user events for some seconds to save power. However, if can be useful to set this to a high
	//! value to improve playing smoothness in scripts.
	//! @param m the new minimum fps setting.
	void setMinFps(float m) {minfps=m; minFpsChanged();}
	//! Get the current minimum frames per second.
	float getMinFps() {return minfps;}
	//! Set the maximum frames per second.
	//! @param m the new maximum fps setting.
	void setMaxFps(float m) {maxfps = m;}
	//! Get the current maximum frames per second.
	float getMaxFps() {return maxfps;}

	//! Updates the scene and process all events
	void updateScene() {
		scene()->update();
	}

protected:
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void keyPressEvent(QKeyEvent* event);
	virtual void keyReleaseEvent(QKeyEvent* event);
	virtual void wheelEvent(QWheelEvent* wheelEvent);
	virtual void moveEvent(QMoveEvent* event);

	//! Update the mouse pointer state and schedule next redraw.
	//! This method is called automatically by Qt.
	virtual void drawBackground(QPainter* painter, const QRectF &rect);

signals:
	//! emitted when saveScreenShot is requested with saveScreenShot().
	//! doScreenshot() does the actual work (it has to do it in the main
	//! thread, where as saveScreenShot() might get called from another one.
	void screenshotRequested(void);

private slots:
	// Do the actual screenshot generation in the main thread with this method.
	void doScreenshot(void);

	void minFpsChanged();

private:
	//! Start the display loop
	void startMainLoop();

	//! The StelMainView singleton
	static StelMainView* singleton;

	//! This is created by the StelGuiItem, but need to be publicly
	//! accessible so that StelDialog instances can reparent to it.
	QGraphicsWidget *guiWidget;

	//! The openGL window
	StelQGLWidget* glWidget;
	StelGuiBase* gui;
	class StelApp* stelApp;

	bool flagInvertScreenShotColors;

	QString screenShotPrefix;
	QString screenShotDir;

	// Number of second before the mouse cursor disappears
	float cursorTimeout;
	bool flagCursorTimeout;

	//! Notify that an event was handled by the program and therefore the
	//! FPS should be maximized for a couple of seconds.
	void thereWasAnEvent();

	double lastEventTimeSec;

	QTimer* minFpsTimer;
	//! The minimum desired frame rate in frame per second.
	float minfps;
	//! The maximum desired frame rate in frame per second.
	float maxfps;
};

#endif // USE_QUICKVIEW
#endif // _STELMAINGRAPHICSVIEW_HPP_
