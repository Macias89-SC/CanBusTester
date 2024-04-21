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
            x: 522
            y: 125
            kmh_gauge:myController.SpeedGauge
            kmh_string:myController.SpeedText
        }
        FuelLevel {
            id: fuelLevel
            x: 581
            y: 515
            scale: 0.9
            fuelLevel:myController.FuelLevel
        }
        RPMGauge {
            id: rpm
            x: 8
            y: 125
            width: 500
            height: 500
            rpmFrame:myController.RPM
        }
        EngineTemp {
            id: engineTemp
            x: 62
            y: 521
            currentEngineTemperature: myController.EngineTemp
            scale: 0.9
        }
        IsoIcons {
            id: isoIcons
            x: 115
            y: 626

            doorOpen_active: myController.DoorOpenActive
            sterringFault_active: myController.SteeringFaultActive
            seatBelt_active: myController.SeatBeltActive
            parkingBrake_active: myController.ParkingBrakeActive
            abs_active: myController.AbsActive
            charging_active: myController.Charging
            checkEngine_active: myController.CheckEngine
            cruiseControl_active: myController.CruiseControlActive
            esp_active: myController.EspActive
            imobilizer_active:myController.ImobilizerActive
            antiFog_active: myController.FogLight

            scale: 0.8
        }
        LightIcons {
            id: lightIcons
            x: 440
            y: 125
            right_active: myController.rightBlink
            left_active: myController.leftBlink
            highBeam_active: myController.highBeam

        }

    }


}
