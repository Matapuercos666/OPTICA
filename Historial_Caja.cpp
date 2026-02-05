#include "Historial_Caja.h"
#include "ui_Historial_Caja.h"
#include "ESTILOS.h"
#include "VentanaBase.h"



Historial_Caja::Historial_Caja(QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Historial_Caja)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
}

Historial_Caja::~Historial_Caja()
{
    delete ui;
}
