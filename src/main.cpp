#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "log.hpp"
#include "features/home/HomeScreen.hpp"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("homeScreen", new HomeScreen(&app));
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
