#include "Agregar_Paciente.h"
#include "ui_Agregar_Paciente.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

Agregar_Paciente::Agregar_Paciente(QWidget *parent)
    : QDialog(parent)
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
    if(ui->NOMBRE->text().isEmpty())
    {
        ui->NOMBRE->setFocus();
        QMessageBox::critical(this, "Nombre", "Favor de introducir un nombre válido");
        return;
    }

    QString Nombre = ui->NOMBRE->text().trimmed();
    QString Telefono = ui->TELEFONO->text().trimmed();
    QString Email = ui->EMAIL->text().trimmed();
    QString Nacimiento = ui->NACIMIENTO->text().trimmed();
    QString Antecedentes = ui->ANTECEDENTES->text();
    QString Edad = ui->EDAD->text().trimmed();

    QSqlQuery query;
    query.clear();
    query.prepare("INSERT INTO PACIENTES (NOMBRE, TELEFONO, EMAIL, NACIMIENTO, ANTECEDENTES, EDAD) "
                  "VALUES (?,?,?,?,?,?)");
    query.addBindValue(Nombre);
    query.addBindValue(Telefono);
    query.addBindValue(Email);
    query.addBindValue(Nacimiento);
    query.addBindValue(Antecedentes);
    query.addBindValue(Edad);

    if(!query.exec())
    {
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
