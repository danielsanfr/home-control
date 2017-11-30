import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 800
    height: 450
    minimumWidth: 480
    minimumHeight: 320
    title: qsTr("Home Control")
    header: ToolBar {
        RowLayout {
            anchors.fill: parent

            RowLayout {
                Layout.minimumWidth: window.width / 3 + 16
                Layout.maximumWidth: window.width / 3 + 16

                Label {
                    text: qsTr("Home Control")
                    font.bold: true
                    font.pointSize: 12
                    Layout.leftMargin: 8
                }

                Item {
                    Layout.fillWidth: true
                }

                Label {
                    text: "11:10"
                    font.bold: true
                    font.pointSize: 10
                    Layout.rightMargin: 8
                }

                ToolSeparator {
                    Material.theme: Material.Dark
                }
            }

            ImageButton {
                id: closeButton
                visible: source != ""
                Layout.minimumWidth: 48
                Layout.minimumHeight: 48
                Layout.maximumWidth: 48
                Layout.maximumHeight: 48
                Material.elevation: 0
                Component.onCompleted: {
                    source = ""
                }
                onClicked: {
                    source = ""
                    deviceDetail.device = null
                }
            }

            Item {
                Layout.fillWidth: true
            }

            ToolButton {
                text: qsTr("Open")
                visible: closeButton.visible
                Layout.rightMargin: 8
            }
        }
    }

    ApplicationWindow {
        id: testWindow
    }

    Page {
        anchors.fill: parent

        RowLayout {
            spacing: 0
            anchors.fill: parent
            Item {
                Layout.fillHeight: true
                Layout.minimumWidth: window.width / 3
                ListView {
                    anchors.fill: parent
                    visible: homeScreen.devices.length !== 0
                    snapMode: ListView.SnapToItem
                    model: homeScreen.devices
                    delegate: DeviceItem {
                        onClicked: {
                            deviceDetail.device = modelData
                            closeButton.source = "qrc:/assets/ic_close_white_64dp.png"
                        }
                    }
                }

                BusyIndicator {
                    anchors.centerIn: parent
                    visible: homeScreen.devices.length === 0
                    running: visible
                }
            }


            Pane {
                Material.elevation: 6
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.margins: 4

                ScrollView {
                    anchors.fill: parent
                    clip: true
                    visible: deviceDetail.device !== undefined && deviceDetail.device !== null

                    DeviceDetail {
                        id: deviceDetail
                    }
                }

                ColumnLayout {
                    anchors.centerIn: parent
                    visible: deviceDetail.device === undefined || deviceDetail.device === null

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
            }
        }
    }

}
