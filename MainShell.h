#ifndef MAINSHELL_H
#define MAINSHELL_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QToolButton>
#include <QLabel>
#include <QStack>
#include <QMap>
#include <QListWidget>

class MainShell : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainShell(QWidget *parent = nullptr);
    ~MainShell();

    // Agrega una vista al QStackedWidget con su título
    void addView(QWidget *view, const QString &title);
    // Navega a una vista (apila la actual)
    void pushView(int index);
    // Regresa a la vista anterior
    void popView();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onBackClicked();
    void onMinimizeClicked();
    void onMaximizeClicked();
    void onCloseClicked();
    void onPerfilClicked();      // Acción del menú de usuario
    void onCerrarSesionClicked();
    void onNavItemClicked(int row);

private:
    void setupUI();
    void updateTitleBar();
    void upDateNavBar();

    // Widgets de la barra superior
    QWidget *m_topBar;
    QLabel *m_logoLabel;
    QLabel *m_appTitleLabel;
    QToolButton *m_btnBack;
    QLabel *m_viewTitleLabel;
    QToolButton *m_btnUserMenu;
    QToolButton *m_btnMinimize, *m_btnMaximize, *m_btnClose;

    //barra lateral
    QListWidget *m_navList;

    QStackedWidget *m_stackedWidget;

    // Historial de navegación (pilas)
    QStack<int> m_historyStack;
    QMap<int, QString> m_viewTitles;
    QMap<int, int> m_navMap;
};


#endif // MAINSHELL_H
