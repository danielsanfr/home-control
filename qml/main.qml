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
                    if (deviceScreen.popDeviceOptions()) {
                        titleLabel.reset()
                        source = "qrc:/assets/ic_close_white_64dp.png"
                    } else {
                        source = ""
                        deviceScreen.device = null
                    }
                }
            }

            Label {
                id: titleLabel
                visible: closeButton.visible
                font.bold: true
                font.pointSize: 12
                Layout.leftMargin: 8
                Layout.rightMargin: 8
                Layout.fillWidth: true
                Component.onCompleted: {
                    reset()
                }
                function reset() {
                    text = qsTr("Device details")
                }
            }

            ToolButton {
                text: qsTr("Open")
                visible: closeButton.visible
                Layout.rightMargin: 8
                onClicked: {
                    deviceScreen.pushDeviceOptions()
                    titleLabel.text = deviceScreen.device["friendlyName"]
                    closeButton.source = "qrc:/assets/ic_arrow_back_white_64dp.png"
                }
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
                            titleLabel.reset()
                            deviceScreen.popDeviceOptions()
                            deviceScreen.device = modelData
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
                Layout.leftMargin: 4
                Layout.topMargin: 8
                Layout.rightMargin: 8
                Layout.bottomMargin: 8

                DeviceScreen {
                    id: deviceScreen
                    anchors.fill: parent
                }
            }
        }
    }

}
