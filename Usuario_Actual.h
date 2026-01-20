#ifndef USUARIO_ACTUAL_H
#define USUARIO_ACTUAL_H


#include <QString>

class Usuario_Actual
{
private:
    static Usuario_Actual* instancia;
    QString Nombre;
    QString Rol;
    QString Password;
    QString ID;

    Usuario_Actual();   //El constructor será privado

public:
    //Eliminando copias
    Usuario_Actual(const Usuario_Actual&) = delete;
    Usuario_Actual& operator = (const Usuario_Actual&) = delete;
    static Usuario_Actual* obtenerinstancia();

    //seters(esto también incluye modificar el archivo de usuarios)
    void establecerusuario(const QString& nombre, const QString& rol, const QString& password, const QString &id);
    void establecernombre(const QString& nombre);
    void establecerrol(const QString& rol);
    void establecerpassword(const QString& password);
    void establecerID(const QString& ID);

    //geters
    QString obtenernombre() const;
    QString obtenerrol() const;
    QString obtenerpassword() const;
    QString obtenerID() const;
    bool EsAdmin() const;    //Para control de permisos

    //limpiar datos al cerrar sesión
    void limpiar();
};

#endif // USUARIO_ACTUAL_H
