#include "VentanaBaseMain.h"
#include <QGuiApplication>
#include <QShowEvent>
#include <QScreen>

VentanaBaseMain::VentanaBaseMain(QWidget *parent)
    : QMainWindow(parent)
    , m_ancho(900)
    , m_alto(700)

{

}

void VentanaBaseMain::setTamanoPredeterminado(int ancho, int alto)
{
    m_ancho = ancho;
    m_alto = alto;
}

void VentanaBaseMain::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    if (event->spontaneous())
        return;

    resize(m_ancho, m_alto);

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect available = screen->availableGeometry();
        int x = available.x() + (available.width() - width()) / 2;
        int y = available.y() + (available.height() - height()) / 2;
        move(x, y);

    }
}
