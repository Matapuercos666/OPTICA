#include "Inventario.h"
#include "ui_Inventario.h"
#include "ESTILOS.h"
#include "VentanaBaseMain.h"

Inventario::Inventario(QWidget *parent)
    : VentanaBaseMain(parent)
    , ui(new Ui::Inventario)
{
    ui->setupUi(this);
    ui->Inventario2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Inventario2->setAlternatingRowColors(true);
    Fuente::AplicarTodas(this);
    connect(ui->Regresar, &QPushButton::clicked, this, &Inventario::Boton_Regresar);}

Inventario::~Inventario()
{
    delete ui;
    if (parentWidget())
        parentWidget()->show();
}
void Inventario::Boton_Regresar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}
