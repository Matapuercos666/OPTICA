#include "Info_paciente.h"
#include "ui_Info_paciente.h"
#include "VentanaBase.h"
#include "Llenar_Consulta.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QMessageBox>


Info_paciente::Info_paciente(int PACIENTEID,QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Info_paciente)
    , ID(PACIENTEID)
{

    ui->setupUi(this);

    ui->GUARDAR->setEnabled(false);

    connect(ui->Historico_consulta, &QTableWidget::cellDoubleClicked, this, &Info_paciente::DobleClick);
    connect(ui->CANCELAR, &QPushButton::clicked, this, &Info_paciente::Boton_Cancelar);
    connect(ui->AGREGAR_CITA, &QPushButton::clicked, this, &Info_paciente::Boton_Agregar);
    connect(ui->EDITAR, &QPushButton::clicked, this, &Info_paciente::Boton_Editar);
    connect(ui->GUARDAR,&QPushButton::clicked, this, &Info_paciente::Boton_Guardar);

    LLenarDatos();

    ui->Historico_consulta->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //ajusta el tamaño de los headers a toda la tabla
    ui->Historico_consulta->setAlternatingRowColors(true);
    ui->Historico_consulta->setColumnCount(3);
    ui->Historico_consulta->setHorizontalHeaderLabels({"Fecha", "Observaciones", "ID consulta"});

    LlenarConsultas();
}


void Info_paciente::LLenarDatos()
{
    QSqlQuery q;
    q.clear();
    q.prepare("SELECT * FROM PACIENTES WHERE ID = ?");
    q.addBindValue(ID);
    if(q.exec() && q.next())
    {
        //Terminar de llenar datos
        ui->IDPACIENTE->setText(q.value(0).toString());
        ui->NOMBRE->setText(q.value(1).toString());
        ui->APELLIDO_P->setText(q.value(2).toString());
        ui->APELLIDO_M->setText(q.value(3).toString());
        ui->NACIMIENTO->setDate(q.value(4).toDate());
        ui->EDAD->setText(q.value(7).toString());
        ui->TELEFONO->setText(q.value(5).toString());
        ui->EMAIL->setText(q.value(6).toString());
        ui->SEXO->setText(q.value(8).toString());
        ui->ANTECEDENTES->setText(q.value(9).toString());
        ui->ANTECEDENTES_O->setText(q.value(10).toString());
    }
}

void Info_paciente::LlenarConsultas()
{
    ui->Historico_consulta->setRowCount(0);//limpiamos

    QSqlQuery q;
    q.clear();
    q.prepare("SELECT ID, FECHA, COMENTARIO  FROM CONSULTAS"
              " WHERE PACIENTEID = ? ORDER BY FECHA DESC");
    q.addBindValue(ID);

    if(!q.exec())
    {
        qDebug()<<"Error al obtener consultas"<<q.lastError().text();
        return;
    }

    int primera = -1;

    while(q.next())
    {
        int idconsulta = q.value(0).toInt();
        QString fecha = q.value(1).toString();
        QString observaciones = q.value(2).toString();

        int row = ui->Historico_consulta->rowCount();
        ui->Historico_consulta->insertRow(row);

        ui->Historico_consulta->setItem(row, 0, new QTableWidgetItem(fecha));
        ui->Historico_consulta->setItem(row, 1, new QTableWidgetItem(observaciones));
        ui->Historico_consulta->setItem(row, 2, new QTableWidgetItem(QString::number(idconsulta)));

        if(primera == -1)
        {
            primera = idconsulta;
        }

    }

    if(primera != -1)
    {
        ui->Historico_consulta->selectRow(0);
        LlenarDetalles(primera);
    }else{
        ui->Historico_consulta->setColumnCount(1);
        ui->Historico_consulta->setHorizontalHeaderLabels({""});
        ui->Historico_consulta->setRowCount(1);
        ui->Historico_consulta->setItem(0, 0, new QTableWidgetItem("NO HAY NINGUNA CONSULTA AÚN"));
    }
}

void Info_paciente::LlenarDetalles(int CONSULTAID)
{
    // limpiamos todo
    ui->AVccOD->clear();
    ui->AVccOI->clear();
    ui->AVOD->clear();
    ui->AVOI->clear();
    ui->AVscOD->clear();
    ui->AVscOI->clear();
    ui->RetinoOD->clear();
    ui->RetinoOI->clear();
    ui->RxTotalOD->clear();
    ui->RxTotalOI->clear();
    ui->AmbulatorioOD->clear();
    ui->AmbulatorioOI->clear();
    ui->OBERVACIONES->clear();
    ui->RxAntOD->clear();
    ui->RxAntOI->clear();

    QSqlQuery q;
    q.clear();
    q.prepare("SELECT FECHA, COMENTARIO FROM CONSULTAS WHERE ID = ?");
    q.addBindValue(CONSULTAID);
    if(q.exec() && q.next())
    {
        ui->FechaExamen->setText(q.value(0).toString());
        ui->OBERVACIONES->setPlainText(q.value(1).toString());
    }else{
        qDebug()<<"No se pudo cargar la consulta " << q.lastError().text();
        return;
    }

    //Detalles del examen

    q.clear();
    q.prepare("SELECT OJO, AV_SC, RETINOSCOPIA, RX_TOTAL, AMBULATORIA, AV_CC "
              "FROM EXAMENES WHERE CONSULTAID = ?");
    q.addBindValue(CONSULTAID);

    if(!q.exec())
    {
        qDebug()<<"Error al cargar examen: "<<q.lastError().text();
        return;
    }

    while(q.next())
    {
        QString OJO = q.value(0).toString();
        if(OJO == "DERECHO")
        {
            ui->AVscOD->setText(q.value(1).toString());
            ui->RetinoOD->setText(q.value(2).toString());
            ui->RxTotalOD->setText(q.value(3).toString());
            ui->AmbulatorioOD->setText(q.value(4).toString());
            ui->AVccOD->setText(q.value(5).toString());
        }else if(OJO == "IZQUIERDO")
        {
            ui->AVscOI->setText(q.value(1).toString());
            ui->RetinoOI->setText(q.value(2).toString());
            ui->RxTotalOI->setText(q.value(3).toString());
            ui->AmbulatorioOI->setText(q.value(4).toString());
            ui->AVccOI->setText(q.value(5).toString());

        }
    }

}

void Info_paciente::DobleClick(int row, int /*COLUMN*/)
{
    QTableWidgetItem *item = ui->Historico_consulta->item(row, 2);
    if(!item) return;

    int CONSULTAID = item->text().toInt();
    LlenarDetalles(CONSULTAID);
}


void Info_paciente::Boton_Agregar()
{
    Llenar_Consulta ConsultaDialog(ID, this);
    ConsultaDialog.exec();
}

void Info_paciente::Boton_Cancelar()
{
    this->close();
}

void Info_paciente::Boton_Editar()
{
    ui->GUARDAR->setEnabled(true);
    ui->NOMBRE->setReadOnly(false);
    ui->APELLIDO_P->setReadOnly(false);
    ui->APELLIDO_M->setReadOnly(false);
    ui->NACIMIENTO->setReadOnly(false);
    ui->EDAD->setReadOnly(false);
    ui->SEXO->setReadOnly(false);
    ui->TELEFONO->setReadOnly(false);
    ui->EMAIL->setReadOnly(false);
    ui->ANTECEDENTES->setReadOnly(false);
    ui->ANTECEDENTES_O->setReadOnly(false);
    ui->scrollAreaWidgetContents->style()->unpolish(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->style()->polish(ui->scrollAreaWidgetContents);
    ui->NOMBRE->setFocus();

}

void Info_paciente::Boton_Guardar()
{
    if(ui->Nombre->text().isEmpty())
    {
        ui->Nombre->setFocus();
        QMessageBox::critical(this, "Nombre", "Favor de introducir un nombre válido");
        return;
    }

    QString Nombre = ui->NOMBRE->text().trimmed();
    QString Apellido1 = ui->APELLIDO_P->text().trimmed();
    QString Apellido2 = ui->APELLIDO_M->text().trimmed();
    QString Nacimiento = ui->NACIMIENTO->text().trimmed();
    QString Edad = ui->EDAD->text().trimmed();
    QString Sexo = ui->SEXO->text().trimmed();
    QString Telefono = ui->TELEFONO->text().trimmed();
    QString Email = ui->EMAIL->text().trimmed();
    QString Antecedentes = ui->ANTECEDENTES->toPlainText();
    QString Antecedentes_Oculares = ui->ANTECEDENTES_O->toPlainText();

    QSqlQuery query;
    query.clear();
    query.prepare("UPDATE PACIENTES SET NOMBRE = ?, APELLIDO1 = ?, APELLIDO2 = ?, NACIMIENTO = ?, EDAD = ?, SEXO = ?, "
                  "TELEFONO = ?, EMAIL = ?, ANTECEDENTESF = ?, ANTECEDENTESO = ? WHERE ID = ?");
    query.addBindValue(Nombre);
    query.addBindValue(Apellido1);
    query.addBindValue(Apellido2);
    query.addBindValue(Nacimiento);
    query.addBindValue(Edad);
    query.addBindValue(Sexo);
    query.addBindValue(Telefono);
    query.addBindValue(Email);
    query.addBindValue(Antecedentes);
    query.addBindValue(Antecedentes_Oculares);
    query.addBindValue(ID);

    if(!query.exec())
    {
        qDebug() << "Error" <<query.lastError().text();
        QMessageBox::critical(this, "Error", "No se pudo Cambiar los datos");
        return;
    }
    qDebug() << "Numero de Paciente: " << ID;

    LLenarDatos();

    emit Actualizar();

    ui->GUARDAR->setEnabled(false);
    ui->NOMBRE->setReadOnly(true);
    ui->APELLIDO_P->setReadOnly(true);
    ui->APELLIDO_M->setReadOnly(true);
    ui->NACIMIENTO->setReadOnly(true);
    ui->EDAD->setReadOnly(true);
    ui->SEXO->setReadOnly(true);
    ui->TELEFONO->setReadOnly(true);
    ui->EMAIL->setReadOnly(true);
    ui->ANTECEDENTES->setReadOnly(true);
    ui->ANTECEDENTES_O->setReadOnly(true);
    ui->scrollAreaWidgetContents->style()->unpolish(ui->scrollAreaWidgetContents);
    ui->scrollAreaWidgetContents->style()->polish(ui->scrollAreaWidgetContents);
}
Info_paciente::~Info_paciente()
{
    delete ui;
}
