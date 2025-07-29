#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QCryptographicHash>

inline QString encriptar(const QString &contrasena) {
    QByteArray hash = QCryptographicHash::hash(contrasena.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

#endif // UTILS_H
