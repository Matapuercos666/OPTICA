#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

#include "VentanaBaseMain.h"
#include "Usuario_Actual.h"
#include "Agregar_Paciente.h"
#include "Info_paciente.h"
#include <QFile>
#include <QMessageBox>

namespace Ui {

class Lista_Clientes;
}

class Lista_Clientes : public VentanaBaseMain
{
    Q_OBJECT

public:
    explicit Lista_Clientes(QWidget *parent = nullptr);
    ~Lista_Clientes();

private slots:
    void Boton_Regresar();
    void Boton_Eliminar();
    void Boton_Agregar();
    void abrirPerfil();
    void cerrarSesion();

private:
    Ui::Lista_Clientes *ui;
    Agregar_Paciente *Agregar_PacienteWindow;
    Info_paciente *INFOWINDOW;
    void LlenarDatos();
    void INFO(int row, int column);
};

#endif // LISTA_CLIENTES_H
