#include "Inventario.h"
#include "ui_Inventario.h"
#include "ESTILOS.h"

Inventario::Inventario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inventario)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->Regresar, &QPushButton::clicked, this, &Inventario::Boton_Regresar);}

Inventario::~Inventario()
{
    delete ui;
}
void Inventario::Boton_Regresar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}
