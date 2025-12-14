#include "Lista_Clientes.h"
#include "ui_Lista_Clientes.h"
#include "ESTILOS.h"
#include <QTableWidget>

Lista_Clientes::Lista_Clientes(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lista_Clientes)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->Regresar, &QPushButton::clicked, this, &Lista_Clientes::Boton_Regresar);
    int contador = 0;

    QFile archivo("PACIENTES.dat");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo de pacientes.");
        return;
    }

    QTextStream in(&archivo);

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        QStringList partes = linea.split(';');
        if (partes.size() != 5) continue;

        for (int i = 0; i < 5; ++i) {
            QTableWidgetItem *newitem = new QTableWidgetItem(partes[i]);
            ui->Datos_Clientes->setRowCount(contador+1);
            ui->Datos_Clientes->setItem(contador, i, newitem);
        }
        contador++;
    }

    archivo.close();
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
