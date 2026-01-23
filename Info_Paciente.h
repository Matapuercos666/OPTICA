#ifndef INFO_PACIENTE_H
#define INFO_PACIENTE_H

#include <QDialog>

namespace Ui {
class Info_Paciente;
}

class Info_Paciente : public QDialog
{
    Q_OBJECT

public:
    explicit Info_Paciente(QWidget *parent = nullptr);
    ~Info_Paciente();

private:
    Ui::Info_Paciente *ui;
};

#endif // INFO_PACIENTE_H
