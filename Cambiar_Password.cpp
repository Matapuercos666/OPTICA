#include "Cambiar_Password.h"
#include "ui_Cambiar_Password.h"
#include "Utils.h"
#include <QMessageBox>
#include <QFile>

Cambiar_Password::Cambiar_Password(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cambiar_Password)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
}

Cambiar_Password::~Cambiar_Password()
{
    delete ui;
}
