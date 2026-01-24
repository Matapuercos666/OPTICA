#ifndef INFO_PACIENTE_H
#define INFO_PACIENTE_H

#include <QDialog>

namespace Ui {
class Info_paciente;
}

class Info_paciente : public QDialog
{
    Q_OBJECT

public:
    explicit Info_paciente(QWidget *parent = nullptr);
    ~Info_paciente();

private:
    Ui::Info_paciente *ui;
};

#endif // INFO_PACIENTE_H
