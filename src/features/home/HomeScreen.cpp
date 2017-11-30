#include "HomeScreen.hpp"

#include <QTimer>
#include <QDebug>
#include <QVariantMap>

#include "../../shared/extensions/QObjectExtension.hpp"

HomeScreen::HomeScreen(QObject *parent) : QObject(parent), m_controlPoint(new ControlPoint(this))
{
    qDebug() << "Contructor";
    bool isOk = connect(m_controlPoint, &ControlPoint::newDevice, this, &HomeScreen::onNewDevice);
    Q_ASSERT(isOk);
    QTimer::singleShot(200, this, [=]() { m_controlPoint->discover(); });
}

HomeScreen::~HomeScreen()
{
    qDebug() << "Destructor";
}

const QVariantList &HomeScreen::devices() const
{
    return m_devices;
}

void HomeScreen::onNewDevice(const Device &device)
{
    qDebug() << device;
    m_devices.append(QObjectExtension::toMap(device));
    Q_EMIT devicesChanged(m_devices);
}
