#include "ControlPoint.hpp"

#include <controlpoint.hpp>
#include <device.hpp>

USING_UPNP_NAMESPACE

ControlPoint::ControlPoint(QObject *parent) : QObject(parent), m_cp(new CControlPoint(this))
{
    bool isOk = connect(m_cp, SIGNAL(newDevice(QString)), this, SLOT(onNewDevice(QString)));
    Q_ASSERT(isOk);
    isOk = connect(m_cp, &CControlPoint::lostDevice, this, &ControlPoint::onLostDevice);
    Q_ASSERT(isOk);
    isOk = connect(m_cp, &CControlPoint::eventReady, this, &ControlPoint::onEventReady);
    Q_ASSERT(isOk);
    isOk = connect(m_cp, &CControlPoint::upnpError, this, &ControlPoint::onUPnPError);
    Q_ASSERT(isOk);
    isOk = connect(m_cp, &CControlPoint::networkError, this, &ControlPoint::onNetworkError);
    Q_ASSERT(isOk);
}

ControlPoint::~ControlPoint()
{
}

void ControlPoint::discover()
{
    m_cp->discover();
}

void ControlPoint::onNewDevice(const QString &uuid)
{
    const CDevice &cdevice = m_cp->device(uuid);
    Device device;
//    Q_PROPERTY_IMPL(QString, Location, location)
//    Q_PROPERTY_IMPL(QString, Uuid, uuid)
//    Q_PROPERTY_IMPL(QString, Type, type)
//    Q_PROPERTY_IMPL(QUrl, BaseUrl, baseUrl)
//    Q_PROPERTY_IMPL(QString, FriendlyName, friendlyName)
//    Q_PROPERTY_IMPL(QString, Manufacturer, manufacturer)
//    Q_PROPERTY_IMPL(QUrl, ManufacturerUrl, manufacturerUrl)
//    Q_PROPERTY_IMPL(QString, ModelDescription, modelDescription)
//    Q_PROPERTY_IMPL(QString, ModelName, modelName)
//    Q_PROPERTY_IMPL(QString, ModelNumber, modelNumber)
//    Q_PROPERTY_IMPL(QUrl, ModelUrl, modelUrl)
//    Q_PROPERTY_IMPL(QString, SerialNumber, serialNumber)
//    Q_PROPERTY_IMPL(QString, Upc, upc)
//    Q_PROPERTY_IMPL(QUrl, PresentationUrl, presentationUrl)
//    device.setLocation(cdevice.);
    device.setUuid(cdevice.uuid());
    device.setType(cdevice.deviceType());
    device.setBaseUrl(cdevice.url());
    device.setFriendlyName(cdevice.friendlyName());
    device.setManufacturer(cdevice.manufacturer());
    device.setManufacturerUrl(cdevice.manufacturerURL());
    device.setModelDescription(cdevice.modelDesc());
    device.setModelName(cdevice.modelName());
    device.setModelNumber(cdevice.modelNumber());
    device.setModelUrl(cdevice.modelURL());
    device.setSerialNumber(cdevice.serialNumber());
    device.setUpc(cdevice.upc());
    device.setPresentationUrl(cdevice.presentationURL());

    Q_EMIT(newDevice(device));
}

void ControlPoint::onLostDevice(const QString &uuid)
{
    qDebug() << uuid;
}

void ControlPoint::onEventReady(const QStringList &event)
{
    qDebug() << event;
}

void ControlPoint::onUPnPError(int errorCode, const QString &errorString)
{
    qDebug() << errorString;
}

void ControlPoint::onNetworkError(const QString &uuid, QNetworkReply::NetworkError errorCode,
                                  const QString &errorString)
{
    qDebug() << uuid << errorString;
}
