/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id:iso_Icons
    width: 500
    height: 100

    property bool checkEngine: false
    property bool charging: false

    Image {
        id: charging_active
        x: 14
        y: 31
        source: "Assets/Icons/charging_active.svg"
        fillMode: Image.PreserveAspectFit
        visible: iso_Icons.charging===true
    }

    Image {
        id: charging_NotActive
        x: 14
        y: 31
        source: "Assets/Icons/charging_NotActive.svg"
        fillMode: Image.PreserveAspectFit
        visible: iso_Icons.charging===false
    }

    Image {
        id: checkEngine_active
        x: 100
        y: 32
        source: "Assets/Icons/CheckEngine_active.svg"
        fillMode: Image.PreserveAspectFit
        visible: iso_Icons.checkEngine === true
    }

    Image {
        id: checkEngine_NotActive
        x: 100
        y: 32
        source: "Assets/Icons/CheckEngine_NotActive.svg"
        fillMode: Image.PreserveAspectFit
        visible: iso_Icons.checkEngine === false
    }


    states: [
        State {
            name: "charging_faultActive"
            when: iso_Icons.charging === true

            PropertyChanges {
                target: charging_active
                opacity: 1
            }
            PropertyChanges {
                target: charging_NotActive
                opacity: 0
            }
        },
        State {
            name: "charging_faultNOTActive"
            when: iso_Icons.charging === false

            PropertyChanges {
                target: charging_active
                opacity: 0
            }
            PropertyChanges {
                target: charging_NotActive
                opacity: 1
            }
        }
    ]
}
