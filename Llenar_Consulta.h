#ifndef LLENAR_CONSULTA_H
#define LLENAR_CONSULTA_H

#include <QDialog>

namespace Ui {
class Llenar_Consulta;
}

class Llenar_Consulta : public QDialog
{
    Q_OBJECT

public:
    explicit Llenar_Consulta(QWidget *parent = nullptr);
    ~Llenar_Consulta();

private:
    Ui::Llenar_Consulta *ui;
};

#endif // LLENAR_CONSULTA_H
