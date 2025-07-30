#ifndef USUARIOS_H
#define USUARIOS_H

#include <QMainWindow>

namespace Ui {
class USUARIOS;
}

class USUARIOS : public QMainWindow
{
    Q_OBJECT

public:
    explicit USUARIOS(QWidget *parent = nullptr);
    ~USUARIOS();

private:
    Ui::USUARIOS *ui;
};

#endif // USUARIOS_H
