#ifndef ESTILOS_H
#define ESTILOS_H

#include <QColor>
#include <QMap>
#include <QString>              //Para Paleta De Colores


#include <QFont>
#include <QFontDatabase>
#include <QDebug>
#include <QWidget>
#include <QLabel>               //Para Fuentes

class PaletaColores {           //Paleta de colores
public:
    // Llama a este método UNA SOLA VEZ al iniciar la app
    static void inicializar() {
        if (inicializado) return;
        ColorAzulM      = QColor(69, 123, 157);     //Azul Mediano
        ColorAzulF      = QColor(29, 53, 87);       //Azul Fuerte
        ColorAzulC      = QColor(168, 218, 220);    //Azul Claro
        ColorBlanco     = QColor(241, 250, 238);    //Blanco
        ColorRojo       = QColor(218, 50, 24);      //Rojo
        ColorNegro      = QColor(0, 0, 0);            //Negro
        ColorGris       = QColor(211, 211, 211);     //gris

        inicializado = true;
    }

    static QColor AzulMedio()       { return ColorAzulM; }
    static QColor AzulFuerte()      { return ColorAzulF; }
    static QColor AzulClaro()       { return ColorAzulC; }
    static QColor Blanco()          { return ColorBlanco; }
    static QColor Rojo()            { return ColorRojo; }
    static QColor Negro()           { return ColorNegro; }
    static QColor Gris()            { return ColorGris; }

private:
    static inline QColor ColorAzulM;
    static inline QColor ColorAzulF;
    static inline QColor ColorAzulC;
    static inline QColor ColorBlanco;
    static inline QColor ColorRojo;
    static inline QColor ColorNegro;
    static inline QColor ColorGris;

    static inline bool inicializado = false;
};





class Fuente {              //Fuentes
public:
    // Llama a este método UNA SOLA VEZ al iniciar
    static void inicializar() {
        if (inicializado) return;
        // Precarga fuentes con tamaños estándar
        fuenteTitulo     = cargarFuente(":/FUENTES/FUENTES/Playfair/static/Playfair_9pt_SemiCondensed-Bold.ttf", 48);
        fuenteSubtitulo  = cargarFuente(":/FUENTES/FUENTES/Raleway/static/Raleway-ExtraLight.ttf", 20);
        fuentePie        = cargarFuente(":/FUENTES/FUENTES/Montserrat/static/Montserrat-Italic.ttf", 9);
        fuenteEtiqueta   = cargarFuente(":/FUENTES/FUENTES/Lato/Lato-Thin.ttf", 9);
        fuenteDescripcion= cargarFuente(":/FUENTES/FUENTES/Roboto_Condensed/static/RobotoCondensed-Regular.ttf", 48);
        inicializado = true;
    }

    static QFont titulo()     { return fuenteTitulo; }
    static QFont subtitulo()  { return fuenteSubtitulo; }
    static QFont etiqueta()   { return fuenteEtiqueta; }
    static QFont descripcion(){ return fuenteDescripcion; }
    static QFont pie()        { return fuentePie; }

    //Funciones para aplicar estas fuentes:

    static void AplicarFuenteTitulo(QWidget *ventana) {
        // Busca todos los QLabel con objectName == "Titulo" de forma recursiva
        QList<QLabel*> titulos = ventana->findChildren<QLabel*>("Titulo", Qt::FindChildrenRecursively);
        for (QLabel* lbl : titulos) {
            lbl->setFont(Fuente::titulo());
        }
    }

    static void AplicarFuenteCEO(QWidget *ventana) {
        QList<QLabel*> ceos = ventana->findChildren<QLabel*>("CEO", Qt::FindChildrenRecursively);
        for (QLabel* lbl : ceos) {
            lbl->setFont(Fuente::pie());
        }
    }

    static void AplicarFuenteSubtitulo(QWidget *ventana){
        QList<QLabel*>subtitulos = ventana -> findChildren<QLabel*>("SubTitulo", Qt::FindChildrenRecursively);
        for (QLabel* lbl : subtitulos){
            lbl->setFont(Fuente::subtitulo());
        }
    }




    // Función para aplicar todas las funciones anteriores

    static void AplicarTodas(QWidget *ventana) {
        AplicarFuenteTitulo(ventana);
        AplicarFuenteCEO(ventana);
        AplicarFuenteSubtitulo(ventana);

    }





private:
    // Métodos y miembros privados
    static QFont cargarFuente(const QString &ruta, int tamaño) {
        static QMap<QString, QString> fuentesCargadas;
        if (!fuentesCargadas.contains(ruta)) {
            int id = QFontDatabase::addApplicationFont(ruta);
            if (id == -1) {
                qDebug() << "Error al cargar la fuente desde:" << ruta;
                return QFont();
            }
            QStringList fam = QFontDatabase::applicationFontFamilies(id);
            if (fam.isEmpty()) {
                qDebug() << "No se encontraron familias de fuente en:" << ruta;
                return QFont();
            }
            fuentesCargadas[ruta] = fam.first();
        }
        return QFont(fuentesCargadas[ruta], tamaño);
    }

    static inline QFont fuenteTitulo;
    static inline QFont fuenteSubtitulo;
    static inline QFont fuenteEtiqueta;
    static inline QFont fuenteDescripcion;
    static inline QFont fuentePie;
    static inline bool inicializado = false;
};




#endif // ESTILOS_H
