#include "checkoutitemadmin.h"
#include "ui_checkoutitemadmin.h"
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
#include"date.h"
#include<QtGui>
#include"singletonlms.h"
#include"user.h"
#include"libitem.h"
#include"book.h"
#include"dvd.h"
#include<QString>
#include"loan.h"
#include<QVector>

#include"state.h"
#include"available.h"
#include"issued.h"


checkoutitemadmin::checkoutitemadmin(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::checkoutitemadmin)
{
    ui->setupUi(this);
    name = n;


    ui->comboBox->addItem("student");
    ui->comboBox->addItem("clerk");

    ui->comboBox_2->addItem("book");
    ui->comboBox_2->addItem("dvd");


    ui->label1->hide();
    ui->label2->hide();
    ui->label3->hide();
    ui->label4->hide();
    ui->label5->hide();
    ui->label6->hide();
    ui->label7->hide();
}

checkoutitemadmin::~checkoutitemadmin()
{
    delete ui;
}

void checkoutitemadmin::on_pushButton_clicked()
{
    singletonlms lm;
    user * u;
    loan * l;
    Libitem * li;
    State * s;


    if(ui->comboBox->currentText()=="student")
    {
        bool temp = lm.getMySystem()->searchuser(ui->lineEdit->text().toStdString());
        if(temp == false)
        {
            ui->label1->hide();
            ui->label2->hide();
            ui->label3->hide();
            ui->label4->hide();
            ui->label5->hide();
            ui->label6->show();
            ui->label7->hide();


        }
        else if(temp == true)
        {
            if(ui->comboBox_2->currentText()=="book")
            {
                bool temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == false)
                {
                    ui->label1->hide();
                    ui->label2->hide();
                    ui->label3->hide();
                    ui->label4->hide();
                    ui->label5->hide();
                    ui->label6->hide();
                    ui->label7->show();

                }
                else if(temp1 == true)
                {

                    u =lm.getMySystem()->search_user(ui->lineEdit->text().toStdString()) ;
                    li=lm.getMySystem()->search_items(ui->lineEdit_2->text().toStdString());

                    QString m =QString::fromStdString(li->get_title());
                    bool my;
                    my=u->check_if_already_issued_or_not(m.toStdString());
                    if(my == true)
                    {
                        ui->label1->hide();
                        ui->label2->hide();
                        ui->label3->hide();
                        ui->label4->show();
                        ui->label5->hide();
                        ui->label6->hide();
                        ui->label7->hide();


                    }
                    else if(my ==false)
                    {
                        if(li->get_issue()==true)
                        {
                            ui->label1->hide();
                            ui->label2->hide();
                            ui->label3->show();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();

                            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                            db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
                            if(db.open())
                            {
                                qDebug()<<"gi kya";
                                    QSqlQuery query;
                                    query.prepare("insert into hold values (?,?)");
                                    QString m = QString::fromStdString(u->get_name());
                                    query.bindValue(1,m);
                                    m=QString::fromStdString(li->get_title());
                                    query.bindValue(0,m);
                                    query.exec();
                            }
                            else
                            {
                                 qDebug()<<"ye kia hua";
                            }


                            li->add_on_hold_user(u);
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
                            QString awa = QString::fromStdString(u->get_name());
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
                            query1.prepare("UPDATE book SET flag= 1 WHERE name = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                            }
                            else
                            {
                                qDebug()<<"margya";
                            }
                            l = new loan(u,li,ida,rda);
                            s = lm.getMySystem4();
                            li->set_state(s);
                            li->set_issue(true);

                            ui->label1->show();
                            ui->label2->hide();
                            ui->label3->hide();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();
                        }

                    }
                }
            }
            else if(ui->comboBox_2->currentText()=="dvd")
            {

                bool temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == false)
                {
                    ui->label1->hide();
                    ui->label2->hide();
                    ui->label3->hide();
                    ui->label4->hide();
                    ui->label5->hide();
                    ui->label6->hide();
                    ui->label7->show();

                }
                else if(temp1 == true)
                {

                    u =lm.getMySystem()->search_user(ui->lineEdit->text().toStdString()) ;
                    li=lm.getMySystem()->search_items(ui->lineEdit_2->text().toStdString());

                    QString m =QString::fromStdString(li->get_title());
                    bool my;
                    my=u->check_if_already_issued_or_not(m.toStdString());
                    if(my == true)
                    {
                        ui->label1->hide();
                        ui->label2->hide();
                        ui->label3->hide();
                        ui->label4->hide();
                        ui->label5->show();
                        ui->label6->hide();
                        ui->label7->hide();


                    }
                    else if(my ==false)
                    {
                        if(li->get_issue()==true)
                        {
                            ui->label1->hide();
                            ui->label2->hide();
                            ui->label3->show();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();

                            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                            db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
                            if(db.open())
                            {
                                qDebug()<<"gi kya";
                                    QSqlQuery query;
                                    query.prepare("insert into hold values (?,?)");
                                    QString m = QString::fromStdString(u->get_name());
                                    query.bindValue(1,m);
                                    m=QString::fromStdString(li->get_title());
                                    query.bindValue(0,m);
                                    query.exec();
                            }
                            else
                            {
                                 qDebug()<<"ye kia hua";
                            }


                            li->add_on_hold_user(u);
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
                            QString awa = QString::fromStdString(u->get_name());
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
                            query1.prepare("UPDATE dvd SET flag= 1 WHERE item = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                            }
                            else
                            {
                                qDebug()<<"margya";
                            }
                            l = new loan(u,li,ida,rda);
                            s = lm.getMySystem4();
                            li->set_state(s);
                            li->set_issue(true);

                            ui->label1->hide();
                            ui->label2->show();
                            ui->label3->hide();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();
                        }

                    }
                }
            }
        }
    }
    else if(ui->comboBox->currentText()=="clerk")
    {
        bool temp = lm.getMySystem()->searchuser(ui->lineEdit->text().toStdString());
        if(temp == false)
        {
            ui->label1->hide();
            ui->label2->hide();
            ui->label3->hide();
            ui->label4->hide();
            ui->label5->hide();
            ui->label6->show();
            ui->label7->hide();


        }
        else if(temp == true)
        {
            if(ui->comboBox_2->currentText()=="book")
            {
                bool temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == false)
                {
                    ui->label1->hide();
                    ui->label2->hide();
                    ui->label3->hide();
                    ui->label4->hide();
                    ui->label5->hide();
                    ui->label6->hide();
                    ui->label7->show();

                }
                else if(temp1 == true)
                {

                    u =lm.getMySystem()->search_user(ui->lineEdit->text().toStdString()) ;
                    li=lm.getMySystem()->search_items(ui->lineEdit_2->text().toStdString());

                    QString m =QString::fromStdString(li->get_title());
                    bool my;
                    my=u->check_if_already_issued_or_not(m.toStdString());
                    if(my == true)
                    {
                        ui->label1->hide();
                        ui->label2->hide();
                        ui->label3->hide();
                        ui->label4->show();
                        ui->label5->hide();
                        ui->label6->hide();
                        ui->label7->hide();


                    }
                    else if(my ==false)
                    {
                        if(li->get_issue()==true)
                        {
                            ui->label1->hide();
                            ui->label2->hide();
                            ui->label3->show();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();

                            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                            db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
                            if(db.open())
                            {
                                qDebug()<<"gi kya";
                                    QSqlQuery query;
                                    query.prepare("insert into hold values (?,?)");
                                    QString m = QString::fromStdString(u->get_name());
                                    query.bindValue(1,m);
                                    m=QString::fromStdString(li->get_title());
                                    query.bindValue(0,m);
                                    query.exec();
                            }
                            else
                            {
                                 qDebug()<<"ye kia hua";
                            }


                            li->add_on_hold_user(u);
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
                            QString awa = QString::fromStdString(u->get_name());
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
                            query1.prepare("UPDATE book SET flag= 1 WHERE name = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                            }
                            else
                            {
                                qDebug()<<"margya";
                            }
                            l = new loan(u,li,ida,rda);
                            s = lm.getMySystem4();
                            li->set_state(s);
                            li->set_issue(true);

                            ui->label1->show();
                            ui->label2->hide();
                            ui->label3->hide();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();
                        }

                    }
                }
            }
            else if(ui->comboBox_2->currentText()=="dvd")
            {

                bool temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == false)
                {
                    ui->label1->hide();
                    ui->label2->hide();
                    ui->label3->hide();
                    ui->label4->hide();
                    ui->label5->hide();
                    ui->label6->hide();
                    ui->label7->show();

                }
                else if(temp1 == true)
                {

                    u =lm.getMySystem()->search_user(ui->lineEdit->text().toStdString()) ;
                    li=lm.getMySystem()->search_items(ui->lineEdit_2->text().toStdString());

                    QString m =QString::fromStdString(li->get_title());
                    bool my;
                    my=u->check_if_already_issued_or_not(m.toStdString());
                    if(my == true)
                    {
                        ui->label1->hide();
                        ui->label2->hide();
                        ui->label3->hide();
                        ui->label4->hide();
                        ui->label5->show();
                        ui->label6->hide();
                        ui->label7->hide();


                    }
                    else if(my ==false)
                    {
                        if(li->get_issue()==true)
                        {
                            ui->label1->hide();
                            ui->label2->hide();
                            ui->label3->show();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();

                            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                            db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
                            if(db.open())
                            {
                                qDebug()<<"gi kya";
                                    QSqlQuery query;
                                    query.prepare("insert into hold values (?,?)");
                                    QString m = QString::fromStdString(u->get_name());
                                    query.bindValue(1,m);
                                    m=QString::fromStdString(li->get_title());
                                    query.bindValue(0,m);
                                    query.exec();
                            }
                            else
                            {
                                 qDebug()<<"ye kia hua";
                            }


                            li->add_on_hold_user(u);
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
                            QString awa = QString::fromStdString(u->get_name());
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
                            query1.prepare("UPDATE dvd SET flag= 1 WHERE item = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                            }
                            else
                            {
                                qDebug()<<"margya";
                            }
                            l = new loan(u,li,ida,rda);
                            s = lm.getMySystem4();
                            li->set_state(s);
                            li->set_issue(true);

                            ui->label1->hide();
                            ui->label2->show();
                            ui->label3->hide();
                            ui->label4->hide();
                            ui->label5->hide();
                            ui->label6->hide();
                            ui->label7->hide();
                        }

                    }
                }
            }
        }
    }
}
