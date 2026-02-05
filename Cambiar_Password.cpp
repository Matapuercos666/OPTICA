#include "Cambiar_Password.h"
#include "ui_Cambiar_Password.h"
#include "Utils.h"
#include <QMessageBox>
#include <QFile>
#include "VentanaBase.h"
#include "ESTILOS.h"



Cambiar_Password::Cambiar_Password(QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Cambiar_Password)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
}

Cambiar_Password::~Cambiar_Password()
{
    delete ui;
}
