#include "Eliminar_Usuarios.h"
#include "ui_Eliminar_Usuarios.h"

Eliminar_Usuarios::Eliminar_Usuarios(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Eliminar_Usuarios)
{
    ui->setupUi(this);
    int contador = 0;
    connect(ui->Regresar, &QPushButton::clicked, this, &Eliminar_Usuarios::Boton_Regresar);

    QFile archivo("USUARIOS.dat");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo de usuarios.");
        return;
    }

    QTextStream in(&archivo);

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        QStringList partes = linea.split(';');
        if (partes.size() != 4) continue;

        for (int i = 0; i < 3; ++i) {
            QTableWidgetItem *newitem = new QTableWidgetItem(partes[i]);
            ui->Datos_Empleados->setRowCount(contador+1);
            ui->Datos_Empleados->setItem(contador, i, newitem);
        }
        contador++;
    }

    archivo.close();
}

Eliminar_Usuarios::~Eliminar_Usuarios()
{
    delete ui;
}

void Eliminar_Usuarios::Boton_Regresar()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}
