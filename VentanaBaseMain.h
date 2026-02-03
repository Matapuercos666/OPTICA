#ifndef VENTANABASEMAIN_H
#define VENTANABASEMAIN_H
#include <QMainWindow>
#include <QToolButton>
#include <QMenu>
#include <QAction>

class VentanaBaseMain : public QMainWindow
{

    Q_OBJECT

public:

    explicit VentanaBaseMain(QWidget *parent = nullptr);
    void setTamanoPredeterminado(int ancho, int alto);

signals:
    void perfilClicked();
    void cerrarSesionClicked();

    protected:
    void showEvent(QShowEvent *event) override;
        virtual void setupIconMenu();

    private slots:
        void onPerfilTriggered();
        void onCerrarSesionTriggered();


private:
    QToolButton *m_Icon;
    QMenu *m_IconMenu;
    int m_ancho;
    int m_alto;

};

#endif // VENTANABASEMAIN_H
