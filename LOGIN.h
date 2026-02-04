#ifndef LOGIN_H
#define LOGIN_H
#include "ui_LOGIN.h"
#include <Qdebug>
#include <QWidget>
#include <QSqlQuery>
#include "ESTILOS.h"

struct Usuario {
    QString nombre;
    QString rol;
    QString PASS;
    int ID = -1;
};
QT_BEGIN_NAMESPACE
namespace Ui {
class LOGIN;
}
QT_END_NAMESPACE

class LOGIN : public QWidget
{
    Q_OBJECT

public:
   explicit LOGIN(QWidget *parent = nullptr);
    Usuario BuscarID(int);
    Usuario BuscarUsuario(const QString&);
    ~LOGIN();

signals:
    void loginSuccessful();

private slots:
    void Boton_ENTRAR();

private:
    Ui::LOGIN *ui;

};
#endif // LOGIN_H

