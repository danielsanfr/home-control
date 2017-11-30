#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <QUrl>
#include <QDebug>
#include <QObject>
#include <QSharedDataPointer>

#include "device_p.hpp"

#define PROPERTY_IMPL(type, Name, name) \
    inline void set##Name(const type &name) \
    { \
        if (m_data->name != name) { \
            m_data->name = name; \
            Q_EMIT name##Changed(); \
        } \
    } \
    inline const type & name() const { return m_data-> name; } \
    Q_SIGNAL void name##Changed(); \

#define Q_PROPERTY_IMPL(type, Name, name) \
    Q_PROPERTY(type name READ name WRITE set##Name NOTIFY name##Changed) \

class Device : public QObject
{
    Q_OBJECT
    Q_PROPERTY_IMPL(QString, Uuid, uuid)
    Q_PROPERTY_IMPL(QString, Type, type)
    Q_PROPERTY_IMPL(QUrl, BaseUrl, baseUrl)
    Q_PROPERTY_IMPL(QString, FriendlyName, friendlyName)
    Q_PROPERTY_IMPL(QString, Manufacturer, manufacturer)
    Q_PROPERTY_IMPL(QUrl, ManufacturerUrl, manufacturerUrl)
    Q_PROPERTY_IMPL(QString, ModelDescription, modelDescription)
    Q_PROPERTY_IMPL(QString, ModelName, modelName)
    Q_PROPERTY_IMPL(QString, ModelNumber, modelNumber)
    Q_PROPERTY_IMPL(QUrl, ModelUrl, modelUrl)
    Q_PROPERTY_IMPL(QString, SerialNumber, serialNumber)
    Q_PROPERTY_IMPL(QString, Upc, upc)
    Q_PROPERTY_IMPL(QUrl, PresentationUrl, presentationUrl)

public:
    Device();
    Device(const Device &other);
    ~Device();

    PROPERTY_IMPL(QString, Uuid, uuid)
    PROPERTY_IMPL(QString, Type, type)
    PROPERTY_IMPL(QUrl, BaseUrl, baseUrl)
    PROPERTY_IMPL(QString, FriendlyName, friendlyName)
    PROPERTY_IMPL(QString, Manufacturer, manufacturer)
    PROPERTY_IMPL(QUrl, ManufacturerUrl, manufacturerUrl)
    PROPERTY_IMPL(QString, ModelDescription, modelDescription)
    PROPERTY_IMPL(QString, ModelName, modelName)
    PROPERTY_IMPL(QString, ModelNumber, modelNumber)
    PROPERTY_IMPL(QUrl, ModelUrl, modelUrl)
    PROPERTY_IMPL(QString, SerialNumber, serialNumber)
    PROPERTY_IMPL(QString, Upc, upc)
    PROPERTY_IMPL(QUrl, PresentationUrl, presentationUrl)

    Q_INVOKABLE QString toString() const;

    Device &operator=(const Device &rhs);
    bool operator==(const Device &other) const;
    bool operator!=(const Device &other) const;

private:
    QSharedDataPointer<DeviceData> m_data;
};

Q_DECLARE_METATYPE(Device)

QDebug operator<<(QDebug dbg, const Device &device);

#endif // DEVICE_HPP
