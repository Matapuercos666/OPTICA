#ifndef INFO_PACIENTE_H
#define INFO_PACIENTE_H

#include "VentanaBase.h"

namespace Ui {
class Info_paciente;
}

class Info_paciente : public VentanaBase
{
    Q_OBJECT

public:
    explicit Info_paciente(int PACIENTEID, QWidget *parent = nullptr);
    ~Info_paciente();

private slots:
    void DobleClick(int row, int);
    void Boton_Cancelar();
    void Boton_Guardar();
    void Boton_Editar();
    void Boton_Agregar();

signals:
    void Actualizar();

private:
    Ui::Info_paciente *ui;
    int ID;

    void LLenarDatos();
    void LlenarConsultas();
    void LlenarDetalles(int CONSULTAID);

};

#endif // INFO_PACIENTE_H
