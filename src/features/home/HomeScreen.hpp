#ifndef HOMESCREEN_HPP
#define HOMESCREEN_HPP

#include <QTimer>
#include <QObject>
#include <QVariantList>

#include "../../domain/ControlPoint.hpp"

class HomeScreen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList devices READ devices NOTIFY devicesChanged)
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY currentTimeChanged)

public:
    explicit HomeScreen(QObject *parent = Q_NULLPTR);
    ~HomeScreen();
    const QString currentTime() const;
    const QVariantList &devices() const;

Q_SIGNALS:
    void currentTimeChanged();
    void devicesChanged(const QVariantList &devices);

private Q_SLOTS:
    void onNewDevice(const Device &device);
    void onClockTick();

private:
    QTimer *m_timer;
    QVariantList m_devices;
    ControlPoint *m_controlPoint;
};

#endif // HOMESCREEN_HPP
