#ifndef REMOVEITEM_H
#define REMOVEITEM_H

#include <QMainWindow>

namespace Ui {
class removeitem;
}

class removeitem : public QMainWindow
{
    Q_OBJECT

public:
    explicit removeitem(QWidget *parent = 0,QString n = "my");
    ~removeitem();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::removeitem *ui;
    QString name;
};

#endif // REMOVEITEM_H
