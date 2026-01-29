#ifndef ELIMINAR_USUARIOS_H
#define ELIMINAR_USUARIOS_H

#include "VentanaBaseMain.h"
#include <QTableWidget>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Eliminar_Usuarios;
}

class Eliminar_Usuarios : public VentanaBaseMain
{
    Q_OBJECT

public:
    explicit Eliminar_Usuarios(QWidget *parent = nullptr);
    ~Eliminar_Usuarios();

private slots:
    void Boton_Regresar();


private:
    Ui::Eliminar_Usuarios *ui;
};

#endif // ELIMINAR_USUARIOS_H
