#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <QMainWindow>

namespace Ui {
class Inventario;
}

class Inventario : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inventario(QWidget *parent = nullptr);
    ~Inventario();

private slots:
    void Boton_Regresar();

private:
    Ui::Inventario *ui;
};

#endif // INVENTARIO_H
