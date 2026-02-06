#include "VentanaBase.h"
#include <QShowEvent>
#include <QScreen>
#include <QGuiApplication>

QPoint VentanaBase::ultimaPosicion = QPoint(-1, -1);

VentanaBase::VentanaBase(QWidget *parent)
    :QDialog(parent)
    , m_ancho(700)
    , m_alto(550)
{

}
void VentanaBase::setTamanoPredeterminado(int ancho, int alto)
{
    m_ancho = ancho;
    m_alto = alto;

}
void VentanaBase::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);

    if (event->spontaneous())
        return;

    resize(m_ancho, m_alto);

    if (ultimaPosicion.x() != -1 && ultimaPosicion.y() != -1){
        move(ultimaPosicion);
    } else {

    QScreen *screen = QGuiApplication::primaryScreen();

    if (screen){
        QRect available = screen->availableGeometry();
        int x = available.x() + (available.width() - width()) / 2;
        int y = available.y() + (available.height() - height()) / 2;
        move(x, y);
        }
    }
}
void VentanaBase::moveEvent(QMoveEvent *event){
    ultimaPosicion = pos();
    QDialog::moveEvent(event);
}


