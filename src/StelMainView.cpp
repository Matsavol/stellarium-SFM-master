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

#ifndef USE_QUICKVIEW

#include "StelMainView.hpp"
#include "StelApp.hpp"
#include "StelCore.hpp"
#include "StelFileMgr.hpp"
#include "StelProjector.hpp"
#include "StelModuleMgr.hpp"
#include "StelPainter.hpp"
#include "StelGuiBase.hpp"
#include "StelTranslator.hpp"
#include "StelUtils.hpp"
#include "StelActionMgr.hpp"

#include <QDeclarativeItem>
#include <QDebug>
#include <QDir>
#include <QGLWidget>
#include <QGuiApplication>
#include <QFileInfo>
#include <QIcon>
#include <QMoveEvent>
#include <QPluginLoader>
#include <QScreen>
#include <QSettings>
#include <QtPlugin>
#include <QThread>
#include <QTimer>
#include <QWidget>
#include <QWindow>
#include <QDeclarativeContext>

#include <clocale>

// Initialize static variables
StelMainView* StelMainView::singleton = NULL;

//! Render Stellarium sky. 
class StelSkyItem : public QDeclarativeItem
{
public:
	StelSkyItem(QDeclarativeItem* parent = NULL);
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void wheelEvent(QGraphicsSceneWheelEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
private:
	double previousPaintTime;
	void onSizeChanged();
};

//! Initialize and render Stellarium gui.
class StelGuiItem : public QDeclarativeItem
{
public:
	StelGuiItem(QDeclarativeItem* parent = NULL);
private:
	QGraphicsWidget *widget;
	void onSizeChanged();
};

StelSkyItem::StelSkyItem(QDeclarativeItem* parent)
{
	Q_UNUSED(parent);
	setObjectName("SkyItem");
	setFlag(QGraphicsItem::ItemHasNoContents, false);
	setAcceptHoverEvents(true);
	setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton | Qt::MiddleButton);
	connect(this, &StelSkyItem::widthChanged, this, &StelSkyItem::onSizeChanged);
	connect(this, &StelSkyItem::heightChanged, this, &StelSkyItem::onSizeChanged);
	previousPaintTime = StelApp::getTotalRunTime();
	setFocus(true);
}

void StelSkyItem::onSizeChanged()
{
	StelApp::getInstance().glWindowHasBeenResized(x(), y(), width(), height());
}

void StelSkyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	const double now = StelApp::getTotalRunTime();
	double dt = now - previousPaintTime;
	previousPaintTime = now;

	painter->beginNativePainting();
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	StelApp::getInstance().update(dt);
	StelApp::getInstance().draw();

	painter->endNativePainting();
	update();
}

void StelSkyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QPointF pos = event->scenePos();
	// XXX: to reintroduce
	//distortPos(&pos);
	pos.setY(height() - 1 - pos.y());
	QMouseEvent newEvent(QEvent::MouseButtonPress,
								QPoint(pos.x(), pos.y()),
								event->button(),
								event->buttons(),
								event->modifiers());
	StelApp::getInstance().handleClick(&newEvent);
}

void StelSkyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	QPointF pos = event->scenePos();
	// XXX: to reintroduce
	// distortPos(&pos);
	pos.setY(height() - 1 - pos.y());
	QMouseEvent newEvent(QEvent::MouseButtonRelease,
								QPoint(pos.x(), pos.y()),
								event->button(),
								event->buttons(),
								event->modifiers());
	StelApp::getInstance().handleClick(&newEvent);
}

void StelSkyItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QPointF pos = event->scenePos();
	// XXX: to reintroduce
	// distortPos(&pos);
	pos.setY(height() - 1 - pos.y());
	StelApp::getInstance().handleMove(pos.x(), pos.y(), event->buttons());
}

void StelSkyItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
	QPointF pos = event->scenePos();
	// XXX: to reintroduce
	// distortPos(&pos);
	pos.setY(height() - 1 - pos.y());
	QWheelEvent newEvent(QPoint(pos.x(),pos.y()), event->delta(), event->buttons(), event->modifiers(), event->orientation());
	StelApp::getInstance().handleWheel(&newEvent);
}

void StelSkyItem::keyPressEvent(QKeyEvent* event)
{
	StelApp::getInstance().handleKeys(event);
}

void StelSkyItem::keyReleaseEvent(QKeyEvent* event)
{
	StelApp::getInstance().handleKeys(event);
}


StelGuiItem::StelGuiItem(QDeclarativeItem* parent) : QDeclarativeItem(parent)
{
	connect(this, &StelGuiItem::widthChanged, this, &StelGuiItem::onSizeChanged);
	connect(this, &StelGuiItem::heightChanged, this, &StelGuiItem::onSizeChanged);
	widget = new QGraphicsWidget(this);
	StelMainView::getInstance().guiWidget = widget;
	StelApp::getInstance().getGui()->init(widget);
}

void StelGuiItem::onSizeChanged()
{
	// I whish I could find a way to let Qt automatically resize the widget
	// when the QDeclarativeItem size changes.
	widget->setGeometry(0, 0, width(), height());
	StelApp::getInstance().getGui()->forceRefreshGui();
}

class StelQGLWidget : public QGLWidget
{
public:
	StelQGLWidget(QGLContext* ctx, QWidget* parent) : QGLWidget(ctx, parent)
	{
		setAttribute(Qt::WA_PaintOnScreen);
		setAttribute(Qt::WA_NoSystemBackground);
		setAttribute(Qt::WA_OpaquePaintEvent);
	}

protected:
	virtual void initializeGL()
	{
		qDebug() << "OpenGL supported version: " << QString((char*)glGetString(GL_VERSION));

		QGLWidget::initializeGL();

		if (!format().stencil())
			qWarning("Could not get stencil buffer; results will be suboptimal");
		if (!format().depth())
			qWarning("Could not get depth buffer; results will be suboptimal");
		if (!format().doubleBuffer())
			qWarning("Could not get double buffer; results will be suboptimal");
	}

};

StelMainView::StelMainView(QWidget* parent)
	: QDeclarativeView(parent), gui(NULL),
	  flagInvertScreenShotColors(false),
	  screenShotPrefix("stellarium-"),
	  screenShotDir(""),
	  cursorTimeout(-1.f), flagCursorTimeout(false), minFpsTimer(NULL), maxfps(10000.f)
{
	StelApp::initStatic();
	
	// Can't create 2 StelMainView instances
	Q_ASSERT(!singleton);
	singleton = this;

	setWindowIcon(QIcon(":/mainWindow/icon.bmp"));
	initTitleI18n();
	setObjectName("Mainview");

	// Allows for precise FPS control
	setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
	setFrameShape(QFrame::NoFrame);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFocusPolicy(Qt::StrongFocus);
	connect(this, SIGNAL(screenshotRequested()), this, SLOT(doScreenshot()));

	lastEventTimeSec = 0;

	// Create an openGL viewport
	QGLFormat glFormat(QGL::StencilBuffer | QGL::DepthBuffer | QGL::DoubleBuffer);
	glWidget = new StelQGLWidget(new QGLContext(glFormat), this);
	setViewport(glWidget);

	// Workaround (see Bug #940638) Although we have already explicitly set
	// LC_NUMERIC to "C" in main.cpp there seems to be a bug in OpenGL where
	// it will silently reset LC_NUMERIC to the value of LC_ALL during OpenGL
	// initialization. This has been observed on Ubuntu 11.10 under certain
	// circumstances, so here we set it again just to be on the safe side.
	setlocale(LC_NUMERIC, "C");
	// End workaround
}

void StelMainView::focusSky() {
	StelMainView::getInstance().scene()->setActiveWindow(0);
	QGraphicsObject* skyItem = rootObject()->findChild<QGraphicsObject*>("SkyItem");
	Q_ASSERT(skyItem);
	skyItem->setFocus();
}

StelMainView::~StelMainView()
{
	StelApp::deinitStatic();
}

void StelMainView::init(QSettings* conf)
{
	// Look for a static GUI plugins.
	foreach (QObject *plugin, QPluginLoader::staticInstances())
	{
		StelGuiPluginInterface* pluginInterface = qobject_cast<StelGuiPluginInterface*>(plugin);
		if (pluginInterface)
		{
			gui = pluginInterface->getStelGuiBase();
		}
		break;
	}
	Q_ASSERT(gui);

	Q_ASSERT(glWidget->isValid());
	glWidget->makeCurrent();
	
	stelApp= new StelApp();
	stelApp->setGui(gui);
	stelApp->init(conf);
	StelActionMgr *actionMgr = stelApp->getStelActionManager();
	actionMgr->addAction("actionSave_Screenshot_Global", N_("Miscellaneous"), N_("Save screenshot"), this, "saveScreenShot()", "Ctrl+S");
	actionMgr->addAction("actionSet_Full_Screen_Global", N_("Display Options"), N_("Full-screen mode"), this, "fullScreen", "F11");
	

	StelPainter::initGLShaders();

	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	setResizeMode(QDeclarativeView::SizeRootObjectToView);
	qmlRegisterType<StelSkyItem>("Stellarium", 1, 0, "StelSky");
	qmlRegisterType<StelGuiItem>("Stellarium", 1, 0, "StelGui");
	rootContext()->setContextProperty("stelApp", stelApp);
	setSource(QUrl("qrc:/qml/main.qml"));
	
	QScreen* screen = glWidget->windowHandle()->screen();
	int width = conf->value("video/screen_w", screen->size().width()).toInt();
	int height = conf->value("video/screen_h", screen->size().height()).toInt();
	if (conf->value("video/fullscreen", true).toBool())
	{
#ifdef Q_OS_MAC
		// Without this, the screen is not shown on a Mac.
		resize(width, height);
#endif
		setFullScreen(true);
	}
	else
	{
		setFullScreen(false);
		int x = conf->value("video/screen_x", 0).toInt();
		int y = conf->value("video/screen_y", 0).toInt();
		move(x, y);
		resize(width, height);
	}
	show();

	flagInvertScreenShotColors = conf->value("main/invert_screenshots_colors", false).toBool();
	setFlagCursorTimeout(conf->value("gui/flag_mouse_cursor_timeout", false).toBool());
	setCursorTimeout(conf->value("gui/mouse_cursor_timeout", 10.f).toFloat());
	maxfps = conf->value("video/maximum_fps",10000.f).toFloat();
	minfps = conf->value("video/minimum_fps",10000.f).toFloat();

	// XXX: This should be done in StelApp::init(), unfortunately for the moment we need init the gui before the
	// plugins, because the gui create the QActions needed by some plugins.
	StelApp::getInstance().initPlugIns();

	QThread::currentThread()->setPriority(QThread::HighestPriority);
	startMainLoop();
}

void StelMainView::deinit()
{
	deinitGL();
	delete stelApp;
	stelApp = NULL;
}

// Update the translated title
void StelMainView::initTitleI18n()
{
	QString appNameI18n = q_("Stellarium %1").arg(StelUtils::getApplicationVersion());
	setWindowTitle(appNameI18n);
}

void StelMainView::setFullScreen(bool b)
{
	if (b)
		showFullScreen();
	else
		showNormal();
}

void StelMainView::thereWasAnEvent()
{
	lastEventTimeSec = StelApp::getTotalRunTime();
}

void StelMainView::drawBackground(QPainter*, const QRectF&)
{
	const double now = StelApp::getTotalRunTime();

	// Determines when the next display will need to be triggered
	// The current policy is that after an event, the FPS is maximum for 2.5 seconds
	// after that, it switches back to the default minfps value to save power
	if (now-lastEventTimeSec<2.5)
	{
		double duration = 1./getMaxFps();
		int dur = (int)(duration*1000);
		QTimer::singleShot(dur<5 ? 5 : dur, this, SLOT(updateScene()));
	}

	// Manage cursor timeout
	if (cursorTimeout>0.f && (now-lastEventTimeSec>cursorTimeout) && flagCursorTimeout)
	{
		if (QGuiApplication::overrideCursor()==0)
			QGuiApplication::setOverrideCursor(Qt::BlankCursor);
	}
	else
	{
		if (QGuiApplication::overrideCursor()!=0)
			QGuiApplication::restoreOverrideCursor();
	}
}

void StelMainView::startMainLoop()
{
	// Set a timer refreshing for every minfps frames
	minFpsChanged();
}

void StelMainView::minFpsChanged()
{
	if (minFpsTimer!=NULL)
	{
		disconnect(minFpsTimer, SIGNAL(timeout()), 0, 0);
		delete minFpsTimer;
		minFpsTimer = NULL;
	}

	minFpsTimer = new QTimer(this);
	connect(minFpsTimer, SIGNAL(timeout()), scene(), SLOT(update()));
	minFpsTimer->start((int)(1./getMinFps()*1000.));
}



void StelMainView::mouseMoveEvent(QMouseEvent* event)
{
	thereWasAnEvent(); // Refresh screen ASAP
	QDeclarativeView::mouseMoveEvent(event);
}

void StelMainView::mousePressEvent(QMouseEvent* event)
{
	thereWasAnEvent(); // Refresh screen ASAP
	QDeclarativeView::mousePressEvent(event);
}

void StelMainView::mouseReleaseEvent(QMouseEvent* event)
{
	thereWasAnEvent(); // Refresh screen ASAP
	QDeclarativeView::mouseReleaseEvent(event);
}

void StelMainView::wheelEvent(QWheelEvent* event)
{
	thereWasAnEvent(); // Refresh screen ASAP
	QDeclarativeView::wheelEvent(event);
}

void StelMainView::moveEvent(QMoveEvent * event)
{
	Q_UNUSED(event);

	// We use the glWidget instead of the even, as we want the screen that shows most of the widget.
	StelApp::getInstance().setDevicePixelsPerPixel(glWidget->windowHandle()->devicePixelRatio());
}

void StelMainView::keyPressEvent(QKeyEvent* event)
{
	thereWasAnEvent(); // Refresh screen ASAP
	// Try to trigger a gobal shortcut.
	StelActionMgr* actionMgr = StelApp::getInstance().getStelActionManager();
	if (actionMgr->pushKey(event->key() + event->modifiers(), true)) {
		event->setAccepted(true);
		return;
	}
	QDeclarativeView::keyPressEvent(event);
}

void StelMainView::keyReleaseEvent(QKeyEvent* event)
{
	thereWasAnEvent(); // Refresh screen ASAP
	QDeclarativeView::keyReleaseEvent(event);
}


//! Delete openGL textures (to call before the GLContext disappears)
void StelMainView::deinitGL()
{
	StelApp::getInstance().deinit();
	delete gui;
	gui = NULL;
}

void StelMainView::saveScreenShot(const QString& filePrefix, const QString& saveDir)
{
	screenShotPrefix = filePrefix;
	screenShotDir = saveDir;
	emit(screenshotRequested());
}

void StelMainView::doScreenshot(void)
{
	QFileInfo shotDir;
	QImage im = glWidget->grabFrameBuffer();
	if (flagInvertScreenShotColors)
		im.invertPixels();

	if (screenShotDir == "")
		shotDir = QFileInfo(StelFileMgr::getScreenshotDir());
	else
		shotDir = QFileInfo(screenShotDir);

	if (!shotDir.isDir())
	{
		qWarning() << "ERROR requested screenshot directory is not a directory: " << QDir::toNativeSeparators(shotDir.filePath());
		return;
	}
	else if (!shotDir.isWritable())
	{
		qWarning() << "ERROR requested screenshot directory is not writable: " << QDir::toNativeSeparators(shotDir.filePath());
		return;
	}

	QFileInfo shotPath;
	for (int j=0; j<100000; ++j)
	{
		shotPath = QFileInfo(shotDir.filePath() + "/" + screenShotPrefix + QString("%1").arg(j, 3, 10, QLatin1Char('0')) + ".png");
		if (!shotPath.exists())
			break;
	}

	qDebug() << "INFO Saving screenshot in file: " << QDir::toNativeSeparators(shotPath.filePath());
	if (!im.save(shotPath.filePath())) {
		qWarning() << "WARNING failed to write screenshot to: " << QDir::toNativeSeparators(shotPath.filePath());
	}
}

#endif // ifndef USE_QUICKVIEW
