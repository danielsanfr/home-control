#include "HomeScreen.hpp"

#include <QTime>
#include <QVariantMap>

#include "../../shared/extensions/QObjectExtension.hpp"

HomeScreen::HomeScreen(QObject *parent) : QObject(parent), m_timer(new QTimer(this)),
    m_controlPoint(new ControlPoint(this))
{
    bool isOk = connect(m_controlPoint, &ControlPoint::newDevice, this, &HomeScreen::onNewDevice);
    Q_ASSERT(isOk);
    isOk = connect(m_timer, &QTimer::timeout, this, &HomeScreen::onClockTick);
    Q_ASSERT(isOk);

    m_timer->setInterval(15000);
    m_timer->start();

    QTimer::singleShot(200, this, [=]() { m_controlPoint->discover(); });
}

HomeScreen::~HomeScreen()
{
}

const QString HomeScreen::currentTime() const
{
    return QTime::currentTime().toString("hh:mm");
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

void HomeScreen::onClockTick()
{
    Q_EMIT currentTimeChanged();
}
