#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

#include <QMainWindow>
#include "Usuario_Actual.h"
#include "Agregar_Paciente.h"
#include <QFile>
#include <QMessageBox>

namespace Ui {

class Lista_Clientes;
}

class Lista_Clientes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lista_Clientes(QWidget *parent = nullptr);
    ~Lista_Clientes();

private slots:
    void Boton_Regresar();
    void Boton_Eliminar();
    void Boton_Agregar();

private:
    Ui::Lista_Clientes *ui;
    Agregar_Paciente *Agregar_PacienteWindow;
    void LlenarDatos();
};

#endif // LISTA_CLIENTES_H
