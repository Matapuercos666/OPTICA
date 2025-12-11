#include "Validacion.h"
#include "ui_Validacion.h"
#include "Utils.h"
#include <QPushButton>

Validacion::Validacion(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Validacion),
    m_passwordValidado(false)
{
    ui->setupUi(this);
    Fuente::AplicarTodas(this);
    inicializar();
}

Validacion::~Validacion()
{
    delete ui;
}

void Validacion::inicializar()
{
    //obtener instancia
    Usuario_Actual* Usuario = Usuario_Actual::obtenerinstancia();
    //configurar modo modal
    ui->NombreUsuario->setText(Usuario->obtenernombre());
    setModal(true);

    //conexión de señales

    connect(ui->ACEPTAR, &QPushButton::clicked, this, &Validacion::BOTON_ACEPTAR);
    connect(ui->CANCELAR, &QPushButton::clicked, this, &Validacion::BOTON_CANCELAR);
}

bool Validacion::validarPassword(const QString &password)
{
    //obtenemos la contraseña del usuario actual
    Usuario_Actual *Usuario = Usuario_Actual::obtenerinstancia();
    if(!Usuario)
    {
        QMessageBox::critical(this, "Error", "No se pudo obtener la información del usuario");
        return false;
    }
    //comparar con la contraseña del usuario
    QString password_actual = Usuario->obtenerpassword();

    return(password == password_actual);
}

void Validacion::BOTON_ACEPTAR()
{
    if(!ui->Password->text().isEmpty())
    {
        QString password = encriptar(ui->Password->text());

        if(validarPassword(password))
        {
            m_passwordValidado = true;
            accept(); //cierra el dialogo con resultado accept
        } else
        {
            //contraseña incorrecta
            //limpiar el campo y dar foco
            ui->Password->clear();
            ui->Password->setFocus();
            QMessageBox::critical(this, "ERRROR", "Contraseña incorrecta...");
        }
    }else{
        QMessageBox::information(this, "Vacío", "Por favor llena el campo...");
    }
}

void Validacion::BOTON_CANCELAR()
{
    m_passwordValidado = false;
    reject();//cierra el dialogo con resultado reject
}

bool Validacion::ConfirmarPassword(QWidget *parent)
{
    Validacion Val_Actual(parent);
    //ejecutar dialogo modal
    int resultado=Val_Actual.exec();
    return (resultado == QDialog::Accepted && Val_Actual.passwordValidado());
}
