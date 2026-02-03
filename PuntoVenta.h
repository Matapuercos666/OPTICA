#ifndef PUNTOVENTA_H
#define PUNTOVENTA_H

#include "VentanaBaseMain.h"

namespace Ui {
class PuntoVenta;
}

class PuntoVenta : public VentanaBaseMain
{
    Q_OBJECT

public:
    explicit PuntoVenta(QWidget *parent = nullptr);
    ~PuntoVenta();

private slots:
    void Boton_Regresar();
    void abrirPerfil();
    void cerrarSesion();

private:
    Ui::PuntoVenta *ui;
};

#endif // PUNTOVENTA_H
