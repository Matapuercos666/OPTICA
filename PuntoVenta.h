#ifndef PUNTOVENTA_H
#define PUNTOVENTA_H

#include <QWidget>

namespace Ui {
class PuntoVenta;
}

class PuntoVenta : public QWidget
{
    Q_OBJECT

public:
    explicit PuntoVenta(QWidget *parent = nullptr);
    ~PuntoVenta();

private slots:
    void Boton_Regresar();

private:
    Ui::PuntoVenta *ui;
};

#endif // PUNTOVENTA_H
