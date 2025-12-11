#include "Eliminar_Usuarios.h"
#include "ui_Eliminar_Usuarios.h"

Eliminar_Usuarios::Eliminar_Usuarios(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Eliminar_Usuarios)
{
    ui->setupUi(this);
}

Eliminar_Usuarios::~Eliminar_Usuarios()
{
    delete ui;
}
