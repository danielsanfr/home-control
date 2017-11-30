import qbs 1.0

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        Depends {
            name: "Qt"
            submodules: [
                "core",
                "quick",
                "network",
                "xml"
            ]
        }

        // Additional import path used to resolve QML modules in Qt Creator's code model
        property pathList qmlImportPaths: []

        cpp.cxxLanguageVersion: "c++11"

        cpp.defines: [
            // The following define makes your compiler emit warnings if you use
            // any feature of Qt which as been marked deprecated (the exact warnings
            // depend on your compiler). Please consult the documentation of the
            // deprecated API in order to know how to port your code away from it.
            "QT_DEPRECATED_WARNINGS",

            // You can also make your code fail to compile if you use deprecated APIs.
            // In order to do so, uncomment the following line.
            // You can also select to disable deprecated APIs only up to a certain version of Qt.
            //"QT_DISABLE_DEPRECATED_BEFORE=0x060000" // disables all the APIs deprecated before Qt 6.0.0
        ]
        cpp.includePaths: [
            "~/workspaces/qt/QtUPnP/upnp"
        ]
        cpp.dynamicLibraries: [
            "/home/daniel/workspaces/qt/HomeControl/libs/libqtupnp.a"
        ]

        files: [
            "src/domain/ControlPoint.cpp",
            "src/domain/ControlPoint.hpp",
            "src/features/home/HomeScreen.cpp",
            "src/features/home/HomeScreen.hpp",
            "src/features/wifi/WiFiScreen.cpp",
            "src/features/wifi/WiFiScreen.hpp",
            "src/log.hpp",
            "src/log.cpp",
            "src/main.cpp",
            "resources.qrc",
            "src/model/Device.cpp",
            "src/model/Device.hpp",
            "src/model/device_p.hpp",
            "src/shared/extensions/QObjectExtension.cpp",
            "src/shared/extensions/QObjectExtension.hpp",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: product.type
            qbs.install: true
        }
    }
}
