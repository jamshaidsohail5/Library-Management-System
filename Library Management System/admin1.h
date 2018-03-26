#ifndef ADMIN1_H
#define ADMIN1_H

#include <QWidget>

namespace Ui {
class admin1;
}

class admin1 : public QWidget
{
    Q_OBJECT

public:
    explicit admin1(QWidget *parent = 0);
    ~admin1();

private:
    Ui::admin1 *ui;
};

#endif // ADMIN1_H
