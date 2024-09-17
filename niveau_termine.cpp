#include "niveau_termine.h"
#include "ui_niveau_termine.h"

niveau_termine::niveau_termine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::niveau_termine)
{
    ui->setupUi(this);
}

niveau_termine::~niveau_termine()
{
    delete ui;
}
