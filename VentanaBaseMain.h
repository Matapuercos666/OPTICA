#ifndef VENTANABASEMAIN_H
#define VENTANABASEMAIN_H
#include <QMainWindow>

class VentanaBaseMain : public QMainWindow
{

    Q_OBJECT

public:
    explicit VentanaBaseMain(QWidget *parent = nullptr);
    void setTamanoPredeterminado(int ancho, int alto);

protected:
    void showEvent(QShowEvent *event) override;

private:
    int m_ancho;
    int m_alto;
};

#endif // VENTANABASEMAIN_H
