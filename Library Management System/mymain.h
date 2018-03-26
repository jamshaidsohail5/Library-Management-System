#ifndef MYMAIN_H
#define MYMAIN_H

#include <QWidget>

namespace Ui {
class mymain;
}

class mymain : public QWidget
{
    Q_OBJECT

public:
    explicit mymain(QWidget *parent = 0,QString i="Admin",QString related = "1");
    ~mymain();

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button13_clicked();

    void on_button14_clicked();

    void on_button15_clicked();

    void on_button16_clicked();

    void on_button17_clicked();

    void on_button18_clicked();

    void on_button19_clicked();

    void on_button20_clicked();

    void on_button21_clicked();

    void on_button22_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_button10_clicked();

    void on_button11_clicked();

    void on_button12_clicked();

    void on_Dvd_clicked();

    void on_Dvd1_clicked();

    void on_Dvd2_clicked();

    void on_pushButton_clicked();

private:
    QString idea;
    QString related;
    Ui::mymain *ui;
};

#endif // MYMAIN_H
