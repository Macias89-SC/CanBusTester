/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.8
import QtQuick.Controls 2.15
import QtQuick.Timeline 1.0
import QtQuick.Shapes 1.0
import QtQuick.Studio.Components 1.0
//import QtQuick.Studio.Effects 1.0
import QtQuick.Studio.LogicHelper 1.0
import Qt5Compat.GraphicalEffects
import TesterCanBus_Mazda


Rectangle{
    id: rpm_speed
    color: "#000000"
    width: 500
    height: 500
    property alias rpmFrame: rpmTimeline.currentFrame

    Item {
        id: back
        Image {
        id: tarcza
        x: 0
        y: 0
        width: 505
        height: 505
        source: "Assets/RPMGauge/tarcza.svg"
        fillMode: Image.PreserveAspectFit
        }

        Text {
        id: text2
        x: 122
        y: 360
        color: "#ffffff"
        text: qsTr("r/min")
        font.pixelSize: 14
        font.family: "Verdana"
        }

        Text {
        id: text3
        x: 122
        y: 345
        color: "#ffffff"
        text: qsTr("x1000")
        font.pixelSize: 14
        font.family: "Verdana"
        }
    }


        Item {
            id: mask
            x: 0
            y: -4
            width: 500
            height: 500
            visible: true

            ArcItem { // pozycja od której ma zaznaczać łuk end i begin; stroke to jest szerokosć
                id: arc
                width: 500
                height: 500
                layer.enabled: false
                end: 120
                strokeColor: "#8d1c1cff"
                begin: -128
                strokeWidth: 45
                fillColor: "#00000000"
            }
        }


    Timeline {
        id: rpmTimeline
        animations: [
            TimelineAnimation {
                id: timelineAnimation
                property: "currentFrame"
                pingPong: true
                running: false
                from: 0
                duration: 1000
                loops: -1
                to: 1200
            }
        ]
        startFrame: 0
        enabled: true
        endFrame: 127

        KeyframeGroup {
            target: rot
            property: "rotation"
            Keyframe {
                frame: 0
                value: -125.5
            }
            Keyframe {
                frame: 127
                value: 125
            }
        }

        KeyframeGroup {
            target: arc
            property: "end"
            Keyframe {
                value: -128
                frame: 0
            }
            Keyframe {
                value: 125
                frame: 127
            }
        }

        KeyframeGroup {
            target: mask
            property: "visible"
            Keyframe {
                value: false
                frame: 0
            }
        }

        KeyframeGroup{
            target: arrow
            property: "color"
            Keyframe{
                value: "#ffffff"
                frame: 0
            }
            Keyframe {
                value: "#e01009"
                frame: 127
            }
        }
    }

    Item {
        id: rot
        x: 150
        y: 150
        width: 200
        height: 200
        rotation: -125
        Rectangle {
            id: arrow
            x: 97
            y: -121
            width: 5
            height: 127
            layer.enabled: true


        }
    }

    Image {
        id: smallBackgroundSpedometer
        x: 150
        y: 150
        width: 200
        height: 210
        source: "Assets/SpeedGaugePicture/SmallBackgroundSpedometer.svg"
        fillMode: Image.PreserveAspectFit
    }


}

