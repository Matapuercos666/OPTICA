#ifndef MANEJODEDATA_H
#define MANEJODEDATA_H

#include <QString>
#include <QSqlDatabase>

class ManejoDeData
{
public:
    static ManejoDeData& instance();//singelton

    bool abrir(const QString& RutaArchivo = "BDJardines.sqlite");

    void cerrar();

    QSqlDatabase BaseDeDatos() const();


private:
    ManejoDeData();
    ~ManejoDeData();

    ManejoDeData(const ManejoDeData&) = delete;
    ManejoDeData& operator=(const ManejoDeData&) = delete;

    QSqlDatabase m_db;
};

#endif // MANEJODEDATA_H
