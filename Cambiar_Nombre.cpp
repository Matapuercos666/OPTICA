#include "Cambiar_Nombre.h"
#include "ui_Cambiar_Nombre.h"

Cambiar_Nombre::Cambiar_Nombre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cambiar_Nombre)
{
    ui->setupUi(this);
}

Cambiar_Nombre::~Cambiar_Nombre()
{
    delete ui;
}
