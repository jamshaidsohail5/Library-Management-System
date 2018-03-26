#ifndef LISTITEMS_H
#define LISTITEMS_H

#include <QMainWindow>

namespace Ui {
class listitems;
}

class listitems : public QMainWindow
{
    Q_OBJECT

public:
    explicit listitems(QWidget *parent = 0,QString name="ad");
    ~listitems();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listitems *ui;
    QString name;
};

#endif // LISTITEMS_H
