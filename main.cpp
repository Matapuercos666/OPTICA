#include "ManejoDeData.h"
#include "LOGIN.h"

#include <QApplication>
#include "ESTILOS.h"
#include <QFontDatabase>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#include <QIcon>

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
    LOGIN w;
    w.show();

    int ret = a.exec();
    ManejoDeData::instance().cerrar();
    return ret;
}

