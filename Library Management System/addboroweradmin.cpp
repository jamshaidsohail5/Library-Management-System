#include "addboroweradmin.h"
#include "ui_addboroweradmin.h"
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
#include"student.h"
#include"clerk.h"
#include"libitem.h"
#include"book.h"
#include"dvd.h"
#include<QString>
#include"loan.h"
#include<QVector>

addboroweradmin::addboroweradmin(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::addboroweradmin)
{
    ui->setupUi(this);
    name = n;


    ui->l1->hide();
    ui->l2->hide();
    ui->l3->hide();
    ui->l4->hide();
    ui->l5->hide();
    ui->l6->hide();
    ui->l7->hide();


    ui->lineEdit1->hide();
    ui->lineEdit2->hide();
    ui->lineEdit3->hide();
    ui->lineEdit4->hide();
    ui->lineEdit5->hide();

    ui->label_2->hide();
    ui->label_3->hide();



    ui->b1->hide();
    ui->b2->hide();

    ui->comboBox->addItem("student");
    ui->comboBox->addItem("clerk");

}

addboroweradmin::~addboroweradmin()
{
    delete ui;
}

void addboroweradmin::on_comboBox_activated(const QString &arg1)
{
    if(arg1 == "student")
    {
        ui->l1->show();
        ui->l2->show();
        ui->l3->show();
        ui->l4->show();
        ui->l5->hide();
        ui->l6->hide();
        ui->l7->hide();


        ui->lineEdit1->show();
        ui->lineEdit2->show();
        ui->lineEdit3->show();
        ui->lineEdit4->hide();
        ui->lineEdit5->hide();



        ui->b1->show();
        ui->b2->hide();


    }
    else if(arg1 == "clerk")
    {
        ui->l1->hide();
        ui->l2->hide();
        ui->l3->hide();
        ui->l4->hide();
        ui->l5->show();
        ui->l6->show();
        ui->l7->show();


        ui->lineEdit1->hide();
        ui->lineEdit2->hide();
        ui->lineEdit3->hide();
        ui->lineEdit4->show();
        ui->lineEdit5->show();



        ui->b1->hide();
        ui->b2->show();


    }
}

void addboroweradmin::on_b1_clicked()
{
    user * u;
    singletonlms lm;
    QString name = ui->lineEdit1->text();
    QString password = ui->lineEdit3->text();
    QString rollno = ui->lineEdit2->text();
    boolean temp;
    temp  = false;
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");

        if(db.open())
        {
            QSqlQuery q;
            q.prepare("select * from students where rollno = ?");
            q.bindValue(0,ui->lineEdit2->text());
            q.exec();
            while(q.next())
            {
                temp = true;
            }

            if(temp == true)
            {
                ui->label_2->show();

            }
            else if(temp == false)
            {
                u = new student(ui->lineEdit1->text().toStdString());
                lm.getMySystem()->add_users(u);
                int count;
                QSqlQuery q1;
                q1.exec("Select *  from students");
                while(q1.next())
                {
                    count++;
                }

                QSqlQuery q2;
                q2.prepare("Insert into students values(?,?,?,?)");
                q2.bindValue(0,count+1);
                q2.bindValue(1,ui->lineEdit1->text());
                q2.bindValue(2,ui->lineEdit2->text());
                q2.bindValue(3,ui->lineEdit3->text());
                q2.exec();
            }
        }
        else
        {
            qDebug()<<"Not openened";

        }
}

void addboroweradmin::on_b2_clicked()
{
    user * u;
    singletonlms lm;
    QString name = ui->lineEdit4->text();
    QString password = ui->lineEdit5->text();


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");

    int count;
    count = 0;
    boolean flag;
    flag=false;
    if(db.open())
    {
        QSqlQuery q;
        q.prepare("select *  from clerks where name = ?");
        q.bindValue(0,ui->lineEdit4->text());
        q.exec();

        while(q.next())
        {
            flag= true;

        }
        if(flag == true)
        {
            ui->label_3->show();
        }
        else if(flag == false)
        {
             u = new clerk(ui->lineEdit4->text().toStdString());
            lm.getMySystem()->add_users(u);

            QSqlQuery r;
            r.exec("select * from clerks");
            while(r.next())
            {
                count++;
            }


            QSqlQuery i;
            i.prepare("insert into clerks values(?,?,?)");
            i.bindValue(0,count+1);
            i.bindValue(1,ui->lineEdit4->text());
            i.bindValue(2,ui->lineEdit5->text());
            i.exec();
        }
    }
    else
    {
        qDebug()<<"Not opened";

    }
}
