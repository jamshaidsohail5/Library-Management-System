#ifndef CHECKINITEMCLERK_H
#define CHECKINITEMCLERK_H

#include <QMainWindow>

namespace Ui {
class checkinitemclerk;
}

class checkinitemclerk : public QMainWindow
{
    Q_OBJECT

public:
    explicit checkinitemclerk(QWidget *parent = 0,QString n = "my");
    ~checkinitemclerk();

private slots:
    void on_pushButton_clicked();

private:
    Ui::checkinitemclerk *ui;
    QString name;
};

#endif // CHECKINITEMCLERK_H
