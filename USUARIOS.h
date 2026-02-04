#ifndef USUARIOS_H
#define USUARIOS_H

#include <QWidget>
#include <QPointer>


namespace Ui {
class USUARIOS;
}

class USUARIOS : public QWidget
{
    Q_OBJECT

public:
    explicit USUARIOS(QWidget *parent = nullptr);
    ~USUARIOS();

signals:
    void cambiarPassword();
    void cambiarNombre();
    void eliminarUsuario();
    void agregarUsuario();

private slots:
    void Boton_CambiarPassword();
    void Boton_CambiarNombre();
    void Boton_Eliminar();
    void Boton_AgregarUsuario();

private:
    Ui::USUARIOS *ui;

};

#endif // USUARIOS_H
