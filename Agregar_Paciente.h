#ifndef AGREGAR_PACIENTE_H
#define AGREGAR_PACIENTE_H

#include <QWidget>
#include "Llenar_Consulta.h"

namespace Ui {
class Agregar_Paciente;
}

class Agregar_Paciente : public QWidget
{
    Q_OBJECT

public:
    explicit Agregar_Paciente(QWidget *parent = nullptr);
    ~Agregar_Paciente();

signals:
    void pacienteAgregado();
    void goToLlenarConsulta(int idPaciente);

private slots:
    void Boton_Agregar();
    void Boton_Cancelar();

private:
    Ui::Agregar_Paciente *ui;
};

#endif // AGREGAR_PACIENTE_H
