#include "Info_paciente.h"
#include "ui_Info_paciente.h"
#include "VentanaBase.h"
#include <QSqlDatabase>
#include <QSqlQuery>

Info_paciente::Info_paciente(int PACIENTEID,QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Info_paciente)
{
    QSqlQuery q;
    q.prepare("SELECT * FROM PACIENTES WHERE ID = ?");
    q.addBindValue(PACIENTEID);
    ui->setupUi(this);
    if(q.exec() && q.next())
    {
//Terminar de llenar datos
        ui->Historico_consulta->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //ajusta el tamaño de los headers a toda la tabla
        ui->Historico_consulta->setAlternatingRowColors(true);
    }
}

Info_paciente::~Info_paciente()
{
    delete ui;
}
