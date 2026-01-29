#include "USUARIOS.h"
#include "ui_USUARIOS.h"
#include "ESTILOS.h"
#include "Validacion.h"
#include "VentanaBaseMain.h"

USUARIOS::USUARIOS(QWidget *parent)
    : VentanaBaseMain(parent)
    , ui(new Ui::USUARIOS)
    , CambiarContrasenaWindow(nullptr)
    , CambiarNombreWindow(nullptr)
    , EliminarWindow(nullptr)
    , AgregarWindow(nullptr)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->CambiarContrasena, &QPushButton::clicked, this, &USUARIOS::Boton_CambiarPassword);
    connect(ui->CambiarNombre, &QPushButton::clicked, this, &USUARIOS::Boton_CambiarNombre);
    connect(ui->ELIMINAR, &QPushButton::clicked, this, &USUARIOS::Boton_Eliminar);
    connect(ui->Agregar, &QPushButton::clicked, this, &USUARIOS::Boton_AgregarUsuario);
    connect(ui->Regresar, &QPushButton::clicked, this, &USUARIOS::Boton_Regresar);
}

USUARIOS::~USUARIOS()
{
    delete ui;
}

void USUARIOS::Boton_CambiarPassword()
{
    if(Validacion::ConfirmarPassword(this))
    {
        if(CambiarContrasenaWindow)
        {
            delete CambiarNombreWindow;
        }
        CambiarContrasenaWindow = new Cambiar_Password(this);
        CambiarContrasenaWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(CambiarContrasenaWindow, &QObject::destroyed, this, [this]() { CambiarContrasenaWindow = nullptr; });
        CambiarContrasenaWindow->show();


    }
}

void USUARIOS::Boton_CambiarNombre()
{
    if(Validacion::ConfirmarPassword(this))
    {
        if(CambiarNombreWindow)
        {
            delete CambiarNombreWindow;
        }

        CambiarNombreWindow = new Cambiar_Nombre(this);
        CambiarNombreWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(CambiarNombreWindow, &QObject::destroyed, this, [this]() { CambiarNombreWindow = nullptr; });
        CambiarNombreWindow->show();


    }
}

void USUARIOS::Boton_Eliminar()
{
    if(Validacion::ConfirmarPassword(this))
    {
        if(EliminarWindow)
        {
            delete EliminarWindow;
        }
        EliminarWindow = new Eliminar_Usuarios(this);
        EliminarWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(EliminarWindow, &QObject::destroyed, this, [this](){EliminarWindow = nullptr;});
        EliminarWindow->show();
    }
}

void USUARIOS::Boton_AgregarUsuario()
{
    if(Validacion::ConfirmarPassword(this))
    {
        if(AgregarWindow)
        {
            delete AgregarWindow;
        }
        AgregarWindow = new Agregar_Usuario(this);
        AgregarWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(AgregarWindow, &QObject::destroyed, this, [this](){AgregarWindow = nullptr;});
        AgregarWindow->show();
    }
}


void USUARIOS::Boton_Regresar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}
