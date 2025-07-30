#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPointer>
#include "Lista_Clientes.h"
#include "PuntoVenta.h"
#include "Inventario.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    void configurarInterfazSegunRol(const QString &Rol, const QString &Nombre);

private slots:
    void Boton_Lista();
    void Boton_Punto();
    void Boton_Inventario();

private:
    Ui::Menu *ui;
    //punteros a nuevas ventanas
    Lista_Clientes *ListaWindow;
    PuntoVenta *Punto_Venta_Window;
    Inventario *InventarioWindow;
};

#endif // MENU_H
