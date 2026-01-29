#ifndef LLENAR_CONSULTA_H
#define LLENAR_CONSULTA_H

#include "VentanaBase.h"

namespace Ui {
class Llenar_Consulta;
}

class Llenar_Consulta : public VentanaBase
{
    Q_OBJECT

public:
    explicit Llenar_Consulta(QWidget *parent = nullptr);
    ~Llenar_Consulta();

private:
    Ui::Llenar_Consulta *ui;
};

#endif // LLENAR_CONSULTA_H
