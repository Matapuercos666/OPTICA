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

private:
    Ui::Info_paciente *ui;
};

#endif // INFO_PACIENTE_H
