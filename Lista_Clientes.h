#ifndef LISTA_CLIENTES_H
#define LISTA_CLIENTES_H

#include <QMainWindow>
#include "Usuario_Actual.h"
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

private:
    Ui::Lista_Clientes *ui;
    void LlenarDatos();
};

#endif // LISTA_CLIENTES_H
