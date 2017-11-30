import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

ColumnLayout {
    property variant device

    width: parent.width
    visible: device !== undefined && device !== null

    SingleDetail {
        name {
            text: qsTr("Name")
            font.bold: true
        }
        value {
            text: qsTr("Value")
            font.bold: true
        }
    }

    SingleDetail {
        name.text: qsTr("UDN")
        value.text: device["uuid"]
    }

    SingleDetail {
        name.text: qsTr("Type")
        value.text: device["type"]
    }

    SingleDetail {
        name.text: qsTr("Base URL")
        value.text: device["baseUrl"]
    }

    SingleDetail {
        name.text: qsTr("Friendly Name")
        value.text: device["friendlyName"]
    }

    SingleDetail {
        name.text: qsTr("Manufacturer")
        value.text: device["manufacturer"]
    }

    SingleDetail {
        name.text: qsTr("Manufacturer URL")
        value.text: device["manufacturerUrl"]
    }

    SingleDetail {
        name.text: qsTr("Model Description")
        value.text: device["modelDescription"]
    }

    SingleDetail {
        name.text: qsTr("Model Name")
        value.text: device["modelName"]
    }

    SingleDetail {
        name.text: qsTr("Model Number")
        value.text: device["modelNumber"]
    }

    SingleDetail {
        name.text: qsTr("Model URL")
        value.text: device["modelUrl"]
    }

    SingleDetail {
        name.text: qsTr("Serial Number")
        value.text: device["serialNumber"]
    }

    SingleDetail {
        name.text: qsTr("UPC")
        value.text: device["upc"]
    }

    SingleDetail {
        name.text: qsTr("Presentation URL")
        value.text: device["presentationUrl"]
    }
}
