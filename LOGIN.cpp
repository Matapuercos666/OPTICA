#include "LOGIN.h"
#include "ui_LOGIN.h"
#include <QDebug>
#include <QLabel>
#include "ESTILOS.h"
#include "Utils.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <Menu.h>
#include "Usuario_Actual.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include "ManejoDeData.h"
#include "VentanaBaseMain.h"


LOGIN::LOGIN(QWidget *parent)
    : VentanaBaseMain(parent)
    , ui(new Ui::LOGIN)
    , MenuWindow(nullptr)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);

    ui->Usuario->setFocus();

    connect(ui->ENTRAR, &QPushButton::clicked, this, &LOGIN::Boton_ENTRAR);
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::Boton_ENTRAR()
{
    bool autorizacion = false;
    Usuario Actual;
    if(!ui->Usuario->text().isEmpty() && !ui->password->text().isEmpty())
    {
        QString usuarioIngresado = ui->Usuario->text().trimmed();
        QString contrasenaIngresada = encriptar(ui->password->text());

        bool EsNumero;

        int IDNumerico = usuarioIngresado.toInt(&EsNumero);

        if(EsNumero)
        {
            Actual = BuscarID(IDNumerico);
            autorizacion = (contrasenaIngresada == Actual.PASS);
        }else
        {
            Actual = BuscarUsuario(usuarioIngresado);
            autorizacion = (contrasenaIngresada == Actual.PASS);
        }

        if(!autorizacion)
        {
            QMessageBox::critical(nullptr, "Error", "Algún campo o ambos son incorrectos");
            ui->Usuario->clear();
            ui->password->clear();
            ui->Usuario->setFocus();
        }
    } else
    {
        if(ui->Usuario->text().isEmpty() && ui->password->text().isEmpty())
        {
            ui->Usuario->setFocus();
        }
        else
        {
            if(ui->Usuario->text().isEmpty())
            {
                QMessageBox::critical(nullptr, "Error", "Por favor introduce tu nombre de usuario o numero de empleado");
                ui->Usuario->setFocus();
            }else{

                QMessageBox::critical(nullptr, "Error", "Por favor introduce tu contraseña");
                ui->password->setFocus();
            }
        }
    }

    if(autorizacion)
    {
        Usuario_Actual *actual = Usuario_Actual::obtenerinstancia();
        actual->establecerusuario(Actual.nombre, Actual.rol, Actual.PASS, QString::number(Actual.ID));
        if (!MenuWindow || MenuWindow->isHidden())
        {
            if(MenuWindow)
            {
                delete MenuWindow;
            }
            MenuWindow = new Menu(parentWidget());
            MenuWindow->setAttribute(Qt::WA_DeleteOnClose);
            connect(MenuWindow, &QObject::destroyed, this, [this]() { MenuWindow = nullptr; });
        }
        MenuWindow->show();
        this->hide();
    }
}

Usuario LOGIN::BuscarID(int IDNumero)
{
    Usuario Puntero;

    QSqlQuery query;
    query.clear();
    query.prepare("SELECT PASS, USUARIO, PUESTO, ID FROM EMPLEADOS WHERE ID = ?");
    query.addBindValue(IDNumero);

    if(query.exec() && query.next())
    {
        Puntero.PASS = query.value(0).toString();
        Puntero.nombre = query.value(1).toString();
        Puntero.rol = query.value(2).toString();
        Puntero.ID = query.value(3).toInt();
        return Puntero;
    }else{

        return Usuario();
    }
}

Usuario LOGIN::BuscarUsuario(const QString& NombreUsuario)
{
    Usuario Puntero;

    QSqlQuery q;
    q.clear();
    q.prepare("SELECT PASS, USUARIO, PUESTO, ID FROM EMPLEADOS WHERE USUARIO = ?");
    q.addBindValue(NombreUsuario);

    if(q.exec() && q.next())
    {
        Puntero.PASS = q.value(0).toString();
        Puntero.nombre = q.value(1).toString();
        Puntero.rol = q.value(2).toString();
        Puntero.ID = q.value(3).toInt();
        return Puntero;
    }
    return Usuario();
}
