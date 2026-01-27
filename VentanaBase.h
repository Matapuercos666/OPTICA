/*#ifndef VENTANABASE_H
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

   private:
    int m_ancho;
    int m_alto;
};

#endif // VENTANABASE_H*/
