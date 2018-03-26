#ifndef UPDATEBOROWERADMIN_H
#define UPDATEBOROWERADMIN_H

#include <QMainWindow>

namespace Ui {
class updateboroweradmin;
}

class updateboroweradmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit updateboroweradmin(QWidget *parent = 0,QString n = "mu");
    ~updateboroweradmin();

private slots:

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::updateboroweradmin *ui;
    QString name;
};

#endif // UPDATEBOROWERADMIN_H
