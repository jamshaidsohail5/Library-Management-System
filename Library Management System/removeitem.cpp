#include "removeitem.h"
#include "ui_removeitem.h"
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

removeitem::removeitem(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::removeitem)
{
    ui->setupUi(this);
    name =n;


    ui->label_2->hide();

    ui->label_4->hide();


    ui->label_8->hide();
    ui->label_9->hide();


    ui->lineEdit->hide();
    ui->lineEdit_3->hide();


    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();


    ui->pushButton->hide();


    ui->comboBox->addItem("book");
    ui->comboBox->addItem("dvd");



}

removeitem::~removeitem()
{
    delete ui;
}

void removeitem::on_pushButton_clicked()
{
    singletonlms lm ;

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

            if(temp == false)
            {

                ui->label_5->show();
                ui->label_6->hide();
                ui->label_7->hide();
                ui->label_8->hide();
                ui->label_9->hide();


            }
            else if(temp == true)
            {

                boolean temp0;


                Libitem * l;
                l=lm.getMySystem()->search_items(ui->lineEdit->text().toStdString());

                if(l->get_issue()==true)
                {

                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->hide();
                    ui->label_8->show();
                    ui->label_9->hide();


                }
                else if(l->get_issue()==false)
                {
                    lm.getMySystem()->remove_item(l->get_title());

                    QSqlQuery q;
                    q.prepare("Delete from book where name =?");
                    q.bindValue(0,ui->lineEdit->text());
                    q.exec();
                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->show();
                    ui->label_8->hide();
                    ui->label_9->hide();


                }

           }
        }
        else
        {
            qDebug()<<"not openend";
        }

    }
    else if(ui->comboBox->currentText()=="dvd")
    {

        QString bok = ui->lineEdit_3->text();
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

            if(temp == false)
            {

                ui->label_5->hide();
                ui->label_6->show();
                ui->label_7->hide();
                ui->label_8->hide();
                ui->label_9->hide();


            }
            else if(temp == true)
            {

                boolean temp0;


                Libitem * l;
                l=lm.getMySystem()->search_items(ui->lineEdit_3->text().toStdString());

                if(l->get_issue()==true)
                {

                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->hide();
                    ui->label_8->hide();
                    ui->label_9->show();


                }
                else if(l->get_issue()==false)
                {
                    lm.getMySystem()->remove_item(l->get_title());

                    QSqlQuery q;
                    q.prepare("Delete from dvd where title =?");
                    q.bindValue(0,ui->lineEdit_3->text());
                    q.exec();

                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->show();
                    ui->label_8->hide();
                    ui->label_9->hide();

                }

           }
        }
        else
        {
            qDebug()<<"not openend";
        }

    }

}

void removeitem::on_comboBox_activated(const QString &arg1)
{

    if(arg1 == "book")
    {

        ui->label_2->show();
        ui->label_4->hide();


        ui->lineEdit->show();
        ui->lineEdit_3->hide();


        ui->pushButton->show();


    }
    else if(arg1=="dvd")
    {

        ui->label_2->hide();
        ui->label_4->show();


        ui->lineEdit->hide();
        ui->lineEdit_3->show();


        ui->pushButton->show();

    }
}
