#ifndef ISSUEBOOK1_H
#define ISSUEBOOK1_H

#include <QMainWindow>

namespace Ui {
class issuebook1;
}

class issuebook1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuebook1(QWidget *parent = 0,QString n = "my");
    ~issuebook1();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::issuebook1 *ui;
QString name;

};

#endif // ISSUEBOOK1_H
