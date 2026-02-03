#include "Lista_Clientes.h"
#include "ui_Lista_Clientes.h"
#include "VentanaBaseMain.h"

#include "ESTILOS.h"
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

struct Paciente
{
    int ID;
    QString Nombre;
    QString Apellido1;
    QString Apellido2;
    QString Nacimiento;
    QString Edad;
    QString Telefono;
    QString Email;
    QString Sexo;
    QString Antecedentesf;
    QString Antecedenteso;
}aux;

Lista_Clientes::Lista_Clientes(QWidget *parent)
    : VentanaBaseMain(parent)
    , ui(new Ui::Lista_Clientes)
    , Agregar_PacienteWindow(nullptr)
{
    ui->setupUi(this);
    ui->Datos_Clientes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Datos_Clientes->setAlternatingRowColors(true);
    Fuente::AplicarTodas(this);
    connect(this, &VentanaBaseMain::perfilClicked, this, &Lista_Clientes::abrirPerfil);
    connect(this, &VentanaBaseMain::cerrarSesionClicked, this, &Lista_Clientes::cerrarSesion);
    connect(ui->Datos_Clientes, &QTableWidget::cellDoubleClicked, this, &Lista_Clientes::INFO);
    connect(ui->Regresar, &QPushButton::clicked, this, &Lista_Clientes::Boton_Regresar);
    connect(ui->ELIMINAR, &QPushButton::clicked, this, &Lista_Clientes::Boton_Eliminar);
    connect(ui->Agregar, &QPushButton::clicked, this, &Lista_Clientes::Boton_Agregar);

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

void Lista_Clientes::Boton_Eliminar()
{
    int fila = ui->Datos_Clientes->currentRow();
    if(fila < 0) return;

    QTableWidgetItem *itemid = ui->Datos_Clientes->item(fila,0);

    if(!itemid)
    {
        QMessageBox::critical(this, "Error", "No se pudo borrar el paciente");
    }
    int idPaciente = itemid->text().toInt();

    QString NombrePaciente = ui->Datos_Clientes->item(fila, 1)->text();

    QMessageBox::StandardButton respuesta = QMessageBox::question(this, "Confirmar eliminación",
    QString("¿Está seguro de eliminar al paciente '%1'?").arg(NombrePaciente),
    QMessageBox::Yes | QMessageBox::No);

    if(respuesta != QMessageBox::Yes) return;

    QSqlQuery q;
    q.prepare("DELETE FROM PACIENTES WHERE ID = ?");
    q.addBindValue(idPaciente);

    q.exec();

    ui->Datos_Clientes->removeRow(fila);

    QMessageBox::information(this, "Eliminado", "Paciente eliminado correctamente");
}

void Lista_Clientes::Boton_Agregar()
{
    if (!Agregar_PacienteWindow || Agregar_PacienteWindow->isHidden())
    {
        if(Agregar_PacienteWindow)
        {
            delete Agregar_PacienteWindow;
        }
        Agregar_PacienteWindow = new Agregar_Paciente(this);
        connect(Agregar_PacienteWindow, &Agregar_Paciente::Actualizar, this, &Lista_Clientes::LlenarDatos);
        Agregar_PacienteWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(Agregar_PacienteWindow, &QObject::destroyed, this, [this]() { Agregar_PacienteWindow = nullptr; });
    }
    Agregar_PacienteWindow->show();
}

void Lista_Clientes::LlenarDatos()
{
    ui->Datos_Clientes->setColumnCount(4);
    ui->Datos_Clientes->setHorizontalHeaderLabels({"N° Paciente", "Nombre", "Edad", "Telefono"});

    ui->Datos_Clientes->setRowCount(0);//limpiamos

    QSqlQuery query;
    query.prepare("SELECT ID, NOMBRE, APELLIDO1, APELLIDO2, EDAD,"
                  "TELEFONO FROM PACIENTES ");
    if(!query.exec())
    {
        qDebug() << "Error" <<query.lastError().text();
        QMessageBox::critical(this, "Error", "No se pudo Cargar la lista de pacientes");
        return;
    }

    while(query.next())
    {
        aux.ID = query.value(0).toInt();
        aux.Nombre = query.value(1).toString();
        aux.Apellido1 = query.value(2).toString();
        aux.Apellido2 = query.value(3).toString();
        aux.Edad = query.value(4).toString();
        aux.Telefono = query.value(5).toString();
        QStringList Nombre_Completo;
        Nombre_Completo << aux.Nombre;
        if(!aux.Apellido1.isEmpty()) Nombre_Completo << aux.Apellido1;
        if(!aux.Apellido2.isEmpty()) Nombre_Completo << aux.Apellido2;
        QString NOMBRE = Nombre_Completo.join(" ");

        int fila = ui->Datos_Clientes->rowCount();
        ui->Datos_Clientes->insertRow(fila);

        ui->Datos_Clientes->setItem(fila, 0, new QTableWidgetItem(QString::number(aux.ID)));
        ui->Datos_Clientes->setItem(fila, 1, new QTableWidgetItem(NOMBRE));
        ui->Datos_Clientes->setItem(fila, 2, new QTableWidgetItem(aux.Edad));
        ui->Datos_Clientes->setItem(fila, 3, new QTableWidgetItem(aux.Telefono));

    }

    //ui->Datos_Clientes->resizeColumnsToContents(); queda como comentario hasta saberlo usar porque somos pendejos
}

void Lista_Clientes::INFO(int row, int column)
{
    QTableWidgetItem *Item = ui->Datos_Clientes->item(row, 0);
    int PACIENTEID = Item->text().toInt();
    Info_paciente *INFOWINDOW = new Info_paciente(PACIENTEID, this);
    connect(INFOWINDOW, &Info_paciente::Actualizar, this, &Lista_Clientes::LlenarDatos);
    INFOWINDOW->setAttribute(Qt::WA_DeleteOnClose);
    INFOWINDOW->show();
}

void Lista_Clientes::abrirPerfil(){
    qDebug() << "Abrir perfil desde ICON";
}

void Lista_Clientes::cerrarSesion(){
    qDebug() << "Cerrar sesion desde ICON";
    this->close();
}
