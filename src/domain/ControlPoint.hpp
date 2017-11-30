#ifndef CONTROLPOINT_HPP
#define CONTROLPOINT_HPP

#include <QObject>
#include <QNetworkReply>

#include "../model/Device.hpp"

namespace QtUPnP {
    class CControlPoint;
}

class ControlPoint : public QObject
{
    Q_OBJECT
public:
    explicit ControlPoint(QObject *parent = Q_NULLPTR);
    ~ControlPoint();
    void discover();

Q_SIGNALS:
    void newDevice(const Device &device);

private Q_SLOTS:
    void onNewDevice(const QString &uuid);
    void onLostDevice(const QString &uuid);
    void onEventReady(const QStringList &event);
    void onUPnPError(int errorCode, const QString &errorString);
    void onNetworkError(const QString &uuid, QNetworkReply::NetworkError errorCode,
                        const QString &errorString);
private:
    QtUPnP::CControlPoint *m_cp;
};

#endif // CONTROLPOINT_HPP
