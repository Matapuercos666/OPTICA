#include "VentanaBaseMain.h"
#include <QGuiApplication>
#include <QShowEvent>
#include <QScreen>

VentanaBaseMain::VentanaBaseMain(QWidget *parent)
    : QMainWindow(parent)
    , m_Icon(nullptr)
    , m_IconMenu(nullptr)
    , m_ancho(800)
    , m_alto(650)

{

}

void VentanaBaseMain::setupIconMenu(){
    if (m_Icon && m_IconMenu) return;

    qDebug() << "===Nombre QToolButton" << this->metaObject()->className() << "===";
    QList<QToolButton*> botones = this->findChildren<QToolButton*>();
    for (QToolButton* btn : botones) {
        qDebug() <<" - QToolButton objectName :" << btn ->objectName();
    }

    m_Icon = findChild<QToolButton*>("Icon");
    if (!m_Icon){
        qWarning() << "No se encontro ningun QToolButton con objectName 'Icon' en la ventana"
                  << "El menu del logo no se configurara";
        return;
    }

    m_IconMenu = new QMenu(this);
    QAction *accionPerfil = m_IconMenu->addAction("Perfil");
    QAction *accionCerrarSesion = m_IconMenu->addAction("Cerrar sesión");

    connect(accionPerfil, &QAction::triggered, this, &VentanaBaseMain::onPerfilTriggered);
    connect(accionCerrarSesion, &QAction::triggered, this, &VentanaBaseMain::onCerrarSesionTriggered);

    m_Icon->setMenu(m_IconMenu);
    m_Icon->setPopupMode(QToolButton::InstantPopup);

    m_Icon->setStyleSheet("QToolButton { border: none; background: transparent; }");

    qDebug() << "Menu del logo configurado correctamente en" << this ->metaObject()->className();
}

void VentanaBaseMain::onPerfilTriggered(){
    emit perfilClicked();
}

void VentanaBaseMain::onCerrarSesionTriggered(){
    emit cerrarSesionClicked();
}

void VentanaBaseMain::setTamanoPredeterminado(int ancho, int alto)
{
    m_ancho = ancho;
    m_alto = alto;
}

void VentanaBaseMain::showEvent(QShowEvent *event){

    QMainWindow::showEvent(event);
    static bool primeraVez = true;
    if (primeraVez) {
        setupIconMenu();
        primeraVez = false;
    }

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
