#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H

#include "Usuario_Actual.h"
#include <QFile>
#include <QMessageBox>

#include <QWidget>

namespace Ui {

class Lista_Usuarios;
}

class Lista_Usuarios : public QWidget
{
    Q_OBJECT
public:
    explicit Lista_Usuarios(QWidget *parent = nullptr);
     ~Lista_Usuarios();

private:
     Ui::Lista_Usuarios *ui;

};

#endif // LISTA_USUARIOS_H
