#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H

#include <QMainWindow>

namespace Ui {
class issuebook;
}

class issuebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit issuebook(QWidget *parent = 0,QString n = "mera");
    ~issuebook();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::issuebook *ui;
    QString name;
};

#endif // ISSUEBOOK_H
