#ifndef CLERK1_H
#define CLERK1_H

#include <QWidget>

namespace Ui {
class clerk1;
}

class clerk1 : public QWidget
{
    Q_OBJECT

public:
    explicit clerk1(QWidget *parent = 0);
    ~clerk1();

private:
    Ui::clerk1 *ui;
};

#endif // CLERK1_H
