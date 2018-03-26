#ifndef ISSUEDVD2_H
#define ISSUEDVD2_H

#include <QMainWindow>

namespace Ui {
class issuedvd2;
}

class issuedvd2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuedvd2(QWidget *parent = 0,QString na = "mu");
    ~issuedvd2();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_activated(const QString &arg1);


private:
    Ui::issuedvd2 *ui;
    QString name;
};

#endif // ISSUEDVD2_H
