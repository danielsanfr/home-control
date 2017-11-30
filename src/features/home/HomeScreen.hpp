#ifndef HOMESCREEN_HPP
#define HOMESCREEN_HPP

#include <QObject>
#include <QVariantList>

#include "../../domain/ControlPoint.hpp"

class HomeScreen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList devices READ devices NOTIFY devicesChanged)

public:
    explicit HomeScreen(QObject *parent = Q_NULLPTR);
    ~HomeScreen();
    const QVariantList &devices() const;

Q_SIGNALS:
    void devicesChanged(const QVariantList &devices);

private Q_SLOTS:
    void onNewDevice(const Device &device);

private:
    QVariantList m_devices;
    ControlPoint *m_controlPoint;
};

#endif // HOMESCREEN_HPP
