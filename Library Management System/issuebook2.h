#ifndef ISSUEBOOK2_H
#define ISSUEBOOK2_H

#include <QMainWindow>

namespace Ui {
class issuebook2;
}

class issuebook2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuebook2(QWidget *parent = 0,QString n="AD");
    ~issuebook2();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::issuebook2 *ui;
    QString name;
};

#endif // ISSUEBOOK2_H
