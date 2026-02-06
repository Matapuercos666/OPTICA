#ifndef INVENTARIO_USUARIO_H
#define INVENTARIO_USUARIO_H

#include <QDialog>

namespace Ui {
class Inventario_Usuario;
}

class Inventario_Usuario : public QDialog
{
    Q_OBJECT

public:
    explicit Inventario_Usuario(QWidget *parent = nullptr);
    ~Inventario_Usuario();

private:
    Ui::Inventario_Usuario *ui;
};

#endif // INVENTARIO_USUARIO_H
