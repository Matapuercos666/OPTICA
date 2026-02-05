#include "Menu.h"
#include "ui_Menu.h"
#include "ESTILOS.h"
#include "Usuario_Actual.h"
#include <QString>


Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)

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
}

Menu::~Menu()
{
    delete ui;
}

void Menu::Boton_Lista()
{
    emit goToLista();
}

void Menu::Boton_Punto()
{
    emit goToVenta();
}

void Menu::Boton_Inventario()
{
    emit goToInventario();
}


