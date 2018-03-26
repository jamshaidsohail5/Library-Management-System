#include "issuedvd1.h"
#include "ui_issuedvd1.h"
#include"student.h"
#include"user.h"
#include"dvd.h"
#include"date.h"
#include"singletonlms.h"
#include"libitem.h"
#include"admin.h"
#include"clerk.h"
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


#include"state.h"
#include"available.h"
#include"issued.h"


issuedvd1::issuedvd1(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::issuedvd1)
{
    name = n;
    ui->setupUi(this);

    ui->comboBox->addItem("book0");
    ui->comboBox->addItem("book1");
    ui->comboBox->addItem("book2");
    ui->comboBox->addItem("book3");
    ui->comboBox->addItem("book4");
    ui->comboBox->addItem("book5");
    ui->comboBox->addItem("book6");
    ui->comboBox->addItem("book7");
    ui->comboBox->addItem("book8");
    ui->comboBox->addItem("book9");
    ui->comboBox->hide();


    ui->comboBox_2->addItem("dvd0");
    ui->comboBox_2->addItem("dvd1");
    ui->comboBox_2->addItem("dvd2");
    ui->comboBox_2->addItem("dvd3");
    ui->comboBox_2->addItem("dvd4");
    ui->comboBox_2->addItem("dvd5");
    ui->comboBox_2->addItem("dvd6");
    ui->comboBox_2->addItem("dvd7");
    ui->comboBox_2->addItem("dvd8");
    ui->comboBox_2->addItem("dvd9");

    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();


}

issuedvd1::~issuedvd1()
{
    delete ui;
}

void issuedvd1::on_pushButton_clicked()
{
    singletonlms lms;
    State *s ;

    user * ad =lms.getMySystem()->search_user(name.toStdString()) ;
    Libitem * li=lms.getMySystem()->search_items(ui->comboBox_2->currentText().toStdString());

    QString m =QString::fromStdString(li->get_title());
    bool my;
    my=ad->check_if_already_issued_or_not(m.toStdString());

    if(my==true)
    {
        ui->label_3->show();
        ui->label->hide();
        ui->label_2->hide();
    }
    else if(my==false)
    {
        if(li->get_issue()==true)
        {
        ui->label_2->show();
        ui->label->hide();
        ui->label_3->hide();

        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

        db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
        if(db.open())
        {
                QSqlQuery query;
                query.prepare("insert into hold values (?,?)");
                QString m = QString::fromStdString(ad->get_name());
                query.bindValue(1,m);
                m=QString::fromStdString(li->get_title());
                query.bindValue(0,m);
                query.exec();
        }
        else
        {
             qDebug()<<"ye kia hua";
        }


        li->add_on_hold_user(ad);

        }
        else if(li->get_issue()==false)
        {
            Date ida(2016,01,01);
            Date rda(2016,02,01);
            li->set_issue(true);
            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

            db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
            if(db.open()){
            //tracking record of loan
            QSqlQuery query;
            query.prepare("insert into loans1 values (?,?,?,?,?,?,?,?)");
            QString awa = QString::fromStdString(ad->get_name());
            query.bindValue(0,awa);
            awa = QString::fromStdString(li->get_title());
            query.bindValue(1,awa);
            query.bindValue(2,ida.get_year());
            query.bindValue(3,ida.get_month());
            query.bindValue(4,ida.get_day());
            query.bindValue(5,rda.get_year());
            query.bindValue(6,rda.get_month());
            query.bindValue(7,rda.get_day());
            query.exec();
            //tracking that book has been issued
            QSqlQuery query1;
            query1.prepare("UPDATE dvd SET flag= 1 WHERE title = ?");
            QString awaien =QString::fromStdString(li->get_title());
            query1.bindValue(0,awaien);
            query1.exec();
            }
            else
            {
                qDebug()<<"margya";
            }

            loan * m = new loan(ad,li,ida,rda);
            s = lms.getMySystem4();
            li->set_state(s);
            li->set_issue(true);


            ui->label_2->hide();
            ui->label_3->hide();
            ui->label->setText("DVD Issued Successfully.Return date is 2016/02/01(yr/mn/day)");
            ui->label->show();
        }
    }
}

void issuedvd1::on_comboBox_2_activated(const QString &arg1)
{
    ui->lineEdit->setText(arg1);
}
