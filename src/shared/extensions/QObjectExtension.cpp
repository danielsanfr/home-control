#include "QObjectExtension.hpp"

#include <QMetaObject>
#include <QMetaProperty>

QVariantMap QObjectExtension::toMap(const QObject &object)
{
    QVariantMap map;
    const QMetaObject *metaObject = object.metaObject();
    for (int index = 0; index < metaObject->propertyCount(); ++index) {
        QMetaProperty metaProperty = metaObject->property(index);
        map[metaProperty.name()] = object.property(metaProperty.name());
    }
    return map;
}
