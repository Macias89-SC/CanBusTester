import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Shapes 1.15

RowLayout {
    id: lightIconsRow
    width: 400
    height: 400
    rotation: 0

    property bool highBeam_active: false
    property bool left_active: false
    property bool right_active: false

   readonly property real radiusReadOnly: 150
   readonly property real angleStepReadOnly: 60

    Repeater {
        model: [
 { activePath: "Assets/Icons/LightIcons/Left.svg", inactivePath: "Assets/Icons/LightIcons/Left_NotActive.svg", isActive: left_active},
 { activePath: "Assets/Icons/LightIcons/HighBeam_active.svg", inactivePath: "Assets/Icons/LightIcons/HighBeam_NotActive.svg", isActive: highBeam_active},
 { activePath: "Assets/Icons/LightIcons/Right_active.svg", inactivePath: "Assets/Icons/LightIcons/Right_NotActive.svg", isActive: right_active}
        ]

        delegate: RowLayout {
            width: 80
            height: 100
            scale: 1.1
            x: lightIconsRow.width / 2 + lightIconsRow.radiusReadOnly * Math.cos(index * lightIconsRow.angleStepReadOnly * Math.PI / 180) - width / 2
            y: lightIconsRow.height / 2 + lightIconsRow.radiusReadOnly * Math.sin(index * lightIconsRow.angleStepReadOnly * Math.PI / 180) - height / 2


            Image {
                anchors.centerIn: parent
                source: modelData.isActive ? modelData.activePath : modelData.inactivePath
                width: 50
                height: 50
                rotation:   (modelData.activePath === "Assets/Icons/LightIcons/HighBeam_active.svg") ? 180 :
                            (modelData.activePath === "Assets/Icons/LightIcons/Left.svg") ? 180 :
                            (modelData.activePath === "Assets/Icons/LightIcons/Right_active.svg") ? 180 : 0
            }
        }
    }
}

