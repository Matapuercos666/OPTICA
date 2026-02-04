#ifndef MENU_H
#define MENU_H
#include "ui_Menu.h"
#include <QPointer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

signals:
    void goToLista();
    void goToVenta();
    void goToInventario();
    void goToUsuarios();

private slots:
    void Boton_Lista();
    void Boton_Punto();
    void Boton_Inventario();
    void Boton_Usuarios();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
