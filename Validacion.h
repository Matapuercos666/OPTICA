#ifndef VALIDACION_H
#define VALIDACION_H
#include <QDialog>
#include <QMessageBox>
#include "Usuario_Actual.h"
#include "ESTILOS.h"

namespace Ui{
class Validacion;
}

class Validacion : public QDialog
{
    Q_OBJECT

public:
    explicit Validacion(QWidget *parent = nullptr);

    ~Validacion();

    //Metodo estatico para facilitar su uso
    static bool ConfirmarPassword(QWidget *parent = nullptr);

    //Método para saber si fue validada correctamente
    bool passwordValidado() const {return m_passwordValidado;}

private slots:
    void BOTON_ACEPTAR();
    void BOTON_CANCELAR();

private:
    Ui::Validacion *ui;
    bool m_passwordValidado;

    void inicializar();
    bool validarPassword(const QString &password);
};

#endif // VALIDACION_H
