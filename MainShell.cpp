#include "MainShell.h"
#include <QApplication>
#include <QScreen>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QAction>
#include <QDebug>

MainShell::MainShell(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

MainShell::~MainShell() {}

void MainShell::setupUI()
{
    // Ventana sin marco (la apariencia se controlará con QSS)
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground); // opcional, para bordes redondeados

    // Widget central y layout principal
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // --- Barra superior (topBar) ---
    m_topBar = new QWidget(this);
    m_topBar->setObjectName("topBar");            // importante para el CSS
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

    m_appTitleLabel = new QLabel("Sistema Óptica");
    m_appTitleLabel->setObjectName("appTitle");
    row1->addWidget(m_appTitleLabel);
    row1->addStretch();

    // Botones de ventana
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

    // Conexiones botones ventana
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

    //barra lateral

    QHBoxLayout *contentLayout = new QHBoxLayout();
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);

    m_navList = new QListWidget(this);
    m_navList->setObjectName("navList");
    m_navList->setFixedWidth(200);
    m_navList->setVisible(false);
    m_navList->setStyleSheet(
        "QListWidget { background-color: %3; border: none; }"
        "QListWidget::item { padding: 1.2em; font-size: 11pt; }"
        "QListWidget::item:selected { background-color: #d0d0d0; }"
        );

    QList<QPair<QString, int>> modulos = {
    {"PACIENTES", 3},
    {"INVENTARIO", 2},
    {"VENTA", 4},

                                          };

    for (const auto &mod: modulos) {
        QListWidgetItem *item = new QListWidgetItem(mod.first);
        item->setData(Qt::UserRole, mod.second);
        m_navList->addItem(item);
        m_navMap[mod.second] = m_navList->count() - 1;
    }

    contentLayout->addWidget(m_navList);

    // Área central (QStackedWidget)
    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->setObjectName("stackedWidget");
    contentLayout->addWidget(m_stackedWidget, 1);

    mainLayout->addLayout(contentLayout);

    // Conectar botón regresar
    connect(m_btnBack, &QToolButton::clicked, this, &MainShell::onBackClicked);
    connect(m_navList, &QListWidget::currentRowChanged, this, &MainShell::onNavItemClicked);


    // Tamaño inicial de la ventana (se puede ajustar, pero el CSS puede definir min-width/height)
    resize(1000, 700);
}

void MainShell::addView(QWidget *view, const QString &title)
{
    int index = m_stackedWidget->addWidget(view);
    m_viewTitles[index] = title;
    if (m_stackedWidget->count() == 1) {
        m_stackedWidget->setCurrentIndex(index);
        updateTitleBar();
        upDateNavBar();
    }
}

void MainShell::pushView(int index)
{
    if (index < 0 || index >= m_stackedWidget->count()) return;
    int current = m_stackedWidget->currentIndex();
    if (current != index) {
        m_historyStack.push(current);
        m_stackedWidget->setCurrentIndex(index);
        updateTitleBar();
        upDateNavBar();   // ← actualizar visibilidad y selección
    }
}

void MainShell::popView()
{
    if (!m_historyStack.isEmpty()) {
        int previous = m_historyStack.pop();
        m_stackedWidget->setCurrentIndex(previous);
        updateTitleBar();
        upDateNavBar();
    }
}

void MainShell::updateTitleBar()
{
    int idx = m_stackedWidget->currentIndex();
    QString title = m_viewTitles.value(idx, "Vista");
    m_viewTitleLabel->setText(title);
    m_btnBack->setEnabled(!m_historyStack.isEmpty());
}

void MainShell::onBackClicked()
{
    popView();
}

void MainShell::onMinimizeClicked()
{
    showMinimized();
}

void MainShell::onMaximizeClicked()
{
    if (windowState() & Qt::WindowMaximized)
        showNormal();
    else
        showMaximized();
}

void MainShell::onCloseClicked()
{
    close();
}

void MainShell::onPerfilClicked()
{
    pushView(0);
}

void MainShell::onCerrarSesionClicked()
{
    // Vuelve a la vista de login (índice 0) y limpia el historial
    m_stackedWidget->setCurrentIndex(0);
    m_historyStack.clear();
    updateTitleBar();
}

void MainShell::onNavItemClicked(int row)
{
    if (row < 0) return;
    QListWidgetItem *item = m_navList->item(row);
    if (!item) return;
    int viewIndex = item->data(Qt::UserRole).toInt();
    // Navegar a la vista correspondiente (sin apilar, porque es navegación directa)
    // Si quieres que se guarde en el historial, usa pushView; si no, usa setCurrentIndex
    // Recomiendo pushView para mantener consistencia
    pushView(viewIndex);
}

void MainShell::upDateNavBar()
{
    int idx = m_stackedWidget->currentIndex();
    // Mostrar la barra en todas las vistas excepto login (0) y menú (1)
    bool visible = (idx != 0 && idx != 1);
    m_navList->setVisible(visible);

    // Si la barra está visible, seleccionar el ítem correspondiente a la vista actual
    if (visible) {
        // Buscar el ítem cuyo UserRole coincida con idx
        for (int i = 0; i < m_navList->count(); ++i) {
            QListWidgetItem *item = m_navList->item(i);
            if (item && item->data(Qt::UserRole).toInt() == idx) {
                m_navList->setCurrentRow(i);
                break;
            }
        }
    }
}


void MainShell::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    // Centrar la ventana en la pantalla (usando geometría disponible)
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        QRect available = screen->availableGeometry();
        int x = available.x() + (available.width() - width()) / 2;
        int y = available.y() + (available.height() - height()) / 2;
        move(x, y);
    }
}
