#ifndef STUDENT1_H
#define STUDENT1_H

#include <QWidget>

namespace Ui {
class student1;
}

class student1 : public QWidget
{
    Q_OBJECT

public:
    explicit student1(QWidget *parent = 0);
    ~student1();

private:
    Ui::student1 *ui;
};

#endif // STUDENT1_H
