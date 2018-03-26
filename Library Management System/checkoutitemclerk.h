#ifndef CHECKOUTITEMCLERK_H
#define CHECKOUTITEMCLERK_H

#include <QMainWindow>

namespace Ui {
class checkoutitemclerk;
}

class checkoutitemclerk : public QMainWindow
{
    Q_OBJECT

public:
    explicit checkoutitemclerk(QWidget *parent = 0,QString n ="my");
    ~checkoutitemclerk();

private slots:
    void on_pushButton_clicked();

private:
    Ui::checkoutitemclerk *ui;
    QString name;

};

#endif // CHECKOUTITEMCLERK_H
