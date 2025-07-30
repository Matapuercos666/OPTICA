#include "Menu.h"
#include "ui_Menu.h"
#include "ESTILOS.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
    , ListaWindow(nullptr)
    , Punto_Venta_Window(nullptr)
    , InventarioWindow(nullptr)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    ui->botones->setSpacing(20);

    //Conectar botones
    connect(ui->Lista, &QPushButton::clicked, this, &Menu::Boton_Lista);
    connect(ui->Punto, &QPushButton::clicked, this, &Menu::Boton_Punto);
    connect(ui->Inventario, &QPushButton::clicked, this, &Menu::Boton_Inventario);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::configurarInterfazSegunRol(const QString &Rol, const QString &Nombre)
{
    bool EsAdmin = (Rol == "Administrador");

    ui->USUARIOS->setVisible(EsAdmin);
}

void Menu::Boton_Lista()
{
    if (!ListaWindow || ListaWindow->isHidden())
    {
        if(ListaWindow)
        {
            delete ListaWindow;
        }
        ListaWindow = new Lista_Clientes(this);
        ListaWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(ListaWindow, &QObject::destroyed, this, [this]() { ListaWindow = nullptr; });
    }
    ListaWindow->show();
    this->hide();
}

void Menu::Boton_Punto()
{
    if (!Punto_Venta_Window || Punto_Venta_Window->isHidden())
    {
        if (Punto_Venta_Window)
        {
            delete Punto_Venta_Window;
        }
        Punto_Venta_Window = new PuntoVenta(this);  // Se hace padre de la ventana punto de venta para poder recuperar la referencia
        Punto_Venta_Window->setAttribute(Qt::WA_DeleteOnClose);
        connect(Punto_Venta_Window, &QObject::destroyed, this, [this]() { Punto_Venta_Window = nullptr; });
    }
    Punto_Venta_Window->show();
    this->hide();
}

void Menu::Boton_Inventario()
{
    if (!InventarioWindow || InventarioWindow->isHidden())
    {
        if(InventarioWindow)
        {
            delete InventarioWindow;
        }
        InventarioWindow = new Inventario(this);
        InventarioWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(InventarioWindow, &QObject::destroyed, this, [this]() { InventarioWindow = nullptr; });
    }
    InventarioWindow->show();
    this->hide();
}
