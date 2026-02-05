#ifndef HISTORIAL_CAJA_H
#define HISTORIAL_CAJA_H
#include "VentanaBase.h"


#include <QDialog>

namespace Ui {
class Historial_Caja;
}

class Historial_Caja : public VentanaBase
{
    Q_OBJECT

public:
    explicit Historial_Caja(QWidget *parent = nullptr);
    ~Historial_Caja();

private:
    Ui::Historial_Caja *ui;
};

#endif // HISTORIAL_CAJA_H
