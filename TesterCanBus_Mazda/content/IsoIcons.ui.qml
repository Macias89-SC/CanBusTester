import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

RowLayout {
    id: iso_Icons
    width: 800
    height: 50

    property bool checkEngine_active: false
    property bool charging_active: false
    property bool abs_active: false
    property bool cruiseControl_active: false
    property bool doorOpen_active: false
    property bool esp_active: false
    property bool imobilizer_active: false
    property bool parkingBrake_active: false
    property bool seatBelt_active: false
    property bool sterringFault_active: false
    property bool antiFog_active: false

    Repeater {
       model: [
     { activePath: "Assets/Icons/charging_active.svg", inactivePath: "Assets/Icons/charging_NotActive.svg", isActive: charging_active, x: 0, y: 0 },
     { activePath: "Assets/Icons/CheckEngine_active.svg", inactivePath: "Assets/Icons/CheckEngine_NotActive.svg", isActive: checkEngine_active, x: 80, y: 0 },
     { activePath: "Assets/Icons/CruiseControl_active.svg", inactivePath: "Assets/Icons/CruiseControl_NotActive.svg", isActive: cruiseControl_active, x: 160, y:0 },
     { activePath: "Assets/Icons/ABS_active.svg", inactivePath: "Assets/Icons/ABS_NotActive.svg", isActive: abs_active, x: 240, y: 0 },
     { activePath: "Assets/Icons/DoorOpen_active.svg", inactivePath: "Assets/Icons/DoorOpen_NotActive.svg", isActive: doorOpen_active, x: 320, y: 0 },
     { activePath: "Assets/Icons/ESP_active.svg", inactivePath: "Assets/Icons/ESP_NotActive.svg", isActive: esp_active, x: 400, y: 0 },
     { activePath: "Assets/Icons/Imobilizer_fault.svg", inactivePath: "Assets/Icons/Imobilizer_NotFault.svg", isActive: imobilizer_active, x: 480, y: 0 },
     { activePath: "Assets/Icons/ParkingBreak_active.svg", inactivePath: "Assets/Icons/ParkingBreak_NotActive.svg", isActive: parkingBrake_active, x: 560, y: 0 },
     { activePath: "Assets/Icons/SeatBelt_active.svg", inactivePath: "Assets/Icons/SeatBelt_NotActive.svg", isActive: seatBelt_active, x: 640, y: 0 },
     { activePath: "Assets/Icons/SterringFault_active.svg", inactivePath: "Assets/Icons/SterringFault_NotActive.svg",isActive: sterringFault_active, x: 720, y: 0 },
     { activePath: "Assets/Icons/LightIcons/AntiFog_active.svg", inactivePath:"Assets/Icons/LightIcons/AntiFog_NotActive.svg",isActive: antiFog_active, x: 800, y: 0 },
        ]

        delegate: RowLayout {
            width: 100
            height: 100
            x: modelData.x
            y: modelData.y

            // Obraz dla wersji aktywnej
            Image {
                anchors.centerIn: parent
                source: modelData.activePath
                width: 50
                height: 50
                visible: modelData.isActive
            }

            // Obraz dla wersji nieaktywnej
            Image {
                anchors.centerIn: parent
                source: modelData.inactivePath
                width: 50
                height: 50
                visible: !modelData.isActive
            }
        }
    }
}


