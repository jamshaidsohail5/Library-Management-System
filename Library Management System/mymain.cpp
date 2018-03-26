#include "mymain.h"
#include "ui_mymain.h"
#include"search.h"
#include<QDebug>
#include <QSql>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtCore>
#include<QtGui>
#include"issuebook.h"
#include"issuebook1.h"
#include"issuebook2.h"
#include"issuedvd.h"
#include"issuedvd1.h"
#include"issuedvd2.h"
#include"listitems.h"
#include"checkinitem.h"
#include"checkinitemclerk.h"
#include"checkoutitemadmin.h"
#include"checkoutitemclerk.h"
#include"mainwindow.h"
#include"addboroweradmin.h"
#include"addborowerclerk.h"
#include"updateborowerclerk.h"
#include"updateboroweradmin.h"
#include"aditem.h"
#include"removeitem.h"







mymain::mymain(QWidget *parent,QString i,QString relate) :
    QWidget(parent),
    ui(new Ui::mymain)
{
    ui->setupUi(this);
    idea = i;
    related =relate;
    if(idea == "Admin")
    {
        //hiding borower
        ui->label1->hide();
        ui->button1->hide();
        ui->button2->hide();
        ui->button4->hide();
        ui->Dvd->hide();

        //hiding clerk
        ui->label2->hide();
        ui->button5->hide();
        ui->button6->hide();

        ui->button8->hide();
        ui->button9->hide();
        ui->button10->hide();
        ui->button11->hide();
        ui->button12->hide();
        ui->Dvd2->hide();



        //showing admin
        ui->label3->show();
        ui->button13->show();
        ui->button14->show();
        ui->button16->show();
        ui->button17->show();
        ui->button18->show();
        ui->button19->show();
        ui->button20->show();
        ui->button21->show();
        ui->button22->show();
        ui->Dvd1->show();





    }
    else if(idea == "Student")
    {
        //hiding clerk
        ui->label2->hide();
        ui->button5->hide();
        ui->button6->hide();

        ui->button8->hide();
        ui->button9->hide();
        ui->button10->hide();
        ui->button11->hide();
        ui->button12->hide();
        ui->Dvd2->hide();

        //hiding admin
        ui->label3->hide();
        ui->button13->hide();
        ui->button14->hide();
        ui->button16->hide();
        ui->button17->hide();
        ui->button18->hide();
        ui->button19->hide();
        ui->button20->hide();
        ui->button21->hide();
        ui->button22->hide();
        ui->Dvd1->hide();


        //showing student
        ui->label1->show();
        ui->button1->show();
        ui->button2->show();
        ui->button4->show();
        ui->Dvd->show();
    }
    else if(idea == "Clerk")
    {
        //hiding student
        ui->label1->hide();
        ui->button1->hide();
        ui->button2->hide();
        ui->button4->hide();
        ui->Dvd->hide();
        //hiding admin
        ui->label3->hide();
        ui->button13->hide();
        ui->button14->hide();
        ui->button16->hide();
        ui->button17->hide();
        ui->button18->hide();
        ui->button19->hide();
        ui->button20->hide();
        ui->button21->hide();
        ui->button22->hide();
        ui->Dvd1->hide();
        // showing clerk
        ui->label2->show();
        ui->button5->show();
        ui->button6->show();

        ui->button8->show();
        ui->button9->show();
        ui->button10->show();
        ui->button11->show();
        ui->button12->show();
        ui->Dvd2->show();
    }
}

mymain::~mymain()
{
    delete ui;
}



void mymain::on_button1_clicked()
{

    Search *srch=new Search(this->parentWidget());
    srch->show();


}

void mymain::on_button2_clicked()
{
    //Issue book or dvd for borrower
    issuebook1 *my = new issuebook1(this->parentWidget(),related);
    my->show();

}

void mymain::on_button3_clicked()
{

}

void mymain::on_button4_clicked()
{
    listitems * i = new listitems(this->parentWidget(),related);
    i->show();
}

void mymain::on_button13_clicked()
{

    Search *srch=new Search(this->parentWidget());
    srch->show();
}

void mymain::on_button14_clicked()
{

    issuebook *my = new issuebook(this->parentWidget(),related);
    my->show();


}

void mymain::on_button15_clicked()
{

}

void mymain::on_button16_clicked()
{
    listitems * i = new listitems(this->parentWidget(),related);
    i->show();

}

void mymain::on_button17_clicked()
{
    //check in item
    Checkinitem * n = new Checkinitem(this->parentWidget(),related);
    n->show();

}

void mymain::on_button18_clicked()
{
    checkoutitemadmin * c =new checkoutitemadmin(this->parentWidget(),related);
    c->show();


}

void mymain::on_button19_clicked()
{
    addboroweradmin * q = new addboroweradmin(this->parentWidget(),related);
    q->show();


}

void mymain::on_button20_clicked()
{
    updateboroweradmin * a  = new updateboroweradmin(this->parentWidget(),related);
    a->show();

}

void mymain::on_button21_clicked()
{
    aditem * n = new aditem(this->parentWidget(),related);
    n->show();


}

void mymain::on_button22_clicked()
{
    removeitem * r = new removeitem(this->parentWidget(),related);
    r->show();

}

void mymain::on_button5_clicked()
{

    Search *srch=new Search(this->parentWidget());
    srch->show();


}

void mymain::on_button6_clicked()
{
    issuebook2 * i = new issuebook2(this->parentWidget(),related);

    i->show();
}

void mymain::on_button7_clicked()
{

}

void mymain::on_button8_clicked()
{
    listitems * i = new listitems(this->parentWidget(),related);
    i->show();


}

void mymain::on_button9_clicked()
{
    //check in item by clerk
    checkinitemclerk * i = new checkinitemclerk(this->parentWidget(),related);
    i->show();
}

void mymain::on_button10_clicked()
{
    checkoutitemclerk * c =new checkoutitemclerk(this->parentWidget(),related);
    c->show();

}

void mymain::on_button11_clicked()
{
    addborowerclerk * c = new addborowerclerk (this->parentWidget(),related);
    c->show();

}

void mymain::on_button12_clicked()
{
    updateborowerclerk * n = new updateborowerclerk(this->parentWidget(),related);
    n->show();


}

void mymain::on_Dvd_clicked()
{
    issuedvd * d = new issuedvd(this->parentWidget(),related);
    d->show();

}

void mymain::on_Dvd1_clicked()
{
    issuedvd1 * d = new issuedvd1(this->parentWidget(),related);
    d->show();

}

void mymain::on_Dvd2_clicked()
{
    issuedvd2 * d = new issuedvd2(this->parentWidget(),related);
    d->show();
}

void mymain::on_pushButton_clicked()
{
    MainWindow *m = new MainWindow(this->parentWidget());
    this->hide();
    m->show();

}
