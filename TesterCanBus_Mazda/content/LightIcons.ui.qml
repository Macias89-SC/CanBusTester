import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Shapes 1.15

RowLayout {
    id: lightIconsRow
    width: 150
    height: 50


    property bool highBeam_active: false
    property bool left_active: false
    property bool right_active: false


    Repeater {
        model: [
        { activePath: "Assets/Icons/LightIcons/Left.svg", inactivePath: "Assets/Icons/LightIcons/Left_NotActive.svg", isActive: left_active},
        { activePath: "Assets/Icons/LightIcons/HighBeam_active.svg", inactivePath: "Assets/Icons/LightIcons/HighBeam_NotActive.svg", isActive: highBeam_active},
        { activePath: "Assets/Icons/LightIcons/Right_active.svg", inactivePath: "Assets/Icons/LightIcons/Right_NotActive.svg", isActive: right_active}
        ]

        delegate: RowLayout {
            width: 100
            height: 100
            x: modelData.x
            y: modelData.y

            // Obraz dla wersji aktywnej
            Image {
                Layout.alignment: parent
                //anchors.centerIn: parent
                source: modelData.activePath
                width: 50
                height: 50
                visible: modelData.isActive
            }

            // Obraz dla wersji nieaktywnej
            Image {
                Layout.alignment: parent
                source: modelData.inactivePath
                width: 50
                height: 50
                visible: !modelData.isActive
            }
        }
    }
}

