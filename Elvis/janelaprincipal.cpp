#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

janelaprincipal::janelaprincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::janelaprincipal)
{
    ui->setupUi(this);
}

janelaprincipal::~janelaprincipal()
{
    delete ui;
}
