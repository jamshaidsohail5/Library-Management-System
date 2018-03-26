#ifndef ADDITEM_H
#define ADDITEM_H

#include <QMainWindow>

namespace Ui {
class additem;
}

class additem : public QMainWindow
{
    Q_OBJECT

public:
    explicit additem(QWidget *parent = 0,QString n ="a");
    ~additem();

private:
    Ui::additem *ui;
    QString name;
};

#endif // ADDITEM_H
