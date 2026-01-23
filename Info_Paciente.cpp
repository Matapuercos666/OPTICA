#include "Info_Paciente.h"
#include "ui_Info_Paciente.h"

Info_Paciente::Info_Paciente(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Info_Paciente)
{
    ui->setupUi(this);
}

Info_Paciente::~Info_Paciente()
{
    delete ui;
}
