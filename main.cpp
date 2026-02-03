#include "ManejoDeData.h"
#include "LOGIN.h"
#include "Menu.h"
#include "Lista_Clientes.h"
#include "Agregar_Paciente.h"
#include "Agregar_Usuario.h"
#include "Cambiar_Nombre.h"
#include "Cambiar_Password.h"
#include "Info_paciente.h"
#include "Inventario.h"
#include "Llenar_Consulta.h"
#include "PuntoVenta.h"
#include "USUARIOS.h"


#include <QApplication>
#include "ESTILOS.h"
#include <QFontDatabase>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#include <QIcon>
#include "mainshell.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/IMAGENES/IMAGENES/LOGOS/LOGO.png"));

    // Inicialización de la base de datos
    ManejoDeData& data = ManejoDeData::instance();
    if(!data.abrir("DBJardines.db")) {
        QMessageBox::critical(nullptr, "Error", "No se encontró la base de datos");
        return -1;
    }

    // Inicializar paleta de colores y fuentes (ESTILOS.h)
    PaletaColores::inicializar();
    Fuente::inicializar();


    // Cargar y aplicar la hoja de estilos global desde recursos

    QFile archivoEstilos(":/ESTILOS/ESTILOS/Estilos.qss");

    if (!archivoEstilos.exists()) {
        qWarning() << "[ERROR] El archivo de recursos Estilos.qss no existe en la ruta especificada.";
        qWarning() << "Verifica que el archivo esté añadido al .qrc y que el prefijo sea correcto.";
    }

    if (archivoEstilos.open(QFile::ReadOnly)) {
        QString estiloBase = QLatin1String(archivoEstilos.readAll());
        archivoEstilos.close();

        // Reemplazar placeholders %1 a %15 con los colores de la paleta
        QString estiloCompleto = estiloBase
                                     .arg(PaletaColores::Gris().name())        // %1
                                     .arg(PaletaColores::Negro().name())       // %2
                                     .arg(PaletaColores::AzulFuerte().name())  // %3
                                     .arg(PaletaColores::Blanco().name())      // %4
                                     .arg(PaletaColores::Negro().name())       // %5
                                     .arg(PaletaColores::AzulClaro().name())   // %6
                                     .arg(PaletaColores::Negro().name())       // %7
                                     .arg(PaletaColores::Negro().name())       // %8
                                     .arg(PaletaColores::Blanco().name())      // %9
                                     .arg(PaletaColores::Negro().name())       // %10
                                     .arg(PaletaColores::Negro().name())       // %11
                                     .arg(PaletaColores::Rojo().name())        // %12
                                     .arg(PaletaColores::AzulFuerte().name())  // %13
                                     .arg(PaletaColores::Negro().name())       // %14
                                     .arg(PaletaColores::AzulMedio().name());  // %15

        // Aplicar la hoja de estilos completa y correctamente formada
        a.setStyleSheet(estiloCompleto);

    } else {
        qWarning() << "[ERROR] No se pudo abrir el archivo Estilos.qss para lectura.";
        qWarning() << "Motivo:" << archivoEstilos.errorString();
    }

    //crear ventana unica

    MainShell shell;

    //vistas de los widgets

    LOGIN *loginView = new LOGIN(&shell);
    Menu *menuView = new Menu(&shell);
    Agregar_Paciente *agregarPacienteView = new Agregar_Paciente(&shell);
    Agregar_Usuario *agregarUsuarioView = new Agregar_Usuario(&shell);
    Cambiar_Nombre *cambiarNombreView = new Cambiar_Nombre(&shell);
    Cambiar_Password *cambiarPasswordView = new Cambiar_Password(&shell);
    Eliminar_Usuarios *eliminarUsuariosView = new Eliminar_Usuarios(&shell);
    Info_paciente *infoPacienteView = new Info_paciente(&shell);
    Inventario *inventarioView = new Inventario(&shell);
    Lista_Clientes *listaClientesView = new Lista_Clientes(&shell);
    Llenar_Consulta *llenarConsultaView = new Llenar_Consulta(&shell);
    PuntoVenta *puntoVentaView = new PuntoVenta(&shell);
    USUARIOS *usuariosView = new USUARIOS(&shell);

    //agregar las vistas a la ventana principal

    shell.addView(loginView, "Iniciar sesión");                  //indice 0
    shell.addView(menuView, "Menú");                             //indice 1
    shell.addView(agregarPacienteView, "Agregar Paciente");      //indice 2
    shell.addView(agregarUsuarioView, "Usuario Nuevo");          //indice 3
    shell.addView(cambiarNombreView, "Cambiar nombre");          //indice 4
    shell.addView(cambiarPasswordView, "Cambiar Contraseña");    //indice 5
    shell.addView(eliminarUsuariosView, "Eliminar Usuario");     //indice 6
    shell.addView(infoPacienteView, "Información de paciente");  //indice 7
    shell.addView(inventarioView, "Inventario");                 //indice 8
    shell.addView(listaClientesView, "Pacientes");               //indice 9
    shell.addView(llenarConsultaView, "Consulta");               //indice 10
    shell.addView(puntoVentaView, "Venta");                      //indice 11
    shell.addView(usuariosView, "Menú usuario");                 //indice 12

    //señales de navegacion por indice

    QObject::connect(loginView, &LOGIN::loginSuccessful, &shell, [&shell](){
        shell.pushView(1);
    });

    QObject::connect(menuView, &Menu::goToLista, &shell, [&shell](){ shell.pushView(9);});
    QObject::connect(menuView, &Menu::goToVenta, &shell, [&shell](){ shell.pushView(11);});
    QObject::connect(menuView, &Menu::goToUsuarios, &shell, [&shell](){ shell.pushView(12);});
    QObject::connect(menuView, &Menu::goToInventario, &shell, [&shell](){ shell.pushView(8);});

    QObject::connect(listaClientesView, &Lista_Clientes::agregarPaciente, &shell, [&shell](){ shell.pushView(2);});



    QObject::connect(agregarPacienteView, &Agregar_Paciente::goToLLenarConsulta, &shell, [&shell, llenarConsultaView](int idPaciente){ llenarConsultaView->setIdPaciente(idPaciente);
    shell.pushView(10);
    });

    QObject::connect(agregarPacienteView, &Agregar_Paciente::pacienteAgregado, &shell, &MainShell::popView);



    shell.show();

    int ret = a.exec();
    ManejoDeData::instance().cerrar();
    return ret;
}

