#ifndef AGREGAR_USUARIO_H
#define AGREGAR_USUARIO_H

#include <QDialog>
#include <QDebug>
#include "ESTILOS.h"
#include <QFile>
#include "Utils.h"

namespace Ui {
class Agregar_Usuario;
}

class Agregar_Usuario : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar_Usuario(QWidget *parent = nullptr);
    ~Agregar_Usuario();

private slots:
    void BOTON_ACEPTAR();
    void BOTON_CANCELAR();

private:
    Ui::Agregar_Usuario *ui;
};

#endif // AGREGAR_USUARIO_H
