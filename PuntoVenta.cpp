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
    connect(ui->Regresar, &QPushButton::clicked, this, &PuntoVenta::Boton_Regresar);
}

PuntoVenta::~PuntoVenta()
{
    delete ui;
    if (parentWidget())
        parentWidget()->show();
}

void PuntoVenta::Boton_Regresar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}

