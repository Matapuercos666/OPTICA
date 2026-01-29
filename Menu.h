#ifndef MENU_H
#define MENU_H

#include "VentanaBaseMain.h"
#include <QPointer>
#include "Lista_Clientes.h"
#include "PuntoVenta.h"
#include "Inventario.h"
#include "USUARIOS.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Menu;
}
QT_END_NAMESPACE

class Menu : public VentanaBaseMain
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void Boton_Lista();
    void Boton_Punto();
    void Boton_Inventario();
    void Boton_Usuarios();

private:
    Ui::Menu *ui;
    //punteros a nuevas ventanas
    Lista_Clientes *ListaWindow;
    PuntoVenta *Punto_Venta_Window;
    Inventario *InventarioWindow;
    USUARIOS *UsuariosWindow;
};

#endif // MENU_H
