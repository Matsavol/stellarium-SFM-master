/*
 * Stellarium
 * Copyright (C) 2013 Fabien Chereau
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

import QtQuick 2.2

StelDialog {
	id: root
	title: country ? qsTr("Pick City") : qsTr("Pick Country")
	width: rootStyle.niceMenuWidth
	height: 320*rootStyle.scale
	property string country
	property string city

	ListView {
		id: countriesList
		anchors.left: parent.left
		width: root.country ? root.width / 2 : root.width
		Behavior on width {
			NumberAnimation { easing.type: Easing.InOutQuad }
		}
		height: root.height
		delegate: StelListItem {
			withArrow: false
			text: qsTr(modelData)
			selected: root.country === modelData
			onClicked: root.country = modelData
		}
		model: stellarium.getCountryNames()
		clip: true
	}
	ListView {
		anchors.left: countriesList.right
		anchors.right: parent.right
		height: root.height
		delegate: StelListItem {
			withArrow: false
			text: qsTr(modelData)
			selected: root.city === modelData
			onClicked: root.city = modelData
		}
		model: stellarium.getCityNames(root.country)
		clip: true
	}

	onCityChanged: {
		if (!country || !city) return;
		stellarium.location = "%1, %2".arg(city).arg(country)
		close();
	}
}
