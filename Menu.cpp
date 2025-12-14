#include "Menu.h"
#include "ui_Menu.h"
#include "ESTILOS.h"
#include "Usuario_Actual.h"
#include <QString>

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
    , ListaWindow(nullptr)
    , Punto_Venta_Window(nullptr)
    , InventarioWindow(nullptr)
    , UsuariosWindow(nullptr)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);

    //Configurar la interfaz segun el rol
    Usuario_Actual* Datos = Usuario_Actual::obtenerinstancia();
    QString Nombre = Datos -> obtenernombre();

    if(!Datos -> EsAdmin())
    {
        ui->USUARIOS->setVisible(false);
    }

    //Conectar botones
    connect(ui->Lista, &QPushButton::clicked, this, &Menu::Boton_Lista);
    connect(ui->Punto, &QPushButton::clicked, this, &Menu::Boton_Punto);
    connect(ui->Inventario, &QPushButton::clicked, this, &Menu::Boton_Inventario);
    connect(ui->USUARIOS, &QPushButton::clicked, this, &Menu::Boton_Usuarios);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::Boton_Lista()
{
    if (!ListaWindow || ListaWindow->isHidden())
    {
        if(ListaWindow)
        {
            delete ListaWindow;
        }
        ListaWindow = new Lista_Clientes(parentWidget());
        ListaWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(ListaWindow, &QObject::destroyed, this, [this]() { ListaWindow = nullptr; });
    }
    ListaWindow->show();
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
}

void Menu::Boton_Usuarios()
{
    if (!UsuariosWindow || UsuariosWindow->isHidden())
    {
        if(UsuariosWindow)
        {
            delete UsuariosWindow;
        }
        UsuariosWindow = new USUARIOS(this);
        UsuariosWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(UsuariosWindow, &QObject::destroyed, this, [this]() { UsuariosWindow = nullptr; });
    }
    UsuariosWindow->show();
    this->hide();
}
