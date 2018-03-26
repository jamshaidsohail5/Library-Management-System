#ifndef ISSUEDVD_H
#define ISSUEDVD_H

#include <QMainWindow>

namespace Ui {
class issuedvd;
}

class issuedvd : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuedvd(QWidget *parent = 0,QString i = "mu");
    ~issuedvd();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_activated(const QString &arg1);


private:
    Ui::issuedvd *ui;
    QString name;
};

#endif // ISSUEDVD_H
