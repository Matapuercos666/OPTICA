#ifndef LLENAR_CONSULTA_H
#define LLENAR_CONSULTA_H

#include <QWidget>

namespace Ui {
class Llenar_Consulta;
}

class Llenar_Consulta : public QWidget
{
    Q_OBJECT

public:
    explicit Llenar_Consulta(int PACIENTEID, QWidget *parent = nullptr);
    ~Llenar_Consulta();

private slots:
    void Boton_Cancelar();
    void Boton_Aceptar();
signals:
    void señalAceptar();
private:
    Ui::Llenar_Consulta *ui;
    bool Campo_Lleno();
    int ID;
};

#endif // LLENAR_CONSULTA_H
