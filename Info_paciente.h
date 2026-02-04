#ifndef INFO_PACIENTE_H
#define INFO_PACIENTE_H

#include <QWidget>

namespace Ui {
class Info_paciente;
}

class Info_paciente : public QWidget
{
    Q_OBJECT

public:
    explicit Info_paciente(QWidget *parent = nullptr);
    void LLENAR_TODO(int idpaciente);
    ~Info_paciente();

private slots:
    void DobleClick(int row, int);
    void Boton_Cancelar();
    void Boton_Guardar();
    void Boton_Editar();
    void Boton_Agregar();

signals:
    void Actualizar();
    void goToLlenarConsulta(int idPaciente);

private:
    Ui::Info_paciente *ui;
    int ID;

    void LLenarDatos(int id);
    void LlenarConsultas();
    void LlenarDetalles(int CONSULTAID);

};

#endif // INFO_PACIENTE_H
