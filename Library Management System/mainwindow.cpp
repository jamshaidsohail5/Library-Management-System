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
#include"state.h"
#include<QString>

class mymain;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"1";
    ui->setupUi(this);
    ui->wc->hide();
    ui->wr->hide();
    ui->wu->hide();
    ui->comboBox->addItem("Admin");
    ui->comboBox->addItem("Student");
    ui->comboBox->addItem("Clerk");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Signin_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");

    if(db.open())
    {
        qDebug()<<"2";
        singletonlms lm;
        State * si;
        //adding books
        Libitem * li;
        QString name,author;
        boolean my;
        QSqlQuery query1;
        query1.exec("select * from book");
        while(query1.next())
        {
            qDebug()<<"3";

            name=query1.value(0).toString();
            author=query1.value(1).toString();
            my = query1.value(2).toBool();
            li = new book(name.toStdString(),author.toStdString(),my);
            if(my == true)
            {
                si = lm.getMySystem4();
                li->set_state(si);
            }
            else if(my == false)
            {
                si = lm.getMySystem2();
                li->set_state(si);


            }
            lm.getMySystem()->add_lib_item(li);
        }
        //adding dvds
        Libitem * l;
        QString name1;
        boolean my1;
        QSqlQuery query2;
        query2.exec("select * from dvd");
        while(query2.next())
        {
            qDebug()<<"4";

            name1=query2.value(0).toString();
            my1=query2.value(1).toBool();
            l = new dvd(name1.toStdString(),my1);
            if(my1 == true)
            {
                si = lm.getMySystem4();
                l->set_state(si);
            }
            else if(my1 == false)
            {
                si = lm.getMySystem2();
                l->set_state(si);

            }

            lm.getMySystem()->add_lib_item(l);
        }
        qDebug()<<"5";


        //adding users
        user * u;
        QString name2;
        QSqlQuery query3;
        query3.exec("select * from admin1");
        while(query3.next())
        {
            qDebug()<<"6";

            name2 = query3.value(1).toString();
            u = new admin(name2.toStdString());
            lm.getMySystem()->add_users(u);
        }
        user *u1;
        QString name3;
        QSqlQuery query4;
        query4.exec("select * from students");
        while(query4.next())
        {
            qDebug()<<"7";

            name3 = query4.value(1).toString();
            u1=new student(name3.toStdString());
            lm.getMySystem()->add_users(u1);
        }
        qDebug()<<"8";


        user *u2;
        QString name4;
        QSqlQuery query5;
        query5.exec("select * from clerks");
        while(query5.next())
        {
            qDebug()<<"9";

            name4 = query5.value(1).toString();
            u2=new clerk(name4.toStdString());
            lm.getMySystem()->add_users(u2);
        }
        qDebug()<<"10";




        //adding all the loans back and hold wale log
        QSqlQuery q;
        QString na;
        QString na1;
        user *u13;
        Libitem * l1;
        int d1;
        int d2;
        int d3;
        int d4;
        int d5;
        int d6;
        q.exec("select * from loans1");
        while(q.next())
        {
            qDebug()<<"11";

            na = q.value(0).toString();
            u13 = lm.getMySystem()->search_user(na.toStdString());
            na1=q.value(1).toString();
            l1 = lm.getMySystem()->search_items(na1.toStdString());
            Date iida(q.value(2).toInt(),q.value(3).toInt(),q.value(4).toInt());
            Date rrda(q.value(5).toInt(),q.value(6).toInt(),q.value(7).toInt());
            loan * lop = new loan(u13,l1,iida,rrda);
        }
        //adding all hold wale back
        qDebug()<<"12";

        QSqlQuery s;
        user * user12;
        Libitem * libr;
        s.exec("select * from hold");
        while(s.next())
        {
            qDebug()<<"13";
            user12 = lm.getMySystem()->search_user(s.value(1).toString().toStdString());
            libr = lm.getMySystem()->search_items(s.value(0).toString().toStdString());
            libr->add_on_hold_user(user12);
        }

        qDebug()<<"14";


        QSqlQuery query;
        if(ui->comboBox->currentText()=="Admin")
        {
            query.prepare("select * from admin1 where name=? and passwor=?");
            query.bindValue(0,ui->user->text());
            query.bindValue(1,ui->password->text());
            query.exec();
            if(query.next())
            {
                mymain * new_form = new mymain(this->parentWidget(),ui->comboBox->currentText(),ui->user->text());
                this->hide();
                new_form->show();

            }
            else
            {
                 ui->wu->show();
            }

            db.close();

        }
        else if(ui->comboBox->currentText()=="Student")
        {

            query.prepare("select * from students where rollno=? and passwor=?");
            query.bindValue(0,ui->roll->text());
            query.bindValue(1,ui->password->text());
            query.exec();
            if(query.next())
            {
                mymain * new_form = new mymain(this->parentWidget(),ui->comboBox->currentText(),query.value(1).toString());
                this->hide();
                new_form->show();
                qDebug()<<"Connected";
            }
            else
            {
             ui->wr->show();
            }
            db.close();


        }
        else if(ui->comboBox->currentText()=="Clerk")
        {
            query.prepare("select * from clerks where clerkID=? and passwor=?");
            query.bindValue(0,ui->client->text());
            query.bindValue(1,ui->password->text());
            query.exec();
            if(query.next())
            {
                mymain * new_form = new mymain(this->parentWidget(),ui->comboBox->currentText(),query.value(1).toString());
                this->hide();
                new_form->show();
                qDebug()<<"Connected";
            }
            else
            {
                ui->wc->show();

            }

            db.close();
        }
    }
    else
        qDebug()<<"error in connection";
}
void MainWindow::on_comboBox_activated(const QString &arg1)
{


    if(ui->comboBox->currentText()=="Admin")
    {
        ui->client->hide();
        ui->label_4->hide();

        ui->roll->hide();
        ui->label_3->hide();

        ui->user->show();
        ui->label->show();
        ui->password->show();
        ui->Signin->show();

    }
    else if(ui->comboBox->currentText()=="Clerk")
    {
        ui->client->show();
        ui->label_4->show();
        ui->roll->hide();
        ui->label_3->hide();
        ui->user->hide();
        ui->label->hide();
        ui->password->show();
        ui->Signin->show();


    }
    else if(ui->comboBox->currentText()=="Student")
    {
        ui->client->hide();
        ui->label_4->hide();

        ui->roll->show();
        ui->label_3->show();

        ui->user->hide();
        ui->label->hide();
        ui->password->show();
        ui->Signin->show();
    }
}
