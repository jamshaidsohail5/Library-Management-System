#ifndef CHECKOUTITEMADMIN_H
#define CHECKOUTITEMADMIN_H

#include <QMainWindow>

namespace Ui {
class checkoutitemadmin;
}

class checkoutitemadmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit checkoutitemadmin(QWidget *parent = 0,QString n = "my");
    ~checkoutitemadmin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::checkoutitemadmin *ui;
    QString name;
};

#endif // CHECKOUTITEMADMIN_H
