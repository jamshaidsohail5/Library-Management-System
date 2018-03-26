#include "listitems.h"
#include "ui_listitems.h"
#include"libitem.h"
#include"user.h"
#include"libitem.h"
#include<QVector>
#include"singletonlms.h"
#include"loan.h"
#include"date.h"
#include<QDebug>
listitems::listitems(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::listitems)
{
    name = n;
    ui->setupUi(this);
}

listitems::~listitems()
{
    delete ui;
}

void listitems::on_pushButton_clicked()
{
    singletonlms lm;
    QString temp;
    QString temp1;
    Date d1;
    Date d2;


    user * u = lm.getMySystem()->search_user(name.toStdString());
    QVector<loan *> te =QVector<loan *>::fromStdVector(u->show_all_loans());
    for (int i=0;i<te.size();i++)
    {
        temp =QString::fromStdString(te[i]->get_name_of_libitem());
        temp1 = QString::fromStdString(te[i]->get_name_of_user());
        qDebug()<<temp1;

        d1 = te[i]->getida();
        d2 = te[i]->getrda();

        ui->listWidget->addItem("Name : "+ temp1);
        ui->listWidget->addItem("ItemIssued : "+ temp);
        ui->listWidget->addItem("Issue Date : " + QString::number(d1.get_year()) + "-" + QString::number(d1.get_month()) + "-" + QString::number(d1.get_day()) +" yyyy-mm-dd");
        ui->listWidget->addItem("Return Date : " + QString::number(d2.get_year()) + "-" + QString::number(d2.get_month()) + "-" + QString::number(d2.get_day()) +" yyyy-mm-dd");
        ui->listWidget->addItem("________________________________________________");
    }
}
