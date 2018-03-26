#include "checkinitemclerk.h"
#include "ui_checkinitemclerk.h"
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
#include"issued.h"


checkinitemclerk::checkinitemclerk(QWidget *parent,QString n) :
    QMainWindow(parent),
    ui(new Ui::checkinitemclerk)
{
    ui->setupUi(this);
    name = n;

    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_10->hide();


    ui->comboBox->addItem("dvd");
    ui->comboBox->addItem("book");

    ui->comboBox_2->addItem("admin");
    ui->comboBox_2->addItem("student");
}

checkinitemclerk::~checkinitemclerk()
{
    delete ui;
}

void checkinitemclerk::on_pushButton_clicked()
{
    qDebug()<<"1";

    singletonlms lm;
    QSqlQuery query;
    loan * l;
    user * u;
    Libitem *li;
    boolean temp;
    boolean temp1;
    boolean temp2;
    temp = false;

    if(ui->comboBox_2->currentText()=="admin")
    {
        qDebug()<<"1";
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

        db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
        qDebug()<<"2";

        if(db.open())
        {
            qDebug()<<"3";
        QSqlQuery query;
        query.prepare("select * from admin1 where name = ?");
        query.bindValue(0,ui->lineEdit->text());
        query.exec();
        while(query.next())
        {
            temp = true;
            if(ui->comboBox->currentText()=="dvd")
            {
                qDebug()<<"4";
                temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == true)
                {
                    qDebug()<<"5";

                    //getting user and item
                    QString meri =ui->lineEdit->text();
                    QString teri = ui->lineEdit_2->text();

                    //retrieving them from class
                    u=lm.getMySystem()->search_user(meri.toStdString());
                    li=lm.getMySystem()->search_items(teri.toStdString());
                    qDebug()<<"6";

                    //checking if the item was really issued or not
                    temp2 = u->check_if_already_issued_or_not(ui->lineEdit_2->text().toStdString());
                    if(temp2==false)
                    {
                     ui->label_10->show();
                     ui->label_4->hide();
                     ui->label_5->hide();
                     ui->label_6->hide();
                     ui->label_7->hide();

                    }
                    else if(temp2==true)
                    {
                        qDebug()<<"7";

                        l = u->search_loan(ui->lineEdit_2->text().toStdString(),ui->lineEdit->text().toStdString());

                        //now here i will impose a fine if it is to be imposed and then store it in the database.

                        Date d1 = l->getida();
                        Date d2 =l->getrda();
                        QString da = ui->lineEdit_3->text();
                        QStringList myStringList = da.split("-");
                        qDebug()<<"8";


                        Date userdate(myStringList.at(0).toInt(),myStringList.at(1).toInt(),myStringList.at(2).toInt());
                        int days = (userdate.rdn(userdate.get_year(),userdate.get_month(),userdate.get_day()))-(d1.rdn(d1.get_year(),d1.get_month(),d1.get_day()));
                        boolean ghar ;
                        ghar = false;
                        if(days > 30)
                        {
                            ghar = true;
                            qDebug()<<"9";

                            int rest = days - 30;
                            int fine = rest * 10;
                            //now recording fine into the database

                            QSqlQuery q11;
                            q11.prepare("insert into loans values (?,?,?,?,?,?,?,?,?)");
                            q11.bindValue(0,ui->lineEdit->text());
                            q11.bindValue(1,ui->lineEdit_2->text());
                            q11.bindValue(2,d1.get_year());
                            q11.bindValue(3,d1.get_month());
                            q11.bindValue(4,d1.get_day());
                            q11.bindValue(5,d2.get_year());
                            q11.bindValue(6,d2.get_month());
                            q11.bindValue(7,d2.get_day());
                            q11.bindValue(8,fine);
                            q11.exec();
                            qDebug()<<"10";

                            ui->label_6->show();
                            ui->label_6->setText("Item Returned successfully.Fine of Rs. " +QString::number(fine)+" is imposed !");
                            ui->label_4->hide();
                            ui->label_5->hide();
                            ui->label_7->hide();
                            ui->label_10->hide();
                        }

                        /////////////////////////////////
                        li->remove_loan(l);
                        li->set_issue(false);
                        //setting state
                        State * st;
                        singletonlms ja;
                        st = ja.getMySystem2();
                        li->set_state(st);

                        //deleting the loan
                        QSqlQuery i;
                        i.prepare("delete from loans1 where nameofuser = ? AND nameofitem = ? ");
                        i.bindValue(0,ui->lineEdit->text());
                        i.bindValue(1,ui->lineEdit_2->text());
                        i.exec();


                        if(ghar == false)
                        {
                            ui->label_5->show();
                            ui->label_6->hide();
                            ui->label_7->hide();
                            ui->label_4->hide();
                            ui->label_10->hide();
                        }



                        ////////////////////////////////
                        int op =li->no_of_holders();
                        qDebug()<<op;

                        if(li->no_of_holders()>0)
                        {
                            user * iou = li->get_holder_front_holder_wala();
                            Date y(2016,01,01);
                            Date y1(2016,02,01);
                            loan * o;

                            QSqlQuery query;
                            query.prepare("insert into loans1 values (?,?,?,?,?,?,?,?)");
                            QString awa = QString::fromStdString(iou->get_name());
                            query.bindValue(0,awa);
                            awa = QString::fromStdString(li->get_title());
                            query.bindValue(1,awa);
                            query.bindValue(2,y.get_year());
                            query.bindValue(3,y.get_month());
                            query.bindValue(4,y.get_day());
                            query.bindValue(5,y1.get_year());
                            query.bindValue(6,y1.get_month());
                            query.bindValue(7,y1.get_day());
                            query.exec();
                            //tracking that book has been issued
                            QSqlQuery query1;
                            query1.prepare("UPDATE dvd SET flag= 1 WHERE title = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();

                            //updating hold wale

                            QString hamza = QString::fromStdString(iou->get_name());
                            QString javed = QString::fromStdString(li->get_title());

                            QSqlQuery u;
                            u.prepare("delete from hold where nameofitem = ? AND nameofuser = ?");
                            u.bindValue(0,javed);
                            u.bindValue(1,hamza);
                            u.exec();
                            o = new loan(iou,li,y,y1);
                            li->set_issue(true);
                            State * r;
                            singletonlms a;
                            r = a.getMySystem4();
                            li->set_state(r);

                        }
                        else
                        {

                            State * r;
                            singletonlms a;
                            r = a.getMySystem2();
                            li->set_state(r);
                            li->set_issue(false);

                            QSqlQuery query1;
                            query1.prepare("UPDATE dvd SET flag= 0 WHERE item = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                        }
                    }
                }
                else if(temp1==false)
                {
                    ui->label_4->show();
                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->hide();
                    ui->label_10->hide();
                }
            }
            else if(ui->comboBox->currentText()=="book")
            {
                temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == true)
                {
                    //getting user and item
                    QString meri =ui->lineEdit->text();
                    QString teri = ui->lineEdit_2->text();

                    //retrieving them from class
                    u=lm.getMySystem()->search_user(meri.toStdString());
                    li=lm.getMySystem()->search_items(teri.toStdString());

                    //checking if the item was really issued or not
                    temp2 = u->check_if_already_issued_or_not(ui->lineEdit_2->text().toStdString());
                    if(temp2==false)
                    {
                        ui->label_10->show();
                        ui->label_4->hide();
                        ui->label_5->hide();
                        ui->label_6->hide();
                        ui->label_7->hide();
                    }
                    else if(temp2==true)
                    {
                        l = u->search_loan(ui->lineEdit_2->text().toStdString(),ui->lineEdit->text().toStdString());

                        //now here i will impose a fine if it is to be imposed and then store it in the database.

                        Date d1 = l->getida();
                         Date d2 = l->getrda();

                        QString da = ui->lineEdit_3->text();
                        QStringList myStringList = da.split("-");


                        Date userdate(myStringList.at(0).toInt(),myStringList.at(1).toInt(),myStringList.at(2).toInt());
                        int days = (userdate.rdn(userdate.get_year(),userdate.get_month(),userdate.get_day()))-(d1.rdn(d1.get_year(),d1.get_month(),d1.get_day()));
                        boolean ghar ;
                        ghar = false;

                        if(days > 30)
                        {
                            ghar =true;
                            int rest = days - 30;
                            int fine = rest * 10;
                            //now recording fine into the database

                            QSqlQuery q11;
                            q11.prepare("insert into loans values (?,?,?,?,?,?,?,?,?)");
                            q11.bindValue(0,ui->lineEdit->text());
                            q11.bindValue(1,ui->lineEdit_2->text());
                            q11.bindValue(2,d1.get_year());
                            q11.bindValue(3,d1.get_month());
                            q11.bindValue(4,d1.get_day());
                            q11.bindValue(5,d2.get_year());
                            q11.bindValue(6,d2.get_month());
                            q11.bindValue(7,d2.get_day());
                            q11.bindValue(8,fine);
                            q11.exec();

                            ui->label_6->show();
                            ui->label_6->setText("Item Returned successfully.Fine of Rs. " +QString::number(fine)+" is imposed !");
                            ui->label_4->hide();
                            ui->label_5->hide();
                            ui->label_7->hide();
                            ui->label_10->hide();

                        }

                        /////////////////////////////////
                        li->remove_loan(l);
                        li->set_issue(false);
                        State * r;
                        singletonlms a;
                        r = a.getMySystem2();
                        li->set_state(r);

                        //deleting the loan
                        QSqlQuery i;
                        i.prepare("delete from loans1 where nameofuser = ? AND nameofitem = ? ");
                        i.bindValue(0,ui->lineEdit->text());
                        i.bindValue(1,ui->lineEdit_2->text());
                        i.exec();
                        if(ghar == false)
                        {
                            ui->label_5->show();
                            ui->label_6->hide();
                            ui->label_7->hide();
                            ui->label_4->hide();
                            ui->label_10->hide();


                        }


                        ////////////////////////////////

                        if(li->no_of_holders()>0)
                        {
                            user * iou = li->get_holder_front_holder_wala();
                            Date y(2016,01,01);
                            Date y1(2016,02,01);
                            loan * o;

                            QSqlQuery query;
                            query.prepare("insert into loans1 values (?,?,?,?,?,?,?,?)");
                            QString awa = QString::fromStdString(iou->get_name());
                            query.bindValue(0,awa);
                            awa = QString::fromStdString(li->get_title());
                            query.bindValue(1,awa);
                            query.bindValue(2,y.get_year());
                            query.bindValue(3,y.get_month());
                            query.bindValue(4,y.get_day());
                            query.bindValue(5,y1.get_year());
                            query.bindValue(6,y1.get_month());
                            query.bindValue(7,y1.get_day());
                            query.exec();
                            //tracking that book has been issued
                            QSqlQuery query1;
                            query1.prepare("UPDATE book SET flag= 1 WHERE name = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();

                            //updating hold wale

                            QString hamz = QString::fromStdString(iou->get_name());
                            QString jav = QString::fromStdString(li->get_title());

                            QSqlQuery u;
                            u.prepare("delete from hold where nameofitem = ? AND nameofuser = ?");
                            u.bindValue(0,jav);
                            u.bindValue(1,hamz);
                            u.exec();
                            o = new loan(iou,li,y,y1);
                            li->set_issue(true);
                            State * r;
                            singletonlms a;
                            r = a.getMySystem4();
                            li->set_state(r);

                        }
                        else
                        {
                            State * r;
                            singletonlms a;
                            r = a.getMySystem2();
                            li->set_state(r);
                            li->set_issue(false);

                            QSqlQuery query1;
                            query1.prepare("UPDATE book SET flag= 0 WHERE name = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                        }
                    }
                }
                else if(temp1==false)
                {
                    ui->label_4->show();
                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->hide();
                    ui->label_10->hide();

                }
            }
        }
        if(temp == false)
        {
         ui->label_7->show();
         ui->label_4->hide();
         ui->label_5->hide();
         ui->label_6->hide();
         ui->label_10->hide();
        }
      }
    }
    else if(ui->comboBox_2->currentText()=="student")
    {
        qDebug()<<"2";

        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

        db.setDatabaseName("DRIVER={SQL Server};Server=DESKTOP-JUCF3LS\\SQLExpress;Database=Users;Trusted_connection=yes");
        qDebug()<<"3";

        if(db.open())
        {
            qDebug()<<"4";

        QSqlQuery query;
        query.prepare("select * from students where name = ?");
        query.bindValue(0,ui->lineEdit->text());
        query.exec();
        while(query.next())
        {
            qDebug()<<"5";

            temp = true;
            if(ui->comboBox->currentText()=="dvd")
            {

                temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == true)
                {
                    qDebug()<<"7";


                    //getting user and item
                    QString meri =ui->lineEdit->text();
                    QString teri = ui->lineEdit_2->text();
                    qDebug()<<"8";

                    //retrieving them from class
                    u=lm.getMySystem()->search_user(meri.toStdString());
                    qDebug()<<"9";

                    li=lm.getMySystem()->search_items(teri.toStdString());
                    qDebug()<<"10";



                    //checking if the item was really issued or not
                    temp2 = u->check_if_already_issued_or_not(ui->lineEdit_2->text().toStdString());
                    qDebug()<<"11";

                    if(temp2==false)

                    {
                        qDebug()<<"12";

                     ui->label_10->show();
                     ui->label_4->hide();
                     ui->label_5->hide();
                     ui->label_6->hide();
                     ui->label_7->hide();
                    }
                    else if(temp2==true)
                    {
                        qDebug()<<"13";

                        l = u->search_loan(ui->lineEdit_2->text().toStdString(),ui->lineEdit->text().toStdString());
                        qDebug()<<"14";

                        //now here i will impose a fine if it is to be imposed and then store it in the database.

                        Date d1 = l->getida();
                        Date d2 =l->getrda();
                        qDebug()<<"15";

                        QString da = ui->lineEdit_3->text();
                        QStringList myStringList = da.split("-");

                        qDebug()<<"16";

                        Date userdate(myStringList.at(0).toInt(),myStringList.at(1).toInt(),myStringList.at(2).toInt());
                        int days = (userdate.rdn(userdate.get_year(),userdate.get_month(),userdate.get_day()))-(d1.rdn(d1.get_year(),d1.get_month(),d1.get_day()));
                        qDebug()<<"17";
                        boolean ghar;
                        ghar = false;

                        if(days > 30)
                        {
                            ghar  = true;
                            int rest = days - 30;
                            int fine = rest * 10;
                            //now recording fine into the database

                            QSqlQuery q11;
                            q11.prepare("insert into loans values (?,?,?,?,?,?,?,?,?)");
                            q11.bindValue(0,ui->lineEdit->text());
                            q11.bindValue(1,ui->lineEdit_2->text());
                            q11.bindValue(2,d1.get_year());
                            q11.bindValue(3,d1.get_month());
                            q11.bindValue(4,d1.get_day());
                            q11.bindValue(5,d2.get_year());
                            q11.bindValue(6,d2.get_month());
                            q11.bindValue(7,d2.get_day());
                            q11.bindValue(8,fine);
                            q11.exec();

                            ui->label_6->show();
                            ui->label_6->setText("Item Returned successfully.Fine of Rs. " +QString::number(fine)+" is imposed !");
                        }

                        /////////////////////////////////
                        li->remove_loan(l);
                        li->set_issue(false);
                        State * r;
                        singletonlms a;
                        r = a.getMySystem2();
                        li->set_state(r);

                        //deleting the loan
                        QSqlQuery i;
                        i.prepare("delete from loans1 where nameofuser = ? AND nameofitem = ? ");
                        i.bindValue(0,ui->lineEdit->text());
                        i.bindValue(1,ui->lineEdit_2->text());
                        i.exec();
                        if(ghar == false)
                        {
                            ui->label_5->show();
                            ui->label_6->hide();
                            ui->label_7->hide();
                            ui->label_4->hide();
                            ui->label_10->hide();


                        }


                        ////////////////////////////////

                        if(li->no_of_holders()>0)
                        {
                            user * iou = li->get_holder_front_holder_wala();
                            Date y(2016,01,01);
                            Date y1(2016,02,01);
                            loan * o;

                            QSqlQuery query;
                            query.prepare("insert into loans1 values (?,?,?,?,?,?,?,?)");
                            QString awa = QString::fromStdString(iou->get_name());
                            query.bindValue(0,awa);
                            awa = QString::fromStdString(li->get_title());
                            query.bindValue(1,awa);
                            query.bindValue(2,y.get_year());
                            query.bindValue(3,y.get_month());
                            query.bindValue(4,y.get_day());
                            query.bindValue(5,y1.get_year());
                            query.bindValue(6,y1.get_month());
                            query.bindValue(7,y1.get_day());
                            query.exec();
                            //tracking that book has been issued
                            QSqlQuery query1;
                            query1.prepare("UPDATE dvd SET flag= 1 WHERE title = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();

                            //updating hold wale

                            QString ade = QString::fromStdString(iou->get_name());
                            QString sha = QString::fromStdString(li->get_title());

                            QSqlQuery u;
                            u.prepare("delete from hold where nameofitem = ? AND nameofuser = ?");
                            u.bindValue(0,sha);
                            u.bindValue(1,ade);
                            u.exec();
                            o = new loan(iou,li,y,y1);
                            li->set_issue(true);
                            State * r;
                            singletonlms a;
                            r = a.getMySystem4();
                            li->set_state(r);

                        }
                        else
                        {
                            State * r;
                            singletonlms a;
                            r = a.getMySystem2();
                            li->set_state(r);
                            li->set_issue(false);

                            QSqlQuery query1;
                            query1.prepare("UPDATE dvd SET flag= 0 WHERE title = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                        }
                    }
                }
                else if(temp1==false)
                {
                    ui->label_4->show();
                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->hide();
                    ui->label_10->hide();
                }
            }
            else if(ui->comboBox->currentText()=="book")
            {
                qDebug()<<"6";
                temp1 = lm.getMySystem()->searchitem(ui->lineEdit_2->text().toStdString());
                if(temp1 == true)
                {
                    qDebug()<<"7";

                    //getting user and item
                    QString meri =ui->lineEdit->text();
                    QString teri = ui->lineEdit_2->text();

                    //retrieving them from class
                    u=lm.getMySystem()->search_user(meri.toStdString());
                    li=lm.getMySystem()->search_items(teri.toStdString());
                    qDebug()<<"8";

                    //checking if the item was really issued or not
                    temp2 = u->check_if_already_issued_or_not(ui->lineEdit_2->text().toStdString());
                    qDebug()<<"8";

                    if(temp2==false)
                    {
                        qDebug()<<"9";

                     ui->label_10->show();
                     ui->label_4->hide();
                     ui->label_5->hide();
                     ui->label_6->hide();
                     ui->label_7->hide();
                    }
                    else if(temp2==true)
                    {
                        qDebug()<<"10";

                        l = u->search_loan(ui->lineEdit_2->text().toStdString(),ui->lineEdit->text().toStdString());

                        //now here i will impose a fine if it is to be imposed and then store it in the database.

                        Date d1 = l->getida();
                        Date d2 = l->getrda();
                        qDebug()<<"11";

                        QString da = ui->lineEdit_3->text();
                        QStringList myStringList = da.split("-");
                        Date userdate(myStringList.at(0).toInt(),myStringList.at(1).toInt(),myStringList.at(2).toInt());

                        int days = (userdate.rdn(userdate.get_year(),userdate.get_month(),userdate.get_day()))-(d1.rdn(d1.get_year(),d1.get_month(),d1.get_day()));
                        qDebug()<<"12";

                        boolean ghar;
                        ghar = false;
                        if(days > 30)
                        {
                            ghar = true;
                            qDebug()<<"12";

                            int rest = days - 30;
                            int fine = rest * 10;
                            //now recording fine into the database
                            qDebug()<<"13";

                            QSqlQuery q11;
                            q11.prepare("insert into loans values (?,?,?,?,?,?,?,?,?)");
                            q11.bindValue(0,ui->lineEdit->text());
                            q11.bindValue(1,ui->lineEdit_2->text());
                            q11.bindValue(2,d1.get_year());
                            q11.bindValue(3,d1.get_month());
                            q11.bindValue(4,d1.get_day());
                            q11.bindValue(5,d2.get_year());
                            q11.bindValue(6,d2.get_month());
                            q11.bindValue(7,d2.get_day());
                            q11.bindValue(8,fine);
                            q11.exec();
                            qDebug()<<"14";

                            ui->label_6->show();
                            ui->label_6->setText("Item Returned successfully.Fine of Rs. " +QString::number(fine)+" is imposed !");
                            ui->label_4->hide();
                            ui->label_5->hide();
                            ui->label_7->hide();
                            ui->label_10->hide();
                        }
                        qDebug()<<"15";


                        /////////////////////////////////
                        li->remove_loan(l);
                        li->set_issue(false);
                        State * r;
                        singletonlms a;
                        r = a.getMySystem2();
                        li->set_state(r);

                        //deleting the loan
                        QSqlQuery i;
                        i.prepare("delete from loans1 where nameofuser = ? AND nameofitem = ? ");
                        i.bindValue(0,ui->lineEdit->text());
                        i.bindValue(1,ui->lineEdit_2->text());
                        i.exec();
                        qDebug()<<"16";
                        if(ghar == false)
                        {
                            ui->label_5->show();
                            ui->label_6->hide();
                            ui->label_7->hide();
                            ui->label_4->hide();
                            ui->label_10->hide();


                        }


                        ////////////////////////////////

                        if(li->no_of_holders()>0)
                        {
                            qDebug()<<"17";

                            user * iou = li->get_holder_front_holder_wala();
                            Date y(2016,01,01);
                            Date y1(2016,02,01);
                            loan * o;

                            QSqlQuery query;
                            query.prepare("insert into loans1 values (?,?,?,?,?,?,?,?)");
                            QString awa = QString::fromStdString(iou->get_name());
                            query.bindValue(0,awa);
                            awa = QString::fromStdString(li->get_title());
                            query.bindValue(1,awa);
                            query.bindValue(2,y.get_year());
                            query.bindValue(3,y.get_month());
                            query.bindValue(4,y.get_day());
                            query.bindValue(5,y1.get_year());
                            query.bindValue(6,y1.get_month());
                            query.bindValue(7,y1.get_day());
                            query.exec();
                            //tracking that book has been issued
                            QSqlQuery query1;
                            query1.prepare("UPDATE book SET flag= 1 WHERE name = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();

                            //updating hold wale

                            QString huz = QString::fromStdString(iou->get_name());
                            QString asa = QString::fromStdString(li->get_title());
                            QSqlQuery u;
                            u.prepare("delete from hold where nameofitem = ? AND nameofuser = ?");
                            u.bindValue(0,asa);
                            u.bindValue(1,huz);
                            u.exec();
                            o = new loan(iou,li,y,y1);
                            li->set_issue(true);
                            State * r;
                            singletonlms a;
                            r = a.getMySystem4();
                            li->set_state(r);

                        }
                        else
                        {
                            State * r;
                            singletonlms a;
                            r = a.getMySystem2();
                            li->set_state(r);
                            li->set_issue(false);

                            QSqlQuery query1;
                            query1.prepare("UPDATE book SET flag= 0 WHERE name = ?");
                            QString awaien =QString::fromStdString(li->get_title());
                            query1.bindValue(0,awaien);
                            query1.exec();
                        }
                    }
                }
                else if(temp1==false)
                {
                    ui->label_4->show();
                    ui->label_5->hide();
                    ui->label_6->hide();
                    ui->label_7->hide();
                    ui->label_10->hide();
                }
            }
        }
        if(temp == false)
        {
         ui->label_7->show();
         ui->label_4->hide();
         ui->label_5->hide();
         ui->label_6->hide();
         ui->label_10->hide();
        }
      }
    }
}
