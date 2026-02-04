#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

#include <QWidget>
#include "Usuario_Actual.h"
#include <QFile>

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
    void verInfo(int id);

private:
    Ui::Lista_Clientes *ui;
    void LlenarDatos();
    void INFO(int row, int column);
};

#endif // LISTA_CLIENTES_H
