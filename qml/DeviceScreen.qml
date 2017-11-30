import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Item {
    property alias device: deviceDetail.device

    clip: true

    function pushDeviceOptions() {
        stackView.push(deviceOptionsComponent, {"device": device})
    }

    function popDeviceOptions() {
        if (stackView.depth > 1) {
            stackView.pop()
            return true
        }
        return false
    }

    DeviceDetail {
        id: deviceDetail
        anchors.fill: parent
    }

    ColumnLayout {
        anchors.centerIn: parent
        visible: device === undefined || device === null

        Image {
            source: "qrc:/assets/icons8-headstone-96.png"
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: qsTr("Select a device from the\nlist on the side.")
            font.pointSize: 14
            font.bold: true
            horizontalAlignment: Qt.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: Item { }
        popEnter: Transition {
            XAnimator {
                from: (stackView.mirrored ? -1 : 1) * - stackView.width
                to: 0
                duration: 400
                easing.type: Easing.OutCubic
            }
        }

        popExit: Transition {
            XAnimator {
                from: 0
                to: (stackView.mirrored ? -1 : 1) * stackView.width
                duration: 400
                easing.type: Easing.OutCubic
            }
        }
    }

    Component {
        id: deviceOptionsComponent
        DeviceOptions {
        }
    }
}
