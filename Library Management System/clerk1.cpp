#include "clerk1.h"
#include "ui_clerk1.h"

clerk1::clerk1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clerk1)
{
    ui->setupUi(this);
}

clerk1::~clerk1()
{
    delete ui;
}
