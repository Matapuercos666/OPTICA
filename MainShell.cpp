#include "MainShell.h"
#include <QApplication>
#include <QScreen>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include "Usuario_Actual.h"
#include "Perfil_Usuario.h"

MainShell::MainShell(QWidget *parent)
    : QMainWindow(parent)
    , m_usuarioItemIndex(-1)
    //, PerfilWindow(nullptr)
{
    setupUI();
}

MainShell::~MainShell() {}

void MainShell::setupUI()
{
    // Ventana sin marco
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // --- Barra superior ---
    m_topBar = new QWidget(this);
    m_topBar->setObjectName("topBar");
    m_topBar->setFixedHeight(90);

    QVBoxLayout *topLayout = new QVBoxLayout(m_topBar);
    topLayout->setContentsMargins(10, 5, 10, 5);
    topLayout->setSpacing(5);

    // Fila 1: logo, título app, botones ventana
    QHBoxLayout *row1 = new QHBoxLayout;
    m_logoLabel = new QLabel;
    m_logoLabel->setObjectName("logoLabel");
    m_logoLabel->setPixmap(QPixmap(":/IMAGENES/IMAGENES/LOGOS/LOGO.png").scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    row1->addWidget(m_logoLabel);

    m_appTitleLabel = new QLabel("ÓPTICA JARDINES");
    m_appTitleLabel->setObjectName("appTitle");
    row1->addWidget(m_appTitleLabel);
    row1->addStretch();

    m_btnMinimize = new QToolButton;
    m_btnMinimize->setObjectName("btnMinimize");
    m_btnMinimize->setText("−");
    m_btnMinimize->setFixedSize(30, 25);
    row1->addWidget(m_btnMinimize);

    m_btnMaximize = new QToolButton;
    m_btnMaximize->setObjectName("btnMaximize");
    m_btnMaximize->setText("□");
    m_btnMaximize->setFixedSize(30, 25);
    row1->addWidget(m_btnMaximize);

    m_btnClose = new QToolButton;
    m_btnClose->setObjectName("btnClose");
    m_btnClose->setText("✕");
    m_btnClose->setFixedSize(30, 25);
    row1->addWidget(m_btnClose);

    connect(m_btnMinimize, &QToolButton::clicked, this, &MainShell::onMinimizeClicked);
    connect(m_btnMaximize, &QToolButton::clicked, this, &MainShell::onMaximizeClicked);
    connect(m_btnClose, &QToolButton::clicked, this, &MainShell::onCloseClicked);

    // Fila 2: botón regresar, título vista, menú usuario
    QHBoxLayout *row2 = new QHBoxLayout;
    m_btnBack = new QToolButton;
    m_btnBack->setObjectName("btnBack");
    m_btnBack->setText("← Regresar");
    m_btnBack->setEnabled(false);
    row2->addWidget(m_btnBack);
    row2->addStretch();

    m_viewTitleLabel = new QLabel("Inicio");
    m_viewTitleLabel->setObjectName("viewTitle");
    row2->addWidget(m_viewTitleLabel);
    row2->addStretch();

    m_btnUserMenu = new QToolButton;
    m_btnUserMenu->setObjectName("btnUserMenu");
    m_btnUserMenu->setText("Usuario ▼");
    QMenu *userMenu = new QMenu(this);
    userMenu->addAction("Perfil", this, &MainShell::onPerfilClicked);
    userMenu->addAction("Cerrar sesión", this, &MainShell::onCerrarSesionClicked);
    m_btnUserMenu->setMenu(userMenu);
    m_btnUserMenu->setPopupMode(QToolButton::InstantPopup);
    row2->addWidget(m_btnUserMenu);

    topLayout->addLayout(row1);
    topLayout->addLayout(row2);
    mainLayout->addWidget(m_topBar);

    // --- Barra lateral + contenido ---
    QHBoxLayout *contentLayout = new QHBoxLayout;
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);

    m_navList = new QListWidget(this);
    m_navList->setObjectName("navList");
    m_navList->setFixedWidth(200);
    m_navList->setVisible(false);

    // Módulos de navegación
    QList<QPair<QString, int>> modulos = {
        {"PACIENTES", 3},
        {"INVENTARIO", 2},
        {"VENTA", 4},
        {"USUARIOS", 5}
    };

    for (const auto &mod : modulos) {
        QListWidgetItem *item = new QListWidgetItem(mod.first);
        item->setData(Qt::UserRole, mod.second);
        m_navList->addItem(item);
        if (mod.first == "USUARIOS") {
            m_usuarioItemIndex = m_navList->count() - 1;
        }
    }

    connect(m_navList, &QListWidget::currentRowChanged, this, &MainShell::onNavItemClicked);

    contentLayout->addWidget(m_navList);

    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->setObjectName("stackedWidget");
    contentLayout->addWidget(m_stackedWidget, 1);

    mainLayout->addLayout(contentLayout);

    connect(m_btnBack, &QToolButton::clicked, this, &MainShell::onBackClicked);

    resize(1000, 700);
}

// ------------------------------------------------------------
// Gestión de vistas
// ------------------------------------------------------------
void MainShell::addView(QWidget *view, const QString &title)
{
    int index = m_stackedWidget->addWidget(view);
    m_viewTitles[index] = title;
    if (m_stackedWidget->count() == 1) {
        m_stackedWidget->setCurrentIndex(index);
        updateTitleBar();
        updateNavBar();
        updateTopBarVisibility();   // actualizar visibilidad de la barra superior
    }
}

void MainShell::pushView(int index)
{
    if (index < 0 || index >= m_stackedWidget->count()) return;

    int current = m_stackedWidget->currentIndex();

    // No apilar si la vista actual es LOGIN (índice 0)
    if (current != index && current != 0) {
        m_historyStack.push(current);
    }

    m_stackedWidget->setCurrentIndex(index);
    updateTitleBar();
    updateNavBar();
}

void MainShell::popView()
{
    if (!m_historyStack.isEmpty()) {
        int previous = m_historyStack.pop();
        m_stackedWidget->setCurrentIndex(previous);
        updateTitleBar();
        updateNavBar();
    }
}

// ------------------------------------------------------------
// Actualización de interfaz
// ------------------------------------------------------------
void MainShell::updateTitleBar()
{
    int idx = m_stackedWidget->currentIndex();
    QString title = m_viewTitles.value(idx, "Vista");
    m_viewTitleLabel->setText(title);
    m_btnBack->setEnabled(!m_historyStack.isEmpty());

    // Actualizar visibilidad de elementos según la vista actual
    updateTopBarVisibility();
}

void MainShell::updateNavBar()
{
    int idx = m_stackedWidget->currentIndex();
    bool visible = (idx != 0);   // mostrar barra lateral en todo menos login
    m_navList->setVisible(visible);

    if (visible) {
        for (int i = 0; i < m_navList->count(); ++i) {
            QListWidgetItem *item = m_navList->item(i);
            if (item && !item->isHidden() && item->data(Qt::UserRole).toInt() == idx) {
                m_navList->setCurrentRow(i);
                break;
            }
        }
    }
}

void MainShell::updateTopBarVisibility()
{
    int idx = m_stackedWidget->currentIndex();
    bool isLogin = (idx == 0);

    // Mostrar/ocultar elementos de la barra superior según si estamos en login
    m_btnUserMenu->setVisible(!isLogin);
    m_viewTitleLabel->setVisible(!isLogin);

    // Si es login, mostrar un título fijo, de lo contrario el título de la vista actual
    if (isLogin) {
        m_viewTitleLabel->setText("Iniciar Sesión");
    } else {
        QString title = m_viewTitles.value(idx, "Vista");
        m_viewTitleLabel->setText(title);
    }
}


// ------------------------------------------------------------
// Slots
// ------------------------------------------------------------
void MainShell::onBackClicked()
{
    popView();
}

void MainShell::onMinimizeClicked() { showMinimized(); }
void MainShell::onMaximizeClicked() {
    if (windowState() & Qt::WindowMaximized)
        showNormal();
    else
        showMaximized();
}
void MainShell::onCloseClicked() { close(); }

void MainShell::onPerfilClicked()
{
    // Aquí se abrirá el QDialog Perfil_Usuario
    QMessageBox::information(this, "Perfil", "Abrir perfil de usuario (pendiente)");    //HACER FUNCIÓN PARA ABRIR USUARIO)ACTUAL)
    /*if(PerfilWindow())
    {
        delete PerfilWindow();
    }else{
        Perfil_Usuario *PerfilWindow() = new Perfil_Usuario;
        PerfilWindow()->show();
    }*/
}

void MainShell::onCerrarSesionClicked()
{
    // Limpiar historial y volver al login
    m_historyStack.clear();
    m_stackedWidget->setCurrentIndex(0);
    updateTitleBar();
    updateNavBar();
    //Usuario_Actual::limpiar();
}

void MainShell::onNavItemClicked(int row)
{
    if (row < 0) return;
    QListWidgetItem *item = m_navList->item(row);
    if (!item || item->isHidden()) return;
    int viewIndex = item->data(Qt::UserRole).toInt();
    pushView(viewIndex);
}

// ------------------------------------------------------------
// Eventos
// ------------------------------------------------------------
void MainShell::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect available = screen->availableGeometry();
        int x = available.x() + (available.width() - width()) / 2;
        int y = available.y() + (available.height() - height()) / 2;
        move(x, y);
    }
}
