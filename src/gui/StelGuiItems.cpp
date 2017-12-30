/*
 * Stellarium
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

#include "StelApp.hpp"
#include "StelCore.hpp"
#include "StelProjector.hpp"

#include "StelUtils.hpp"
#include "StelGuiItems.hpp"
#include "StelLocaleMgr.hpp"
#include "StelLocation.hpp"
#include "StelMovementMgr.hpp"
#include "StelActionMgr.hpp"
#include "StelProgressController.hpp"

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QRectF>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QTimeLine>
#include <QMouseEvent>
#include <QRegExp>
#include <QPixmapCache>
#include <QProgressBar>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QSettings>

#ifdef _MSC_BUILD
#define round(dbl) dbl >= 0.0 ? (int)(dbl + 0.5) : ((dbl - (double)(int)dbl) <= -0.5 ? (int)dbl : (int)(dbl - 0.5))
#endif

void StelButton::initCtor(const QPixmap& apixOn,
                          const QPixmap& apixOff,
                          const QPixmap& apixNoChange,
                          const QPixmap& apixHover,
                          StelAction* aaction,
                          bool noBackground,
                          bool isTristate)
{
	pixOn = apixOn;
	pixOff = apixOff;
	pixHover = apixHover;
	pixNoChange = apixNoChange;
	noBckground = noBackground;
	isTristate_ = isTristate;
	opacity = 1.;
	hoverOpacity = 0.;
	action = aaction;

	Q_ASSERT(!pixOn.isNull());
	Q_ASSERT(!pixOff.isNull());

	if (isTristate_)
	{
		Q_ASSERT(!pixNoChange.isNull());
	}

	setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
	setAcceptHoverEvents(true);
	timeLine = new QTimeLine(250, this);
	timeLine->setCurveShape(QTimeLine::EaseOutCurve);
	connect(timeLine, SIGNAL(valueChanged(qreal)),
	        this, SLOT(animValueChanged(qreal)));

	if (action!=NULL)
	{
		if (action->isCheckable())
		{
			setChecked(action->isChecked());
			connect(action, SIGNAL(toggled(bool)), this, SLOT(setChecked(bool)));
			connect(this, SIGNAL(toggled(bool)), action, SLOT(setChecked(bool)));
		}
		else
		{
			QObject::connect(this, SIGNAL(triggered()), action, SLOT(trigger()));
		}
	}
}

StelButton::StelButton(QGraphicsItem* parent,
                       const QPixmap& apixOn,
                       const QPixmap& apixOff,
                       const QPixmap& apixHover,
                       StelAction *aaction,
                       bool noBackground) :
	QGraphicsPixmapItem(apixOff, parent)
{
	initCtor(apixOn, apixOff, QPixmap(), apixHover, aaction, noBackground, false);
}

StelButton::StelButton(QGraphicsItem* parent,
                       const QPixmap& apixOn,
                       const QPixmap& apixOff,
                       const QPixmap& apixNoChange,
                       const QPixmap& apixHover,
                       const QString& aactionId,
                       bool noBackground,
                       bool isTristate) :
	QGraphicsPixmapItem(apixOff, parent)
{
	StelAction *action = StelApp::getInstance().getStelActionManager()->findAction(aactionId);
	initCtor(apixOn, apixOff, apixNoChange, apixHover, action, noBackground, isTristate);
}

StelButton::StelButton(QGraphicsItem* parent,
                       const QPixmap& apixOn,
                       const QPixmap& apixOff,
                       const QPixmap& apixHover,
                       const QString& aactionId,
                       bool noBackground)
	:QGraphicsPixmapItem(apixOff, parent)
{
	StelAction *action = StelApp::getInstance().getStelActionManager()->findAction(aactionId);
	initCtor(apixOn, apixOff, QPixmap(), apixHover, action, noBackground, false);
}


int StelButton::toggleChecked(int checked)
{
	if (!isTristate_)
		checked = !!!checked;
	else
	{
		if (++checked > ButtonStateNoChange)
			checked = ButtonStateOff;
	}
	return checked;
}
void StelButton::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsItem::mousePressEvent(event);
	event->accept();
	setChecked(toggleChecked(checked));
	emit(toggled(checked));
	emit(triggered());
}

void StelButton::hoverEnterEvent(QGraphicsSceneHoverEvent*)
{
	timeLine->setDirection(QTimeLine::Forward);
	if (timeLine->state()!=QTimeLine::Running)
		timeLine->start();

	emit(hoverChanged(true));
}

void StelButton::hoverLeaveEvent(QGraphicsSceneHoverEvent*)
{
	timeLine->setDirection(QTimeLine::Backward);
	if (timeLine->state()!=QTimeLine::Running)
		timeLine->start();
	emit(hoverChanged(false));
}

void StelButton::mouseReleaseEvent(QGraphicsSceneMouseEvent*)
{
	if (action!=NULL && !action->isCheckable())
		setChecked(toggleChecked(checked));
}

void StelButton::updateIcon()
{
	if (opacity < 0.)
		opacity = 0;
	QPixmap pix(pixOn.size());
	pix.fill(QColor(0,0,0,0));
	QPainter painter(&pix);
	painter.setOpacity(opacity);
	if (!pixBackground.isNull() && noBckground==false)
		painter.drawPixmap(0, 0, pixBackground);
	painter.drawPixmap(0, 0,
		(isTristate_ && checked == ButtonStateNoChange) ? (pixNoChange) :
		(checked == ButtonStateOn) ? (pixOn) :
		/* (checked == ButtonStateOff) ? */ (pixOff));
	if (hoverOpacity > 0)
	{
		painter.setOpacity(hoverOpacity * opacity);
		painter.drawPixmap(0, 0, pixHover);
	}
	setPixmap(pix);
}

void StelButton::animValueChanged(qreal value)
{
	hoverOpacity = value;
	updateIcon();
}

void StelButton::setChecked(int b)
{
	checked=b;
	updateIcon();
}

void StelButton::setBackgroundPixmap(const QPixmap &newBackground)
{
	pixBackground = newBackground;
	updateIcon();
}

LeftStelBar::LeftStelBar(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	// Create the help label
	helpLabel = new QGraphicsSimpleTextItem("", this);
	helpLabel->setBrush(QBrush(QColor::fromRgbF(1,1,1,1)));
}

LeftStelBar::~LeftStelBar()
{
}

void LeftStelBar::addButton(StelButton* button)
{
	double posY = 0;
	if (QGraphicsItem::childItems().size()!=0)
	{
		const QRectF& r = childrenBoundingRect();
		posY += r.bottom()-1;
	}
	button->setParentItem(this);
	button->prepareGeometryChange(); // could possibly be removed when qt 4.6 become stable
	button->setPos(0., round(posY+10.5));

	connect(button, SIGNAL(hoverChanged(bool)), this, SLOT(buttonHoverChanged(bool)));
}

void LeftStelBar::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
}

QRectF LeftStelBar::boundingRect() const
{
	return childrenBoundingRect();
}

QRectF LeftStelBar::boundingRectNoHelpLabel() const
{
	// Re-use original Qt code, just remove the help label
	QRectF childRect;
	foreach (QGraphicsItem *child, QGraphicsItem::childItems())
	{
		if (child==helpLabel)
			continue;
		QPointF childPos = child->pos();
		QTransform matrix = child->transform() * QTransform().translate(childPos.x(), childPos.y());
		childRect |= matrix.mapRect(child->boundingRect() | child->childrenBoundingRect());
	}
	return childRect;
}


// Update the help label when a button is hovered
void LeftStelBar::buttonHoverChanged(bool b)
{
	StelButton* button = qobject_cast<StelButton*>(sender());
	Q_ASSERT(button);
	if (b==true)
	{
		if (button->action)
		{
			QString tip(button->action->getText());
			QString shortcut(button->action->getShortcut().toString(QKeySequence::NativeText));
			if (!shortcut.isEmpty())
			{
				//XXX: this should be unnecessary since we used NativeText.
				if (shortcut == "Space")
					shortcut = q_("Space");
				tip += "  [" + shortcut + "]";
			}
			helpLabel->setText(tip);
			helpLabel->setPos(round(boundingRectNoHelpLabel().width()+15.5),round(button->pos().y()+button->pixmap().size().height()/2-8));
		}
	}
	else
	{
		helpLabel->setText("");
	}
}

// Set the pen for all the sub elements
void LeftStelBar::setColor(const QColor& c)
{
	helpLabel->setBrush(c);
}

BottomStelBar::BottomStelBar(QGraphicsItem* parent,
                             const QPixmap& pixLeft,
                             const QPixmap& pixRight,
                             const QPixmap& pixMiddle,
                             const QPixmap& pixSingle) :
	QGraphicsItem(parent),
	pixBackgroundLeft(pixLeft),
	pixBackgroundRight(pixRight),
	pixBackgroundMiddle(pixMiddle),
	pixBackgroundSingle(pixSingle)
{
	// The text is dummy just for testing
	datetime = new QGraphicsSimpleTextItem("2008-02-06  17:33", this);
	location = new QGraphicsSimpleTextItem("Munich, Earth, 500m", this);
	fov = new QGraphicsSimpleTextItem("FOV 43.45", this);
	fps = new QGraphicsSimpleTextItem("43.2 FPS", this);

	// Create the help label
	helpLabel = new QGraphicsSimpleTextItem("", this);
	helpLabel->setBrush(QBrush(QColor::fromRgbF(1,1,1,1)));

	QColor color = QColor::fromRgbF(1,1,1,1);
	setColor(color);

	datetime->font().setPixelSize(12);
	location->font().setPixelSize(12);
	fov->font().setPixelSize(12);
	fps->font().setPixelSize(12);

	flagShowTime = true;
	flagShowLocation = true;
}

BottomStelBar::~BottomStelBar()
{
	// Remove currently hidden buttons which are not delete by a parent element
	for (QMap<QString, ButtonGroup>::iterator iter=buttonGroups.begin();iter!=buttonGroups.end();++iter)
	{
		foreach (StelButton* b, iter.value().elems)
		{
			if (b->parentItem()==0)
			{
				delete b;
				b=NULL;
			}
		}
	}
}

void BottomStelBar::addButton(StelButton* button, const QString& groupName, const QString& beforeActionName)
{
	QList<StelButton*>& g = buttonGroups[groupName].elems;
	bool done = false;
	for (int i=0; i<g.size(); ++i)
	{
		if (g[i]->action && g[i]->action->objectName()==beforeActionName)
		{
			g.insert(i, button);
			done = true;
			break;
		}
	}
	if (done == false)
		g.append(button);

	button->setVisible(true);
	button->setParentItem(this);
	updateButtonsGroups();

	connect(button, SIGNAL(hoverChanged(bool)), this, SLOT(buttonHoverChanged(bool)));
}

StelButton* BottomStelBar::hideButton(const QString& actionName)
{
	QString gName;
	StelButton* bToRemove = NULL;
	for (QMap<QString, ButtonGroup>::iterator iter=buttonGroups.begin();iter!=buttonGroups.end();++iter)
	{
		int i=0;
		foreach (StelButton* b, iter.value().elems)
		{
			if (b->action && b->action->objectName()==actionName)
			{
				gName = iter.key();
				bToRemove = b;
				iter.value().elems.removeAt(i);
				break;
			}
			++i;
		}
	}
	if (bToRemove == NULL)
		return NULL;
	if (buttonGroups[gName].elems.size() == 0)
	{
		buttonGroups.remove(gName);
	}
	// Cannot really delete because some part of the GUI depend on the presence of some buttons
	// so just make invisible
	bToRemove->setParentItem(NULL);
	bToRemove->setVisible(false);
	updateButtonsGroups();
	return bToRemove;
}

// Set the margin at the left and right of a button group in pixels
void BottomStelBar::setGroupMargin(const QString& groupName, int left, int right)
{
	if (!buttonGroups.contains(groupName))
		return;
	buttonGroups[groupName].leftMargin = left;
	buttonGroups[groupName].rightMargin = right;
	updateButtonsGroups();
}

//! Change the background of a group
void BottomStelBar::setGroupBackground(const QString& groupName,
                                       const QPixmap& pixLeft,
                                       const QPixmap& pixRight,
                                       const QPixmap& pixMiddle,
                                       const QPixmap& pixSingle)
{

	if (!buttonGroups.contains(groupName))
		return;

	buttonGroups[groupName].pixBackgroundLeft = new QPixmap(pixLeft);
	buttonGroups[groupName].pixBackgroundRight = new QPixmap(pixRight);
	buttonGroups[groupName].pixBackgroundMiddle = new QPixmap(pixMiddle);
	buttonGroups[groupName].pixBackgroundSingle = new QPixmap(pixSingle);
	updateButtonsGroups();
}

QRectF BottomStelBar::getButtonsBoundingRect() const
{
	// Re-use original Qt code, just remove the help label
	QRectF childRect;
	bool hasBtn = false;
	foreach (QGraphicsItem *child, QGraphicsItem::childItems())
	{
		if (qgraphicsitem_cast<StelButton*>(child)==0)
			continue;
		hasBtn = true;
		QPointF childPos = child->pos();
		QTransform matrix = child->transform() * QTransform().translate(childPos.x(), childPos.y());
		childRect |= matrix.mapRect(child->boundingRect() | child->childrenBoundingRect());
	}

	if (hasBtn)
		return QRectF(0, 0, childRect.width()-1, childRect.height()-1);
	else
		return QRectF();
}

void BottomStelBar::updateButtonsGroups()
{
	double x = 0;
	double y = datetime->boundingRect().height() + 3;
	for (QMap<QString, ButtonGroup >::iterator iter=buttonGroups.begin();iter!=buttonGroups.end();++iter)
	{
		ButtonGroup& group = iter.value();
		QList<StelButton*>& buttons = group.elems;
		if (buttons.empty())
			continue;
		x += group.leftMargin;
		int n = 0;
		foreach (StelButton* b, buttons)
		{
			// We check if the group has its own background if not the case
			// We apply a default background.
			if (n == 0)
			{
				if (buttons.size() == 1)
				{
					if (group.pixBackgroundSingle == NULL)
						b->setBackgroundPixmap(pixBackgroundSingle);
					else
						b->setBackgroundPixmap(*group.pixBackgroundSingle);
				}
				else
				{
					if (group.pixBackgroundLeft == NULL)
						b->setBackgroundPixmap(pixBackgroundLeft);
					else
						b->setBackgroundPixmap(*group.pixBackgroundLeft);
				}
			}
			else if (n == buttons.size()-1)
			{
				if (buttons.size() != 1)
				{
					if (group.pixBackgroundSingle == NULL)
						b->setBackgroundPixmap(pixBackgroundSingle);
					else
						b->setBackgroundPixmap(*group.pixBackgroundSingle);
				}
				if (group.pixBackgroundRight == NULL)
					b->setBackgroundPixmap(pixBackgroundRight);
				else
					b->setBackgroundPixmap(*group.pixBackgroundRight);
			}
			else
			{
				if (group.pixBackgroundMiddle == NULL)
					b->setBackgroundPixmap(pixBackgroundMiddle);
				else
					b->setBackgroundPixmap(*group.pixBackgroundMiddle);
			}
			// Update the button pixmap
			b->animValueChanged(0.);
			b->setPos(x, y);
			x += b->getButtonPixmapWidth();
			++n;
		}
		x+=group.rightMargin;
	}
	updateText(true);
}

// Make sure to avoid any change if not necessary to avoid triggering useless redraw
void BottomStelBar::updateText(bool updatePos)
{
	StelCore* core = StelApp::getInstance().getCore();
	double jd = core->getJDay();
	double deltaT = 0.;
	double sigma = -1.;
	QString sigmaInfo = "";
	QString validRangeInfo = "";
	bool displayDeltaT = false;
	if (core->getCurrentLocation().planetName.contains("Earth"))
	{
		deltaT = core->getDeltaT(jd);
		displayDeltaT = true;		
		sigma = StelUtils::getDeltaTStandardError(jd);
		core->getCurrentDeltaTAlgorithmValidRange(jd, &validRangeInfo);
	}

	// Add in a DeltaT correction. Divide DeltaT by 86400 to convert from seconds to days.
	QString newDate = flagShowTime ? StelApp::getInstance().getLocaleMgr().getPrintableDateLocal(jd-deltaT/86400.) +"   "
			+StelApp::getInstance().getLocaleMgr().getPrintableTimeLocal(jd-deltaT/86400.) : " ";
	if (datetime->text()!=newDate)
	{
		updatePos = true;
		datetime->setText(newDate);
		if (displayDeltaT && core->getCurrentDeltaTAlgorithm()!=StelCore::WithoutCorrection)
		{
			if (sigma>0)
				sigmaInfo = QString("; %1(%2T) = %3s").arg(QChar(0x03c3)).arg(QChar(0x0394)).arg(sigma, 3, 'f', 1);

			if (std::abs(deltaT)>60.)
				datetime->setToolTip(QString("%1T = %2 (%3s)%6 [n-dot @ -23.8946\"/cy%4%5]").arg(QChar(0x0394)).arg(StelUtils::hoursToHmsStr(deltaT/3600.)).arg(deltaT, 5, 'f', 2).arg(QChar(0x00B2)).arg(sigmaInfo).arg(validRangeInfo));
			else
				datetime->setToolTip(QString("%1T = %2s%5 [n-dot @ -23.8946\"/cy%3%4]").arg(QChar(0x0394)).arg(deltaT, 3, 'f', 3).arg(QChar(0x00B2)).arg(sigmaInfo).arg(validRangeInfo));
		}
		else
			datetime->setToolTip("");
	}

	QString newLocation = "";
	const StelLocation* loc = &core->getCurrentLocation();
	if (flagShowLocation && !loc->name.isEmpty())
	{
		newLocation = q_(loc->planetName) +", "+loc->name + ", "+q_("%1m").arg(loc->altitude);
	}
	if (flagShowLocation && loc->name.isEmpty())
	{
		newLocation = q_(loc->planetName)+", "
		        +StelUtils::radToDmsStr(loc->latitude)+", "
		        +StelUtils::radToDmsStr(loc->longitude);
	}
	if (location->text()!=newLocation)
	{
		updatePos = true;
		location->setText(newLocation);
		float lat = core->getCurrentLocation().latitude;
		float lon = core->getCurrentLocation().longitude;
		QString latStr, lonStr, pm;
		if (lat >= 0)
			pm = "N";
		else
			pm = "S";
		latStr = QString("%1%2%3").arg(pm).arg(lat).arg(QChar(0x00B0));
		if (lat >= 0)
			pm = "E";
		else
			pm = "W";
		lonStr = QString("%1%2%3").arg(pm).arg(lon).arg(QChar(0x00B0));
		location->setToolTip(QString("%1 %2").arg(latStr).arg(lonStr));
	}

	QSettings* confSettings = StelApp::getInstance().getSettings();
	QString str;
	QTextStream wos(&str);
	wos << "FOV " << qSetRealNumberPrecision(3) << core->getMovementMgr()->getCurrentFov() << QChar(0x00B0);
	if (fov->text()!=str)
	{
		updatePos = true;
		if (confSettings->value("gui/flag_show_fov", true).toBool())
		{
			fov->setText(str);
		}
		else
		{
			fov->setText("");
		}
	}

	str="";
	QTextStream wos2(&str);
	wos2 << qSetRealNumberPrecision(3) << StelApp::getInstance().getFps() << " FPS";
	if (fps->text()!=str)
	{
		updatePos = true;
		if (confSettings->value("gui/flag_show_fps", true).toBool())
		{
			fps->setText(str);
		}
		else
		{
			fps->setText("");
		}
	}

	if (updatePos)
	{
		QRectF rectCh = getButtonsBoundingRect();
		location->setPos(0, 0);		
		int dtp = rectCh.right()-datetime->boundingRect().width()-5;
		if ((dtp%2) == 1) dtp--; // make even pixel
		datetime->setPos(dtp,0);
		fov->setPos(datetime->x()-200, 0);
		fps->setPos(datetime->x()-95, 0);
	}
}

void BottomStelBar::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
	updateText();
}

QRectF BottomStelBar::boundingRect() const
{
	if (QGraphicsItem::childItems().size()==0)
		return QRectF();
	const QRectF& r = childrenBoundingRect();
	return QRectF(0, 0, r.width()-1, r.height()-1);
}

QRectF BottomStelBar::boundingRectNoHelpLabel() const
{
	// Re-use original Qt code, just remove the help label
	QRectF childRect;
	foreach (QGraphicsItem *child, QGraphicsItem::childItems())
	{
		if (child==helpLabel)
			continue;
		QPointF childPos = child->pos();
		QTransform matrix = child->transform() * QTransform().translate(childPos.x(), childPos.y());
		childRect |= matrix.mapRect(child->boundingRect() | child->childrenBoundingRect());
	}
	return childRect;
}

// Set the pen for all the sub elements
void BottomStelBar::setColor(const QColor& c)
{
	datetime->setBrush(c);
	location->setBrush(c);
	fov->setBrush(c);
	fps->setBrush(c);
	helpLabel->setBrush(c);
}

// Update the help label when a button is hovered
void BottomStelBar::buttonHoverChanged(bool b)
{
	StelButton* button = qobject_cast<StelButton*>(sender());
	Q_ASSERT(button);
	if (b==true)
	{
		StelAction* action = button->action;
		if (action)
		{
			QString tip(action->getText());
			QString shortcut(action->getShortcut().toString(QKeySequence::NativeText));
			if (!shortcut.isEmpty())
			{
				//XXX: this should be unnecessary since we used NativeText.
				if (shortcut == "Space")
					shortcut = q_("Space");
				tip += "  [" + shortcut + "]";
			}
			helpLabel->setText(tip);
			//helpLabel->setPos(button->pos().x()+button->pixmap().size().width()/2,-27);
			helpLabel->setPos(20,-27);
		}
	}
	else
	{
		helpLabel->setText("");
	}
}

StelBarsPath::StelBarsPath(QGraphicsItem* parent) : QGraphicsPathItem(parent)
{
	roundSize = 6;
	QPen aPen(QColor::fromRgbF(0.7,0.7,0.7,0.5));
	aPen.setWidthF(1.);
	setBrush(QBrush(QColor::fromRgbF(0.22, 0.22, 0.23, 0.2)));
	setPen(aPen);
}

void StelBarsPath::updatePath(BottomStelBar* bot, LeftStelBar* lef)
{
	QPainterPath newPath;
	QPointF p = lef->pos();
	QRectF r = lef->boundingRectNoHelpLabel();
	QPointF p2 = bot->pos();
	QRectF r2 = bot->boundingRectNoHelpLabel();

	newPath.moveTo(p.x()-roundSize, p.y()-roundSize);
	newPath.lineTo(p.x()+r.width(),p.y()-roundSize);
	newPath.arcTo(p.x()+r.width()-roundSize, p.y()-roundSize, 2.*roundSize, 2.*roundSize, 90, -90);
	newPath.lineTo(p.x()+r.width()+roundSize, p2.y()-roundSize);
	newPath.lineTo(p2.x()+r2.width(),p2.y()-roundSize);
	newPath.arcTo(p2.x()+r2.width()-roundSize, p2.y()-roundSize, 2.*roundSize, 2.*roundSize, 90, -90);
	newPath.lineTo(p2.x()+r2.width()+roundSize, p2.y()+r2.height()+roundSize);
	newPath.lineTo(p.x()-roundSize, p2.y()+r2.height()+roundSize);
	setPath(newPath);
}

void StelBarsPath::setBackgroundOpacity(double opacity)
{
	setBrush(QBrush(QColor::fromRgbF(0.22, 0.22, 0.23, opacity)));
}

StelProgressBarMgr::StelProgressBarMgr(QGraphicsItem*)
{
	setLayout(new QGraphicsLinearLayout(Qt::Vertical));
}
/*
QRectF StelProgressBarMgr::boundingRect() const
{
	if (QGraphicsItem::children().size()==0)
		return QRectF();
	const QRectF& r = childrenBoundingRect();
	return QRectF(0, 0, r.width()-1, r.height()-1);
}*/

void StelProgressBarMgr::addProgressBar(const StelProgressController* p)
{
	QProgressBar* pb = new QProgressBar();
	pb->setFixedHeight(25);
	pb->setFixedWidth(200);
	pb->setTextVisible(true);
	pb->setValue(p->getValue());
	pb->setMinimum(p->getMin());
	pb->setMaximum(p->getMax());
	pb->setFormat(p->getFormat());
	QGraphicsProxyWidget* pbProxy = new QGraphicsProxyWidget();
	pbProxy->setWidget(pb);
	pbProxy->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
	pbProxy->setZValue(150);
	static_cast<QGraphicsLinearLayout*>(layout())->addItem(pbProxy);
	allBars.insert(p, pb);
	pb->setVisible(true);
	
	connect(p, SIGNAL(changed()), this, SLOT(oneBarChanged()));
}

void StelProgressBarMgr::removeProgressBar(const StelProgressController *p)
{
	QProgressBar* pb = allBars[p];
	pb->deleteLater();
	allBars.remove(p);
}

void StelProgressBarMgr::oneBarChanged()
{
	const StelProgressController *p = static_cast<StelProgressController*>(QObject::sender());
	QProgressBar* pb = allBars[p];
	pb->setValue(p->getValue());
	pb->setMinimum(p->getMin());
	pb->setMaximum(p->getMax());
	pb->setFormat(p->getFormat());
}

CornerButtons::CornerButtons(QGraphicsItem*) : lastOpacity(10)
{
}

void CornerButtons::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*)
{
	// Do nothing. Just paint the child widgets
}

QRectF CornerButtons::boundingRect() const
{
	if (QGraphicsItem::childItems().size()==0)
		return QRectF();
	const QRectF& r = childrenBoundingRect();
	return QRectF(0, 0, r.width()-1, r.height()-1);
}

void CornerButtons::setOpacity(double opacity)
{
	if (opacity<=0. && lastOpacity<=0.)
		return;
	lastOpacity = opacity;
	if (QGraphicsItem::childItems().size()==0)
		return;
	foreach (QGraphicsItem *child, QGraphicsItem::childItems())
	{
		StelButton* sb = qgraphicsitem_cast<StelButton*>(child);
		Q_ASSERT(sb!=NULL);
		sb->setOpacity(opacity);
	}
}
