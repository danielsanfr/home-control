import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls.Material 2.2

ItemDelegate {
    width: ListView.view.width
    height: 80
    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            spacing: 5
            Layout.margins: 5
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image {
                width: 50
                height: 50
                sourceSize.width: width
                sourceSize.height: height

                source: "qrc:/assets/icons8-computer-96.png"
            }

            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Label {
                    text: modelData["friendlyName"]
                    font.bold: true
                    maximumLineCount: 1
                    Layout.fillWidth: true
                }
                Label {
                    text: modelData["modelDescription"]
                    elide: "ElideRight"
                    wrapMode: "WordWrap"
                    maximumLineCount: 2
                    Layout.fillWidth: true
                }
            }
        }

        Rectangle {
            height: 1
            color: Material.color(Material.Grey)
            Layout.fillWidth: true
        }
    }
}

