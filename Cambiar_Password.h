#ifndef CAMBIAR_PASSWORD_H
#define CAMBIAR_PASSWORD_H

#include "VentanaBase.h"
#include "ESTILOS.h"
#include <QFile>

namespace Ui {
class Cambiar_Password;
}

class Cambiar_Password : public VentanaBase
{
    Q_OBJECT

public:
    explicit Cambiar_Password(QWidget *parent = nullptr);
    ~Cambiar_Password();

private:
    Ui::Cambiar_Password *ui;
};


#endif // CAMBIAR_PASSWORD_H
