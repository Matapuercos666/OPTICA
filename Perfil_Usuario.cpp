#include "Perfil_Usuario.h"
#include "ui_Perfil_Usuario.h"
#include "VentanaBase.h"
#include "ESTILOS.h"




Perfil_Usuario::Perfil_Usuario(QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Perfil_Usuario)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);

}

Perfil_Usuario::~Perfil_Usuario()
{
    delete ui;
}
