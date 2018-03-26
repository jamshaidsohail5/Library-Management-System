#ifndef ISSUEDVD1_H
#define ISSUEDVD1_H

#include <QMainWindow>

namespace Ui {
class issuedvd1;
}

class issuedvd1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuedvd1(QWidget *parent = 0,QString n ="m");
    ~issuedvd1();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    
private:
    Ui::issuedvd1 *ui;
    QString name;
};

#endif // ISSUEDVD1_H
