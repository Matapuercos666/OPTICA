#include "PuntoVenta.h"
#include "ui_PuntoVenta.h"
#include "ESTILOS.h"
#include "QPushButton"

PuntoVenta::PuntoVenta(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PuntoVenta)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
}

PuntoVenta::~PuntoVenta()
{
    delete ui;
}



