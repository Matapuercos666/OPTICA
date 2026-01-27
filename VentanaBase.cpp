/*#include "VentanaBase.h"
#include <QShowEvent>
#include <QScreen>
#include <QGuiApplication>


VentanaBase::VentanaBase(QWidget *parent)
    :QDialog(parent)
    , m_ancho(800)
    , m_alto(600)
{
    //disponible para configurar propiedades futuras
}

/*void VentanaBase::setTamanoPredeterminado(int ancho, int alto)
{
    m_ancho = ancho;
    m_alto = alto;


void VentanaBase::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);

    if (event->spontaneous())
        return;

    resize(m_ancho, m_alto);

    QScreen *screen = QGuiApplication::primaryScreen();

    if (screen){
        QRect screenGeometry = screen->geometry();
        int x = (screenGeometry.width() - width()) / 2;
        int y = (screenGeometry.height() - height()) / 2;
        move(x, y);
    }

}

*/
