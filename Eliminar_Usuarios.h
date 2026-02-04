#ifndef ELIMINAR_USUARIOS_H
#define ELIMINAR_USUARIOS_H

#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Eliminar_Usuarios;
}

class Eliminar_Usuarios : public QWidget
{
    Q_OBJECT

public:
    explicit Eliminar_Usuarios(QWidget *parent = nullptr);
    ~Eliminar_Usuarios();

private:
    Ui::Eliminar_Usuarios *ui;
};

#endif // ELIMINAR_USUARIOS_H
