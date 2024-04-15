/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml
import QtQuick.Timeline 1.0
import QtQuick.Studio.Components 1.0
import QtQuick.Studio.Effects 1.0
import QtQuick.Layouts
import TesterCanBus_Mazda



Rectangle {
    id:mainRectangle
    width: 1000
    height: 500

    Image {
        id: mainBackground
        x: 0
        y: 0
        width: 1029
        height: 728
        source: "Assets/MainBackground/MainBackground.svg"
        sourceSize.width: 1000
        sourceSize.height: 500
        fillMode: Image.PreserveAspectFit

        Gauge {
            id: gauge
            x: 232
            y: 8
            kmh_gauge:25
            kmh_string:"test"
        }

        FuelLevel {
            id: fuelLevel
            x: 294
            y: 408
            scale: 0.9
            fuelLevel:1
        }
    }
}
