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
import Stellarium 1.0

MouseArea {
	id: root
	property string text;
	property alias action: stelAction.action

	width: parent.width
	height: textElem.height + 40*rootStyle.scale
	Rectangle {
		gradient: Gradient {
			GradientStop { position: 0.0; color: getColor(1, 1, pressed) }
			GradientStop { position: 1.0; color: getColor(1, 1.5, pressed) }
		}
		border  { width: 1; color: getColor(1, 0.5) }
		radius: 3*rootStyle.scale
		anchors {
			fill: parent
			margins: 5
		}

		Text {
			id: textElem
			anchors.centerIn: parent
			text: root.text
			font.pixelSize: rootStyle.fontNormalSize
			color: "white"
		}
	}
	onClicked: {
		stelAction.trigger()
	}

	StelAction {
		id: stelAction
	}
}
