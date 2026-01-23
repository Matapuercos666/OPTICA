#include "ManejoDeData.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ManejoDeData::ManejoDeData() {}

ManejoDeData::~ManejoDeData()
{
    cerrar();
}

ManejoDeData& ManejoDeData::instance()
{
    static ManejoDeData instancia;
    return instancia;
}

bool ManejoDeData::abrir(const QString &RutaArchivo)
{
    //conexion por defecto de qt
    const QString nombreconexion = "principal";
    if(QSqlDatabase::contains(nombreconexion))
    {
        QSqlDatabase::removeDatabase(nombreconexion);
    }
    m_db = QSqlDatabase::addDatabase("QSQLITE", nombreconexion);
    m_db.setDatabaseName(RutaArchivo);

    if(!m_db.open())
    {
        qCritical() << "Error Al Abrir La Base De Datos..." << m_db.lastError().text();
        return false;
    }

    //activar modo wal para mejorar el rendimiento
    QSqlQuery query(m_db);
    if(!query.exec("PRAGMA journal_mode=WAL;"))
    {
        qWarning() << "No se pudo activar wal:" << query.lastError().text();
    }

    return true;
}

void ManejoDeData::cerrar()
{
    if(m_db.isOpen())
    {
        m_db.close();
    }
}

QSqlDatabase ManejoDeData::BaseDeDatos() const
{
    return m_db;
}
