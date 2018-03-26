#include "addborowerclerk.h"
#include "ui_addborowerclerk.h"
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


addborowerclerk::addborowerclerk(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::addborowerclerk)
{
    ui->setupUi(this);
    name =n;

    ui->label_2->hide();
}

addborowerclerk::~addborowerclerk()
{
    delete ui;
}

void addborowerclerk::on_b1_clicked()
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
