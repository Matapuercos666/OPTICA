#include "Lista_Clientes.h"
#include "ui_Lista_Clientes.h"
#include "ESTILOS.h"

Lista_Clientes::Lista_Clientes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lista_Clientes)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->Regresar, &QPushButton::clicked, this, &Lista_Clientes::Boton_Regresar);
}

Lista_Clientes::~Lista_Clientes()
{
    delete ui;
    if (parentWidget())
        parentWidget()->show();
}

void Lista_Clientes::Boton_Regresar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}
