#include "USUARIOS.h"
#include "ui_USUARIOS.h"

USUARIOS::USUARIOS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::USUARIOS)
{
    ui->setupUi(this);
}

USUARIOS::~USUARIOS()
{
    delete ui;
}
