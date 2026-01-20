#ifndef LOGIN_H
#define LOGIN_H
#include <Qdebug>
#include <QMainWindow>
#include "ESTILOS.H"
#include "Menu.h"

struct Usuario {
    QString nombre;
    QString rol;
    QString PASS;
    int ID;
};
QT_BEGIN_NAMESPACE
namespace Ui {
class LOGIN;
}
QT_END_NAMESPACE

class LOGIN : public QMainWindow
{
    Q_OBJECT

public:
    LOGIN(QWidget *parent = nullptr);
    Usuario BuscarID(int);
    Usuario BuscarUsuario(const QString&);
    ~LOGIN();

private slots:
    void Boton_ENTRAR();

private:
    Ui::LOGIN *ui;
    Menu *MenuWindow; //puntero a la siguiente ventana
};
#endif // LOGIN_H

