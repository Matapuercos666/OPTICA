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
    connect(ui->ENTRAR, &QPushButton::clicked, this, &LOGIN::Boton_ENTRAR);
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::Boton_ENTRAR()
{
    QString usuarioIngresado = ui->Usuario->text().trimmed();
    QString contrasenaIngresada = ui->Contrasena->text();

    QString hashIngresado = encriptar(contrasenaIngresada);

    QFile archivo("USUARIOS.dat");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", QDir::currentPath());
        return;
    }

    QTextStream in(&archivo);
    Usuario usuarioValidado;
    bool encontrado = false;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        QStringList partes = linea.split(';');
        if (partes.size() != 3)
            continue;

        QString usuarioArchivo = partes[0];
        QString hashArchivo = partes[1];
        QString rolArchivo = partes[2];

        if (usuarioArchivo == usuarioIngresado && hashArchivo == hashIngresado) {
            usuarioValidado.nombre = usuarioArchivo;
            usuarioValidado.rol = rolArchivo;
            encontrado = true;
            break;
        }
    }

    archivo.close();

    if (encontrado) {
        QMessageBox::information(this, "Bienvenido", "Hola " + usuarioValidado.nombre + ", tu rol es: " + usuarioValidado.rol);

        // Aquí puedes pasar el rol a tu ventana principal
        MenuWindow = new Menu(this);
        MenuWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Acceso denegado", "Usuario o contraseña incorrectos.");
    }
}
