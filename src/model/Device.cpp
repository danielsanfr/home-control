#include "Device.hpp"

Device::Device() : QObject(), m_data(new DeviceData())
{
}

Device::Device(const Device &other) : QObject(), m_data(other.m_data)
{
}

Device::~Device()
{
}

QString Device::toString() const
{
    bool isUuidEmpty = m_data->uuid.isEmpty();
    bool isFriendlyNameEmpty = m_data->friendlyName.isEmpty();
    if (!isUuidEmpty && !isFriendlyNameEmpty) {
        return QString("Device(uuid=%1, friendlyName=%2)").arg(m_data->uuid, m_data->friendlyName);
    } else if (!isUuidEmpty) {
        return QString("Device(uuid=%1)").arg(m_data->uuid);
    } else if (!isFriendlyNameEmpty) {
        return QString("Device(friendlyName=%1)").arg(m_data->friendlyName);
    } else {
        return QString("Device()");
    }
}

Device &Device::operator=(const Device &rhs)
{
    if (this != &rhs)
        m_data = rhs.m_data;

    return *this;
}

bool Device::operator==(const Device &other) const
{
    return m_data->uuid == other.m_data->uuid;
}

bool Device::operator!=(const Device &other) const
{
    return !(*this == other);
}

QDebug operator<<(QDebug dbg, const Device &device)
{
    return dbg << device.toString().toLocal8Bit().constData();
}
