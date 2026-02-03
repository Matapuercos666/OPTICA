#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "VentanaBaseMain.h"

namespace Ui {
class Inventario;
}

class Inventario : public VentanaBaseMain
{
    Q_OBJECT

public:
    explicit Inventario(QWidget *parent = nullptr);
    ~Inventario();

private slots:
    void Boton_Regresar();
    void abrirPerfil();
    void cerrarSesion();

private:
    Ui::Inventario *ui;
};

#endif // INVENTARIO_H
