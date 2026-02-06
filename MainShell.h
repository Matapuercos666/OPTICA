#ifndef MAINSHELL_H
#define MAINSHELL_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QToolButton>
#include <QLabel>
#include <QStack>
#include <QMap>
#include <QListWidget>
#include "Perfil_Usuario.h"

class MainShell : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainShell(QWidget *parent = nullptr);
    ~MainShell();

    void addView(QWidget *view, const QString &title);
    void pushView(int index);
    void popView();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onBackClicked();
    void onMinimizeClicked();
    void onMaximizeClicked();
    void onCloseClicked();
    void onPerfilClicked();
    void onCerrarSesionClicked();
    void onNavItemClicked(int row);

private:
    void setupUI();
    void updateTitleBar();
    void updateNavBar();
    void updateTopBarVisibility();   // nuevo método
    Perfil_Usuario *PerfilWindow();


    // Barra superior
    QWidget *m_topBar;
    QLabel *m_logoLabel;
    QLabel *m_appTitleLabel;
    QToolButton *m_btnBack;
    QLabel *m_viewTitleLabel;
    QToolButton *m_btnUserMenu;
    QToolButton *m_btnMinimize, *m_btnMaximize, *m_btnClose;

    // Barra lateral
    QListWidget *m_navList;
    int m_usuarioItemIndex;   // índice del ítem "USUARIOS"

    // Contenido
    QStackedWidget *m_stackedWidget;
    QStack<int> m_historyStack;
    QMap<int, QString> m_viewTitles;
};

#endif // MAINSHELL_H
