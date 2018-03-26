#include "mainwindow.h"
#include "singletonlms.h"
#include "search.h"
#include <QSql>
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QtCore>
#include<QtGui>
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


#include <QApplication>

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
