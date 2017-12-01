QT       += core quick network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homecontrol
TEMPLATE = app
CONFIG += c++11

SOURCES += src/main.cpp \
    src/log.cpp \
    src/domain/ControlPoint.cpp \
    src/features/home/HomeScreen.cpp \
    src/features/wifi/WiFiScreen.cpp \
    src/model/Device.cpp \
    src/shared/extensions/QObjectExtension.cpp

HEADERS  += src/log.hpp \
    src/domain/ControlPoint.hpp \
    src/features/home/HomeScreen.hpp \
    src/features/wifi/WiFiScreen.hpp \
    src/model/Device.hpp \
    src/model/device_p.hpp \
    src/shared/extensions/QObjectExtension.hpp

INCLUDEPATH += "/home/daniel/workspaces/qt/QtUPnP/upnp"

unix {
  LIBS += /home/daniel/workspaces/qt/HomeControl/libs/libqtupnp.a
  PRE_TARGETDEPS += /home/daniel/workspaces/qt/HomeControl/libs/libqtupnp.a
}

RESOURCES += resources.qrc
