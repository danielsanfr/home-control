import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

RowLayout {
    property alias name: nameLabel
    property alias value: valeuLabel

    Layout.fillWidth: true
    Label {
        id: nameLabel
        Layout.minimumWidth: 130
    }

    Label {
        id: valeuLabel
    }
}
