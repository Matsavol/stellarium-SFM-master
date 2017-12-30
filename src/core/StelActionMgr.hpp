/*
 * Stellarium
 * Copyright (C) 2013 Guillaume Chereau
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

#ifndef _STELACTIONMGR_HPP_
#define _STELACTIONMGR_HPP_

#include <QObject>
#include <QKeySequence>
#include <QList>

class StelAction : public QObject
{
	Q_OBJECT
public:
	friend class StelActionMgr;
	Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY toggled)

	//! Don't use this constructor, this is just there to ease the migration from QAction.
	StelAction(QObject *parent): QObject(parent) {}

	StelAction(const QString& actionId,
	           const QString& groupId,
	           const QString& text,
	           const QString& primaryKey="",
	           const QString& altKey="",
	           bool global=false);
	//! Connect the action to an object property or slot.
	//! @param slot A property or a slot name.  The slot can either have the signature `func()`, and in that
	//! case the action is made not checkable, either have the signature `func(bool)` and in that case the action
	//! is made checkable.  When linked to a property the action is always made checkable.
	void connectToObject(QObject* obj, const char* slot);
	//! Don't use setCheckable, connectToObject can automatically determine if the action is checkable or not.
	//! This is just there to ease the migration from QAction.
	void setCheckable(bool value) {checkable = value; emit changed();}
	bool isCheckable() const {return checkable;}
	bool isChecked() const {return checked;}
	bool isGlobal() const {return global;}
	void setShortcut(const QString& key);
	void setAltShortcut(const QString& key);
	QKeySequence::SequenceMatch matches(const QKeySequence& seq) const;

	QString getId() const {return objectName();}
	QString getGroup() const {return group;}
	const QKeySequence getShortcut() const {return keySequence;}
	const QKeySequence getAltShortcut() const {return altKeySequence;}
	QString getText() const;
	void setText(const QString& value) {text = value; emit changed();}
signals:
	void toggled(bool);
	void triggered();
	void changed();
public slots:
	void setChecked(bool);
	void trigger();
	void toggle();
private slots:
	void propertyChanged(bool);
private:
	bool checkable;
	bool checked;
	QString group;
	QString text;
	bool global;
	QKeySequence keySequence;
	QKeySequence altKeySequence;
	const QKeySequence defaultKeySequence;
	const QKeySequence defaultAltKeySequence;
	QObject* target;
	const char* property;
	Q_INVOKABLE void reparent();

	// Currently, there is no proper way to handle shortcuts with non latin
	// keyboards layouts.  So for the moment, if we don't use QuickView, we
	// create a QAction added to the main view that will trigger the
	// StelAction when the shortcut is typed.
#ifndef USE_QUICKVIEW
private slots:
	void onChanged();
private:
	class QAction* qAction;
#endif
};

class StelActionMgr : public QObject
{
	Q_OBJECT
public:
	StelActionMgr();
	~StelActionMgr();
	//! Create and add a new StelAction, connected to an object property or slot.
	//! @param id Global identifier.
	//!	@param groupId Group identifier.
	//! @param text Short human-readable description in English.
	//! @param shortcut Default shortcut.
	//! @param target The QObject the action is linked to.
	//! @param slot Either a slot name, in that case the action is not checkable,
	//! either a property name, in that case the action is checkable.
	StelAction* addAction(const QString& id, const QString& groupId, const QString& text,
						  QObject* target, const char* slot,
						  const QString& shortcut="", const QString& altShortcut="",
						  bool global=false);
	StelAction* findAction(const QString& id);
	bool pushKey(int key, bool global=false);

	QStringList getGroupList() const;
	QList<StelAction*> getActionList(const QString& group) const;

	//! Save current shortcuts to file.
	void saveShortcuts();
	//! Restore the default shortcuts combinations
	void restoreDefaultShortcuts();

public slots:
	//! Enable/disable all actions of application.
	//! need for editing shortcuts without trigging any actions
	//! @todo find out if this is really necessary and why.
	void setAllActionsEnabled(bool value) {actionsEnabled = value;}
private:
	bool actionsEnabled;
	QList<int> keySequence;
};

#endif // _STELACTIONMGR_HPP_
