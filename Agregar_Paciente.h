#ifndef AGREGAR_PACIENTE_H
#define AGREGAR_PACIENTE_H

#include "VentanaBase.h"
#include "Llenar_Consulta.h"

namespace Ui {
class Agregar_Paciente;
}

class Agregar_Paciente : public VentanaBase
{
    Q_OBJECT

public:
    explicit Agregar_Paciente(QWidget *parent = nullptr);
    ~Agregar_Paciente();

signals:
    void Actualizar();

private slots:
    void Boton_Agregar();
    void Boton_Cancelar();

private:
    Ui::Agregar_Paciente *ui;
};

#endif // AGREGAR_PACIENTE_H
