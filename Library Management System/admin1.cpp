#include "admin1.h"
#include "ui_admin1.h"

admin1::admin1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin1)
{
    ui->setupUi(this);
}

admin1::~admin1()
{
    delete ui;
}
