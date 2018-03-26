#ifndef ADDBOROWERADMIN_H
#define ADDBOROWERADMIN_H

#include <QMainWindow>

namespace Ui {
class addboroweradmin;
}

class addboroweradmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit addboroweradmin(QWidget *parent = 0,QString n="mu");
    ~addboroweradmin();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_b1_clicked();

    void on_b2_clicked();

private:
    Ui::addboroweradmin *ui;
    QString name;
};

#endif // ADDBOROWERADMIN_H
