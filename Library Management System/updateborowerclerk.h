#ifndef UPDATEBOROWERCLERK_H
#define UPDATEBOROWERCLERK_H

#include <QMainWindow>

namespace Ui {
class updateborowerclerk;
}

class updateborowerclerk : public QMainWindow
{
    Q_OBJECT

public:
    explicit updateborowerclerk(QWidget *parent = 0,QString n ="mu");
    ~updateborowerclerk();

private slots:
    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::updateborowerclerk *ui;
    QString name;
};

#endif // UPDATEBOROWERCLERK_H
