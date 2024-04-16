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
import MyController



Item {
    id:mainRectangle
    width: 1030
    height: 740

   Controller{
        id:myController
    }

    Image {
        id: mainBackground
        x: 0
        y: 0
        width: 1030
        height: 728
        source: "Assets/MainBackground/MainBackground.svg"
        sourceSize.width: 1000
        sourceSize.height: 500
        fillMode: Image.PreserveAspectFit

        SpeedGauge {
            id: gauge
            x: 529
            y: 53
            kmh_gauge:myController.SpeedGauge
            kmh_string:myController.SpeedText
        }
        FuelLevel {
            id: fuelLevel
            x: 587
            y: 448
            scale: 0.9
            fuelLevel:myController.FuelLevel
        }
        RPMGauge {
            id: rpm
            x: 0
            y: 53
            width: 500
            height: 500
            rpmFrame:myController.RPM
        }
        EngineTemp {
            id: engineTemp
            x: 63
            y: 453
            currentEngineTemperature: myController.EngineTemp
            scale: 0.9
        }
        IsoIcons {
            id: isoIcons
            x: 273
            y: 576
            checkEngine: myController.CheckEngine
            charging: myController.Charging
            scale: 0.8
        }
    }


}
