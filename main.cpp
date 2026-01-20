#include "ManejoDeData.h"
#include "LOGIN.h"

#include <QApplication>
#include "ESTILOS.h"
#include <QFontDatabase>
#include <QDebug>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ManejoDeData& data = ManejoDeData::instance();
    if(!data.abrir("DBJardines.db"))
    {
        QMessageBox::critical(nullptr, "Error", "no se encontro");
        return -1;
    }

    PaletaColores::inicializar(); //Precarga la paleta de colores
    Fuente::inicializar();        // <<--- Precarga las fuentes

    // Aplicar estilos globales
    a.setStyleSheet(QString("* {"
                            "   background-color: %1;"
                            "   color: %2;"
                            "}"
                            "QPushButton {"
                            "   font: bold 10pt 'Arial Black';"
                            "   background-color: %3;"
                            "   color: %4;"
                            "   border: 1px solid %5;"
                            "}"
                            "QLineEdit, QTextEdit, QPlainTextEdit {"
                            "   background-color: %6;"
                            "   color: %7;"
                            "   border: 1px solid %8;"
                            "}"
                            "QTableWidget, QTableView {"
                            "   background-color: %9;"
                            "   color: %10;"
                            "   border: 1px solid %11;"
                            "}"
                            "QToolButton {"
                            "   background-color: %12;"
                            "   color: %13;"
                            "   border: 1px solid %14;"
                            "}"
                            "QLabel#Titulo {" // Afecta a TODOS los QLabel con objectName="Titulo"
                            "   color: "
                            + PaletaColores::AzulMedio().name()
                            + ";"
                              "}")
                        .arg(PaletaColores::Gris().name())       // %1 posible fondo
                        .arg(PaletaColores::Negro().name())      // %2 texto general
                        .arg(PaletaColores::AzulFuerte().name()) // %3 fondo botón
                        .arg(PaletaColores::Blanco().name())     // %4 texto botón
                        .arg(PaletaColores::Negro().name())      // %5 borde botón
                        .arg(PaletaColores::AzulClaro().name())  // %6 fondo campos de texto
                        .arg(PaletaColores::Negro().name())      // %7 texto campos de texto
                        .arg(PaletaColores::Negro().name())      // %8 borde campos de texto
                        .arg(PaletaColores::Blanco().name())     // %9 fondo tablas
                        .arg(PaletaColores::Negro().name())      // %10 texto tablas
                        .arg(PaletaColores::Negro().name())      // %11 borde tablas
                        .arg(PaletaColores::Rojo().name())       // %12 fondo de los qtoolboton
                        .arg(PaletaColores::AzulFuerte().name()) // %13 figurita de los qtoolboton
                        .arg(PaletaColores::Negro().name())      // %14 borde qtoolboton
                    );
    LOGIN w;
    w.show();
    int ret = a.exec();
    ManejoDeData::instance().cerrar();
    return ret;
}
