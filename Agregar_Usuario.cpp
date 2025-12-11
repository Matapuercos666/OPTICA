#include "Agregar_Usuario.h"
#include "ui_Agregar_Usuario.h"
#include <QDir>
#include <QMessageBox>

Agregar_Usuario::Agregar_Usuario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Agregar_Usuario)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    connect(ui->AGREGAR, &QPushButton::clicked, this, &Agregar_Usuario::BOTON_ACEPTAR);
    connect(ui->CANCELAR, &QPushButton::clicked, this, &Agregar_Usuario::BOTON_CANCELAR);
}

Agregar_Usuario::~Agregar_Usuario()
{
    delete ui;
}

void Agregar_Usuario::BOTON_ACEPTAR()
{

    if(!ui->USUARIO->text().isEmpty() && !ui->PASSWORD1->text().isEmpty() && !ui->PASSWORD2->text().isEmpty())
    {
        QString usuarioIngresado = ui->USUARIO->text().trimmed();
        QString passwordIngresado = encriptar(ui->PASSWORD1->text());
        QString confirmarPassword = encriptar(ui->PASSWORD2->text());
        QString Rol;
        if(ui->CheckAdmin->isChecked())
        {
            Rol = "Administrador";
        }else Rol = "Empleado";

        QFile archivo("USUARIOS.dat");

        if (!archivo.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::critical(this, "ERROR", "No se pudo abrir el archivo de usuarios");
            return;
        }

        bool usuarioNuevo = true;
        QTextStream in(&archivo);

        while (!in.atEnd()) {
            QString linea = in.readLine().trimmed();
            QStringList partes = linea.split(';');
            if (partes.size() != 3) continue;

            if (partes[0] == usuarioIngresado) {

                usuarioNuevo = false;
                break;
            }
        }

        if(usuarioNuevo)
        {
            if(passwordIngresado == confirmarPassword)
            {
                in << usuarioIngresado << ";" << passwordIngresado << ";" << Rol <<"\n";
                QMessageBox::about(this, "EXITO", "Usuario Creado exitosamente.");
                archivo.close();
                this->close();
            }else{
                ui->PASSWORD1->clear();
                ui->PASSWORD2->clear();
                ui->PASSWORD1->setFocus();
                QMessageBox::critical(this, "ERROR", "Las contraseñas no coinciden");
            }
        }else{
            ui->USUARIO->setFocus();
            QMessageBox::critical(this, "ERROR", "usuario ya existe");
        }
        archivo.close();
    }else{
        if(ui->USUARIO->text().isEmpty())
        {
            ui->USUARIO->setFocus();
        }else{
            if(ui->PASSWORD1->text().isEmpty())
            {
                ui->PASSWORD1->setFocus();
            }else{
                ui->PASSWORD2->setFocus();
            }
        }
        QMessageBox::information(this, "Campos Vacíos", "Rellena Los Campos Faltantes...");
    }

}

void Agregar_Usuario::BOTON_CANCELAR()
{
    reject();
}
