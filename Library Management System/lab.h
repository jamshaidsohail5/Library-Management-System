#ifndef LAB_H
#define LAB_H

#include <QMainWindow>

namespace Ui {
class Lab;
}

class Lab : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lab(QWidget *parent = 0);
    ~Lab();

private:
    Ui::Lab *ui;
};

#endif // LAB_H
