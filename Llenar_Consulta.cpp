#include "Llenar_Consulta.h"
#include "ui_Llenar_Consulta.h"
#include "ESTILOS.h"


Llenar_Consulta::Llenar_Consulta(QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Llenar_Consulta)
{
    ui->setupUi(this);
}

Llenar_Consulta::~Llenar_Consulta()
{
    delete ui;
}
