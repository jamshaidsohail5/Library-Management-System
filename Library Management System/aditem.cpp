#include "aditem.h"
#include "ui_aditem.h"
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
#include"state.h"
#include"available.h"

aditem::aditem(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::aditem)
{
    ui->setupUi(this);
    name = n;

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();


    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();


    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();


    ui->pushButton->hide();


    ui->comboBox->addItem("book");
    ui->comboBox->addItem("dvd");



}

aditem::~aditem()
{
    delete ui;

}

void aditem::on_comboBox_activated(const QString &arg1)
{

    if(arg1 == "book")
    {

        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->hide();


        ui->lineEdit->show();
        ui->lineEdit_2->show();
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

void aditem::on_pushButton_clicked()
{
    singletonlms lm;

    if(ui->comboBox->currentText()=="book")
    {
        QString bok = ui->lineEdit->text();
        boolean temp;
        temp = false;
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");

        if(db.open())
        {
            QSqlQuery q ;
            q.prepare("select * from book where name = ?");
            q.bindValue(0,ui->lineEdit->text());
            q.exec();

            while(q.next())
            {
                  temp = true;

            }

            if(temp == true)
            {

                ui->label_5->show();
                ui->label_6->hide();
                ui->label_7->hide();

            }
            else if(temp == false)
            {
                int flag;
                flag = 0;
                QSqlQuery n;
                n.prepare("insert into book values(?,?,?)");
                n.bindValue(0,ui->lineEdit->text());
                n.bindValue(1,ui->lineEdit_2->text());
                n.bindValue(2,flag);
                n.exec();
                singletonlms o;


                State * st;
                st = o.getMySystem2();
                Libitem * l = new book(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),flag);
                lm.getMySystem()->add_lib_item(l);
                l->set_state(st);


                ui->label_5->hide();
                ui->label_6->hide();
                ui->label_7->show();

            }
        }
        else
        {
            qDebug()<<"not openend";
        }
    }
    else if(ui->comboBox->currentText()=="dvd")
    {
        QString dvk = ui->lineEdit_3->text();
        boolean temp;
        temp = false;
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");

        if(db.open())
        {
            QSqlQuery q ;
            q.prepare("select * from dvd where title = ?");
            q.bindValue(0,ui->lineEdit_3->text());
            q.exec();

            while(q.next())
            {
                  temp = true;

            }

            if(temp == true)
            {

                ui->label_5->hide();
                ui->label_6->show();
                ui->label_7->hide();

            }
            else if(temp == false)
            {
                int flag;
                flag = 0;
                QSqlQuery n;
                n.prepare("insert into dvd values(?,?)");
                n.bindValue(0,ui->lineEdit_3->text());
                n.bindValue(1,flag);

                n.exec();

                State * st;
                singletonlms p;
                st = p.getMySystem2();
                Libitem * l = new dvd(ui->lineEdit_3->text().toStdString(),flag);
                lm.getMySystem()->add_lib_item(l);
                l->set_state(st);

                ui->label_5->hide();
                ui->label_6->hide();
                ui->label_7->show();

            }
        }
        else
        {
            qDebug()<<"not openend";
        }

    }

}
