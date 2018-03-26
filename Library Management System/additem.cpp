#include "additem.h"
#include "ui_additem.h"
#include "checkinitem.h"
#include "ui_checkinitem.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"
#include <QSql>
#include"mymain.h"
#include"ui_mymain.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtCore>
#include<QtGui>
#include"singletonlms.h"
#include"user.h"
#include"libitem.h"
#include"book.h"
#include"dvd.h"
#include<QString>
#include"loan.h"
#include<QVector>

additem::additem(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::additem)
{
    ui->setupUi(this);

    name = n;

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();


    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();


    ui->pushButton->hide();


    ui->comboBox->addItem("book");
    ui->comboBox-addItem("dvd");

}

additem::~additem()
{
    delete ui;
}

void additem::on_comboBox_activated(const QString &arg1)
{
    if(arg1 == "book")
    {

        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->hide();


        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_3->hide();


        ui->pushButton->show();




    }
    else if(arg1=="dvd")
    {

        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->show();


        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        ui->lineEdit_3->show();


        ui->pushButton->show();





    }
}

void additem::on_pushButton_clicked()
{

    if(ui->comboBox->currentText()=="book")
    {

        


    }
    else if(ui->comboBox->currentText=="dvd")
    {

    }

}
