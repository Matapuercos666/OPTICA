#include "Agregar_Paciente.h"
#include "ui_Agregar_Paciente.h"
#include "Usuario_Actual.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>


//tamaño ventana
#include "VentanaBase.h"

Agregar_Paciente::Agregar_Paciente(QWidget *parent)
    : VentanaBase(parent)
    , ui(new Ui::Agregar_Paciente)
{
    ui->setupUi(this);
    connect(ui->AGREGAR, &QPushButton::clicked, this, &Agregar_Paciente::Boton_Agregar);
    connect(ui->CANCELAR, &QPushButton::clicked, this, &Agregar_Paciente::Boton_Cancelar);
}

Agregar_Paciente::~Agregar_Paciente()
{
    delete ui;
}

void Agregar_Paciente::Boton_Agregar()
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
    int Edad = ui->EDAD->text().toInt();
    QString Sexo = ui->SEXO->text().trimmed();
    QString Telefono = ui->TELEFONO->text().trimmed();
    QString Email = ui->EMAIL->text().trimmed();
    QString Antecedentes = ui->ANTECEDENTES->toPlainText();
    QString Antecedentes_Oculares = ui->ANTECEDENTES_O->toPlainText();
    //sabado hacer una clase con estructura usuario para generalizar datos

    QSqlQuery query;
    query.clear();
    query.prepare("INSERT INTO PACIENTES (NOMBRE, APELLIDO1, APELLIDO2, NACIMIENTO, EDAD, SEXO,"
                  "TELEFONO, EMAIL, ANTECEDENTESF, ANTECEDENTESO, EMPLEADOID) "
                  "VALUES (?,?,?,?,?,?,?,?,?,?,?)");
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
    Usuario_Actual* actual = Usuario_Actual::obtenerinstancia();
    QString idtexto = actual->obtenerID();
    int usuarioid = idtexto.toInt();
    query.addBindValue(usuarioid);

    if(!query.exec())
    {
        qDebug() << "Error" <<query.lastError().text();
        QMessageBox::critical(this, "Error", "No se pudo agregar al nuevo usuario");
    }else{
        int NuevoId = query.lastInsertId().toInt();
        QMessageBox::information(this, "EXITO", "Agregado con exito, el paciente con ID: " + QString::number(NuevoId));
        emit Actualizar();
    }

    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}

void Agregar_Paciente::Boton_Cancelar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}
