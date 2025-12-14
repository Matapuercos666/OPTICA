#include "Usuario_Actual.h"

Usuario_Actual* Usuario_Actual::instancia = nullptr;

Usuario_Actual::Usuario_Actual() : Nombre(""), Rol(""), ID("")
{

}

Usuario_Actual* Usuario_Actual::obtenerinstancia()
{
    if(instancia == nullptr)
    {
        instancia = new Usuario_Actual();
    }
    return instancia;
}

void Usuario_Actual::establecerusuario(const QString& nombre, const QString& rol, const QString& password, const QString &id)
{
    Nombre = nombre;
    Rol = rol;
    Password = password;
    ID = id;
}

void Usuario_Actual::establecernombre(const QString& nombre)
{
    Nombre = nombre;
}

void Usuario_Actual::establecerrol(const QString& rol)
{
    Rol = rol;
}

void Usuario_Actual::establecerpassword(const QString& password)
{
    Password = password;
}

void Usuario_Actual::establecerID(const QString& id)
{
    ID = id;
}

//getters

QString Usuario_Actual::obtenernombre() const
{
    return Nombre;
}

QString Usuario_Actual::obtenerrol() const
{
    return Rol;
}

QString Usuario_Actual::obtenerpassword() const
{
    return Password;
}

QString Usuario_Actual::obtenerID() const
{
    return ID;
}
//Para configurar según el rol

bool Usuario_Actual::EsAdmin() const
{
    return Rol == "Administrador";
}

//Limpiar

void Usuario_Actual::limpiar()
{
    Nombre = "";
    Rol = "";
    Password = "";
    ID = "";
}
