#ifndef CHECKINITEM_H
#define CHECKINITEM_H

#include <QMainWindow>

namespace Ui {
class Checkinitem;
}

class Checkinitem : public QMainWindow
{
    Q_OBJECT

public:
    explicit Checkinitem(QWidget *parent = 0,QString n = "my");
    ~Checkinitem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Checkinitem *ui;
    QString name;
};

#endif // CHECKINITEM_H
