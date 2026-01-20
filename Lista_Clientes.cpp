#include "Lista_Clientes.h"
#include "ui_Lista_Clientes.h"
#include "ESTILOS.h"
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

struct Paciente
{
    int ID;
    QString Nombre;
    QString Telefono;
    QString Antecedentes;
    int Edad;
    QString Email;
    QString Nacimiento;
}aux;

Lista_Clientes::Lista_Clientes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lista_Clientes)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->Regresar, &QPushButton::clicked, this, &Lista_Clientes::Boton_Regresar);

    LlenarDatos();
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

void Lista_Clientes::LlenarDatos()
{
    ui->Datos_Clientes->setColumnCount(7);
    ui->Datos_Clientes->setHorizontalHeaderLabels({"N° Paciente", "Nombre", "Antecedentes", "Edad", "Telefono", "Email", "Nacimiento"});
    /*ui->Datos_Clientes->setEditTriggers(QAbstractItemView::SelectRows);*/

    ui->Datos_Clientes->setRowCount(0);//limpiamos

    QSqlQuery query;
    query.prepare("SELECT ID, NOMBRE, ANTECEDENTES, EDAD, TELEFONO, EMAIL, NACIMIENTO FROM PACIENTES");
    query.exec();

    while(query.next())
    {
        aux.ID = query.value(0).toInt();
        aux.Nombre = query.value(1).toString();
        aux.Antecedentes = query.value(2).toString();
        aux.Edad = query.value(3).toInt();
        aux.Telefono = query.value(4).toString();
        aux.Email = query.value(5).toString();
        aux.Nacimiento = query.value(6).toString();

        int fila = ui->Datos_Clientes->rowCount();
        ui->Datos_Clientes->insertRow(fila);

        ui->Datos_Clientes->setItem(fila, 0, new QTableWidgetItem(QString::number(aux.ID)));
        ui->Datos_Clientes->setItem(fila, 1, new QTableWidgetItem(aux.Nombre));
        ui->Datos_Clientes->setItem(fila, 2, new QTableWidgetItem(aux.Antecedentes));
        ui->Datos_Clientes->setItem(fila, 3, new QTableWidgetItem(QString::number(aux.Edad)));
        ui->Datos_Clientes->setItem(fila, 4, new QTableWidgetItem(aux.Telefono));
        ui->Datos_Clientes->setItem(fila, 5, new QTableWidgetItem(aux.Email));
        ui->Datos_Clientes->setItem(fila, 6, new QTableWidgetItem(aux.Nacimiento));

    }

    ui->Datos_Clientes->resizeColumnsToContents();
}
