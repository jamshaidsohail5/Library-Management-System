#ifndef ADDBOROWERCLERK_H
#define ADDBOROWERCLERK_H

#include <QMainWindow>

namespace Ui {
class addborowerclerk;
}

class addborowerclerk : public QMainWindow
{
    Q_OBJECT

public:
    explicit addborowerclerk(QWidget *parent = 0,QString na="mu");
    ~addborowerclerk();

private slots:
    void on_b1_clicked();

private:
    Ui::addborowerclerk *ui;
    QString name;
};

#endif // ADDBOROWERCLERK_H
