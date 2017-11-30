#ifndef QOBJECTEXTENSION_HPP
#define QOBJECTEXTENSION_HPP

#include <QObject>
#include <QVariantMap>

namespace QObjectExtension
{

    QVariantMap toMap(const QObject &object);

}

#endif // QOBJECTEXTENSION_HPP
