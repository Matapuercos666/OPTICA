#include "ui_Lista_Usuarios.h"
#include "Lista_Usuarios.h"
#include "ESTILOS.h"
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


Lista_Usuarios::Lista_Usuarios(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::Lista_Usuarios)
{
    ui->setupUi(this);

    Fuente::AplicarTodas(this);

}

Lista_Usuarios::~Lista_Usuarios()
{
    delete ui;
}
