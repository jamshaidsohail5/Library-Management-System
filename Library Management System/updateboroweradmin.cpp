#include "updateboroweradmin.h"
#include "ui_updateboroweradmin.h"
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


updateboroweradmin::updateboroweradmin(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::updateboroweradmin)
{
    ui->setupUi(this);
    name =n ;

    //hiding labels

    ui->label_5->hide();
    ui->label_11->hide();
    ui->label_8->hide();
    ui->label_13->hide();
    ui->label_14->hide();



    ui->lineEdit->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();



    ui->label_9->hide();
    ui->label_12->hide();
    ui->label_15->hide();
    ui->label_16->hide();

    ui->pushButton->hide();


  ui->comboBox_2->addItem("name");
  ui->comboBox_2->addItem("password");

}

updateboroweradmin::~updateboroweradmin()
{
    delete ui;
}


void updateboroweradmin::on_comboBox_2_activated(const QString &arg1)
{
    if(arg1 == "name")
    {

        //hiding labels

        ui->label_5->show();
        ui->label_11->show();
        ui->label_8->show();
        ui->label_13->hide();
        ui->label_14->hide();



        ui->lineEdit->show();
        ui->lineEdit_5->hide();
        ui->lineEdit_3->show();
        ui->lineEdit_7->hide();
        ui->lineEdit_8->show();



        ui->label_9->hide();
        ui->label_12->hide();
        ui->label_15->hide();
        ui->label_16->hide();

        ui->pushButton->show();


    }

    else if(arg1 =="password")
    {

        //hiding labels

        ui->label_5->hide();
        ui->label_11->hide();
        ui->label_8->show();
        ui->label_13->show();
        ui->label_14->show();



        ui->lineEdit->hide();
        ui->lineEdit_5->show();
        ui->lineEdit_3->hide();
        ui->lineEdit_7->show();
        ui->lineEdit_8->show();



        ui->label_9->hide();
        ui->label_12->hide();
        ui->label_15->hide();
        ui->label_16->hide();

        ui->pushButton->show();

    }
}

void updateboroweradmin::on_pushButton_clicked()
{

    QString roll_no = ui->lineEdit_8->text();
    boolean temp;
    singletonlms lm;
    temp =false;
    boolean temp1;
    temp1 == false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");


    if(db.open())
    {
        if(ui->comboBox_2->currentText()=="name")
        {
            QSqlQuery q;
            q.prepare("select * from students where rollno  = ?");
            q.bindValue(0,roll_no);
            q.exec();

            while(q.next())
            {
                temp = true;
            }
            if(temp == false)
            {


                ui->label_9->hide();
                ui->label_12->hide();
                ui->label_15->hide();
                ui->label_16->show();


            }
            else if(temp == true)
            {
                QSqlQuery q1;
                q1.prepare("select * from students where rollno = ? and name = ?");
                q1.bindValue(0,roll_no);
                q1.bindValue(1,ui->lineEdit->text());
                q1.exec();
                while(q1.next())
                {
                    temp1 = true;
                }
                if(temp1 == false)
                {
                    ui->label_9->hide();
                    ui->label_12->show();
                    ui->label_15->hide();
                    ui->label_16->hide();


                }
                else if(temp1 == true)
                {
                    QSqlQuery r;
                    r.prepare("update students set name = ? where rollno = ?");
                    r.bindValue(0,ui->lineEdit_3->text());
                    r.bindValue(1,roll_no);
                    r.exec();

                    QSqlQuery r1;
                    r1.prepare("update loans1 set nameofuser = ? where nameofuser = ?");
                    r1.bindValue(0,ui->lineEdit_3->text());
                    r1.bindValue(1,ui->lineEdit->text());
                    r1.exec();

                    QSqlQuery r2;
                    r2.prepare("update hold set nameofuser = ? where nameofuser = ?");
                    r2.bindValue(0,ui->lineEdit_3->text());
                    r2.bindValue(1,ui->lineEdit->text());

                    r2.exec();
                    QSqlQuery r3;
                    r3.prepare("update loans set nameofuser = ?  where nameofuser = ?");
                    r3.bindValue(0,ui->lineEdit_3->text());
                    r3.bindValue(1,ui->lineEdit->text());
                    r3.exec();
                    lm.getMySystem()->update_student(ui->lineEdit_3->text().toStdString());

                    ui->label_9->hide();
                    ui->label_12->hide();
                    ui->label_15->show();
                    ui->label_16->hide();

                }

            }

        }
        else if(ui->comboBox_2->currentText()=="password")
        {

            QSqlQuery q;
            q.prepare("select * from students where rollno  = ?");
            q.bindValue(0,roll_no);
            q.exec();

            while(q.next())
            {
                temp = true;
            }
            if(temp == false)
            {


                ui->label_9->hide();
                ui->label_12->hide();
                ui->label_15->hide();
                ui->label_16->show();


            }
            else if(temp == true)
            {
                QSqlQuery q1;
                q1.prepare("select * from students where rollno = ? and passwor = ?");
                q1.bindValue(0,roll_no);
                q1.bindValue(1,ui->lineEdit_5->text());
                q1.exec();
                while(q1.next())
                {
                    temp1 = true;
                }
                if(temp1 == false)
                {
                    ui->label_9->show();
                    ui->label_12->hide();
                    ui->label_15->hide();
                    ui->label_16->hide();


                }
                else if(temp1 == true)
                {
                    QSqlQuery r;
                    r.prepare("update students set passwor = ? where rollno = ?");
                    r.bindValue(0,ui->lineEdit_3->text());
                    r.bindValue(1,roll_no);
                    r.exec();
                    ui->label_9->hide();
                    ui->label_12->hide();
                    ui->label_15->show();
                    ui->label_16->hide();

                }
            }
        }

    }
    else
    {
        qDebug()<<"not opened";
    }


}
