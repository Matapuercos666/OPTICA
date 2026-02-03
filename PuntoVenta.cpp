#include "PuntoVenta.h"
#include "ui_PuntoVenta.h"
#include "ESTILOS.h"
#include "QPushButton"
#include "VentanaBaseMain.h"

PuntoVenta::PuntoVenta(QWidget *parent)
    : VentanaBaseMain(parent)
    , ui(new Ui::PuntoVenta)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->Regresar, &QPushButton::clicked, this, &PuntoVenta::Boton_Regresar);
    connect(this, &VentanaBaseMain::perfilClicked, this, &PuntoVenta::abrirPerfil);
    connect(this, &VentanaBaseMain::cerrarSesionClicked, this, &PuntoVenta::cerrarSesion);
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

void PuntoVenta::abrirPerfil(){
    qDebug() << "Abrir perfil desde ICON";
}

void PuntoVenta::cerrarSesion(){
    qDebug() << "Cerrar sesion desde ICON";
    this->close();
}
