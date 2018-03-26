#include "student1.h"
#include "ui_student1.h"

student1::student1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student1)
{
    ui->setupUi(this);
}

student1::~student1()
{
    delete ui;
}
