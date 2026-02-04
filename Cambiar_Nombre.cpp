#include "Cambiar_Nombre.h"
#include "ui_Cambiar_Nombre.h"
#include "ESTILOS.h"

Cambiar_Nombre::Cambiar_Nombre(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cambiar_Nombre)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);

}

Cambiar_Nombre::~Cambiar_Nombre()
{
    delete ui;
}
