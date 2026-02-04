#include "Inventario.h"
#include "ui_Inventario.h"
#include "ESTILOS.h"

Inventario::Inventario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inventario)
{
    ui->setupUi(this);
    ui->Inventario2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Inventario2->setAlternatingRowColors(true);
    Fuente::AplicarTodas(this);

}

Inventario::~Inventario()
{
    delete ui;
}


