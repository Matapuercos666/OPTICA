#ifndef VENTANABASE_H
#define VENTANABASE_H

#include <QDialog>

class VentanaBase : public QDialog
{
    Q_OBJECT

public:

   explicit VentanaBase(QWidget *parent = nullptr);
    void setTamanoPredeterminado(int ancho, int alto);

   protected:
    void showEvent(QShowEvent *event) override;
       void moveEvent(QMoveEvent *event) override;

   private:
    int m_ancho;
    int m_alto;
    static QPoint ultimaPosicion;

};

#endif // VENTANABASE_H
