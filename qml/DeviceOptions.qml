import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Rectangle {
    property variant device

    color: "#FAFAFA"

    MouseArea {
        anchors.fill: parent
    }

    ColumnLayout {
        anchors.centerIn: parent

        Image {
            source: "qrc:/assets/icons8-headstone-96.png"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: qsTr("Function has not been\nimplemented yet.")
            font.pointSize: 14
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }
    }
}
