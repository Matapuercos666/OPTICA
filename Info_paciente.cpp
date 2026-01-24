#include "Info_paciente.h"
#include "ui_Info_paciente.h"

Info_paciente::Info_paciente(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Info_paciente)
{
    ui->setupUi(this);
}

Info_paciente::~Info_paciente()
{
    delete ui;
}
