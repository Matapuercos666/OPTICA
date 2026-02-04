#include "USUARIOS.h"
#include "ui_USUARIOS.h"
#include "ESTILOS.h"
#include "Validacion.h"

USUARIOS::USUARIOS(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::USUARIOS)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);

    connect(ui->CambiarContrasena, &QPushButton::clicked, this, &USUARIOS::Boton_CambiarPassword);
    connect(ui->CambiarNombre, &QPushButton::clicked, this, &USUARIOS::Boton_CambiarNombre);
    connect(ui->ELIMINAR, &QPushButton::clicked, this, &USUARIOS::Boton_Eliminar);
    connect(ui->Agregar, &QPushButton::clicked, this, &USUARIOS::Boton_AgregarUsuario);
}

USUARIOS::~USUARIOS()
{
    delete ui;
}

void USUARIOS::Boton_CambiarPassword()
{
    if(Validacion::ConfirmarPassword())
    {
       emit cambiarPassword();
    }
}

void USUARIOS::Boton_CambiarNombre()
{
    if(Validacion::ConfirmarPassword())
    {
       emit cambiarNombre();
    }
}

void USUARIOS::Boton_Eliminar()
{
    if(Validacion::ConfirmarPassword())
    {
        emit eliminarUsuario();
    }
}

void USUARIOS::Boton_AgregarUsuario()
{
    if(Validacion::ConfirmarPassword())
    {
        emit agregarUsuario();
    }
}


