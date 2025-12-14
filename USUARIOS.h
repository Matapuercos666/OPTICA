#ifndef USUARIOS_H
#define USUARIOS_H

#include <QMainWindow>
#include "Validacion.h"
#include <QPointer>
#include "Cambiar_Password.h"
#include "Cambiar_Nombre.h"
#include "Eliminar_Usuarios.h"
#include "Agregar_Usuario.h"

namespace Ui {
class USUARIOS;
}

class USUARIOS : public QMainWindow
{
    Q_OBJECT

public:
    explicit USUARIOS(QWidget *parent = nullptr);
    ~USUARIOS();

private slots:
    void Boton_CambiarPassword();
    void Boton_CambiarNombre();
    void Boton_Eliminar();
    void Boton_AgregarUsuario();
    void Boton_Regresar();

private:
    Ui::USUARIOS *ui;
    //Punteros a siguientes ventanas(no sin antes pasar por validación)
    Cambiar_Password *CambiarContrasenaWindow;
    Cambiar_Nombre *CambiarNombreWindow;
    Eliminar_Usuarios *EliminarWindow;
    Agregar_Usuario *AgregarWindow;
};

#endif // USUARIOS_H
