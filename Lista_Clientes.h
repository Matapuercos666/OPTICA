#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

#include "Usuario_Actual.h"
#include "Agregar_Paciente.h"
#include "Info_paciente.h"
#include <QFile>
#include <QMessageBox>

#include <QWidget>

namespace Ui {

class Lista_Clientes;
}

class Lista_Clientes : public QWidget
{
    Q_OBJECT

public:
    explicit Lista_Clientes(QWidget *parent = nullptr);
    ~Lista_Clientes();

private slots:

    void Boton_Eliminar();
    void Boton_Agregar();

private:
    Ui::Lista_Clientes *ui;
    Agregar_Paciente *Agregar_PacienteWindow;
    Info_paciente *INFOWINDOW;
    void LlenarDatos();
    void INFO(int row, int column);
};

#endif // LISTA_CLIENTES_H
