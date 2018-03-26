#ifndef ADITEM_H
#define ADITEM_H

#include <QMainWindow>

namespace Ui {
class aditem;
}

class aditem : public QMainWindow
{
    Q_OBJECT

public:
    explicit aditem(QWidget *parent = 0,QString  n = "ja");
    ~aditem();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::aditem *ui;
    QString name;
};

#endif // ADITEM_H
