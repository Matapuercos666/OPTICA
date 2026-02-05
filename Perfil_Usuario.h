#ifndef PERFIL_USUARIO_H
#define PERFIL_USUARIO_H
#include "VentanaBase.h"


#include <QDialog>

namespace Ui {
class Perfil_Usuario;
}

class Perfil_Usuario : public VentanaBase
{
    Q_OBJECT

public:
    explicit Perfil_Usuario(QWidget *parent = nullptr);
    ~Perfil_Usuario();

private:
    Ui::Perfil_Usuario *ui;
};

#endif // PERFIL_USUARIO_H
