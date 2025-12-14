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

struct Usuario {
    QString nombre;
    QString rol;
};

LOGIN::LOGIN(QWidget *parent)
    : QMainWindow(parent)
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
    if(!ui->Usuario->text().isEmpty() && !ui->password->text().isEmpty())
    {
        QString usuarioIngresado = ui->Usuario->text().trimmed();
        QString contrasenaIngresada = encriptar(ui->password->text());

        QFile archivo("USUARIOS.dat");
        if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "No se pudo abrir el archivo de usuarios.");
            return;
        }

        QTextStream in(&archivo);
        bool loginCorrecto = false;
        QString Rol;
        QString Nombre;
        QString Password;
        QString ID;

        while (!in.atEnd()) {
            QString linea = in.readLine().trimmed();
            QStringList partes = linea.split(';');
            if (partes.size() != 4) continue;

            if ((partes[3] == contrasenaIngresada) && (partes[0] ==usuarioIngresado || partes[1] == usuarioIngresado)) {
                ID = partes[0];
                Nombre = partes[1];
                Rol = partes[2];
                Password = partes[3];
                loginCorrecto = true;
                break;
            }
        }

        archivo.close();

        if (loginCorrecto) {
            Usuario_Actual::obtenerinstancia()->establecerusuario(Nombre, Rol, Password, ID);
            ui->Usuario->clear();
            ui->password->clear();
            ui->Usuario->setFocus();
            MenuWindow = new Menu(nullptr);
            MenuWindow->show();
            this->close();
        } else {
            ui->Usuario->clear();
            ui->password->clear();
            ui->Usuario->setFocus();
            QMessageBox::warning(this, "Acceso denegado", "Usuario o contrseña incorrecto...");
        }
    }else{
        if(ui->Usuario->text().isEmpty())
        {
            ui->Usuario->setFocus();
        }else ui->password->setFocus();
        QMessageBox::information(this, "Campos vacíos", "Por Favor Rellena Los Campos Faltantes...");
    }
}
