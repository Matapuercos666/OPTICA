#ifndef MENU_H
#define MENU_H

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

private slots:
    void Boton_Lista();
    void Boton_Punto();
    void Boton_Inventario();

signals:
    void goToLista();
    void goToVenta();
    void goToInventario();

private:
    Ui::Menu *ui;

};

#endif // MENU_H
