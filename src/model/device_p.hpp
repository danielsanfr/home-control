#ifndef DEVICE_P_HPP
#define DEVICE_P_HPP

#include <QUrl>
#include <QString>
#include <QSharedData>

struct DeviceData : public QSharedData
{
    DeviceData() { }
    DeviceData(const DeviceData &other) : QSharedData(other),
        uuid(other.uuid),
        type(other.type),
        baseUrl(other.baseUrl),
        friendlyName(other.friendlyName),
        manufacturer(other.manufacturer),
        manufacturerUrl(other.manufacturerUrl),
        modelDescription(other.modelDescription),
        modelName(other.modelName),
        modelNumber(other.modelNumber),
        modelUrl(other.modelUrl),
        serialNumber(other.serialNumber),
        upc(other.upc),
        presentationUrl(other.presentationUrl)
    {
    }

    QString uuid;
    QString type;
    QUrl baseUrl;
    QString friendlyName;
    QString manufacturer;
    QUrl manufacturerUrl;
    QString modelDescription;
    QString modelName;
    QString modelNumber;
    QUrl modelUrl;
    QString serialNumber;
    QString upc;
    QUrl presentationUrl;
};

#endif // DEVICE_P_HPP
