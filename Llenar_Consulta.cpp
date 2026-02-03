#include "Llenar_Consulta.h"
#include "ui_Llenar_Consulta.h"
#include "ESTILOS.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

// cambiar db para guardar al empleado que hizo el examen

Llenar_Consulta::Llenar_Consulta(int PACIENTEID, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Llenar_Consulta)
    , ID(PACIENTEID)
{
    ui->setupUi(this);
    connect(ui->CERRAR, &QPushButton::clicked, this, &Llenar_Consulta::Boton_Cancelar);
    connect(ui->AGREGAR, &QPushButton::clicked, this, &Llenar_Consulta::Boton_Aceptar);
}

Llenar_Consulta::~Llenar_Consulta()
{
    delete ui;
}

void Llenar_Consulta::Boton_Cancelar()
{
    this->close();
}
void Llenar_Consulta::Boton_Aceptar()
{
    if(Campo_Lleno() || !ui->OBSERVACIONES->toPlainText().trimmed().isEmpty())
    {
        QString OBSERVACIONES = ui->OBSERVACIONES->toPlainText();
        QString FECHA         = ui->FECHA->text();
        //agregar el id del paciente

        QSqlQuery q;
        q.prepare("INSERT INTO CONSULTAS (PACIENTEID, FECHA, COMENTARIO) "
                  "VALUES (?, ?, ?)");
        q.addBindValue(ID);
        q.addBindValue(FECHA);
        q.addBindValue(OBSERVACIONES);

        if(!q.exec())
        {
            qDebug()<<"Error al insertar consulta: "<<q.lastError().text();
            return;
        }

        int ConsultaID = q.lastInsertId().toInt();

        QString AVSCOD = ui->AVscOD->text().trimmed();
        QString AVCCOD = ui->AVccOD->text().trimmed();
        QString AVOD   = ui->AVOD->text().trimmed();
        QString RetiOD = ui->RetinoOD->text().trimmed();
        QString RXTOD  = ui->RxTotalOD->text().trimmed();
        QString AMBUOD = ui->AmbulaOD->text().trimmed();

        QString AVSCOI = ui->AVscOI->text().trimmed();
        QString AVCCOI = ui->AVccOI->text().trimmed();
        QString AVOI   = ui->AVOI->text().trimmed();
        QString RetiOI = ui->RetinoOI->text().trimmed();
        QString RXTOI  = ui->RxTotalOI->text().trimmed();
        QString AMBUOI = ui->AmbulaOI->text().trimmed();

        //Empezamos con el ojo derecho
        q.clear();
        q.prepare("INSERT INTO EXAMENES (CONSULTAID, OJO, AV_SC, RETINOSCOPIA, RX_TOTAL, AMBULATORIA, AV_CC) "
                  "VALUES (?,'DERECHO', ?, ?, ?, ?, ?)");
        q.addBindValue(ConsultaID);
        q.addBindValue(AVSCOD);
        q.addBindValue(RetiOD);
        q.addBindValue(RXTOD);
        q.addBindValue(AMBUOD);
        q.addBindValue(AVCCOD);
        if(!q.exec())
        {
            qDebug()<<"Error en examen od"<<q.lastError().text();
            qDebug()<<"Error; "<<ConsultaID;
            return;
        }

        //OJO IZQUIERDO
        q.clear();
        q.prepare("INSERT INTO EXAMENES (CONSULTAID, OJO, AV_SC, RETINOSCOPIA, RX_TOTAL, AMBULATORIA, AV_CC)"
                  "VALUES (?,'IZQUIERDO', ?, ?, ?, ?, ?)");
        q.addBindValue(ConsultaID);
        q.addBindValue(AVSCOI);
        q.addBindValue(RetiOI);
        q.addBindValue(RXTOI);
        q.addBindValue(AMBUOI);
        q.addBindValue(AVCCOI);

        if(!q.exec())
        {
            qDebug()<<"Error en examen iz"<<q.lastError().text();
            qDebug()<<"ERROR: "<<ConsultaID;
            return;
        }

        QMessageBox::information(this, "EXITO", "Examen guardado correctamente");
        accept();

    }
}

bool Llenar_Consulta::Campo_Lleno()
{
    QList<QLineEdit*> LineEdits = findChildren<QLineEdit*>();
    for (QLineEdit* le : LineEdits)
    {
        if(!le->text().trimmed().isEmpty())
        {
            return true; //al menos uno no está vacío
        }
    }
    return false;
}
