#include "Inventario_Usuario.h"
#include "ui_Inventario_Usuario.h"

Inventario_Usuario::Inventario_Usuario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Inventario_Usuario)
{
    ui->setupUi(this);
}

Inventario_Usuario::~Inventario_Usuario()
{
    delete ui;
}
