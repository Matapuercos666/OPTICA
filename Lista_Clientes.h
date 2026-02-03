#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

#include <QWidget>
#include "Usuario_Actual.h"
#include "Agregar_Paciente.h"
#include "Info_paciente.h"
#include <QFile>
#include <QMessageBox>

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

signals:

    void agregarPaciente();

private:
    Ui::Lista_Clientes *ui;
    void LlenarDatos();
    void INFO(int row, int column);
};

#endif // LISTA_CLIENTES_H
