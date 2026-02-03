#ifndef CAMBIAR_NOMBRE_H
#define CAMBIAR_NOMBRE_H

#include <QWidget>

namespace Ui {
class Cambiar_Nombre;
}

class Cambiar_Nombre : public QWidget
{
    Q_OBJECT

public:
    explicit Cambiar_Nombre(QWidget *parent = nullptr);
    ~Cambiar_Nombre();

private:
    Ui::Cambiar_Nombre *ui;
};

#endif // CAMBIAR_NOMBRE_H
