#ifndef SEARCH_H
#define SEARCH_H

#include <QMainWindow>

namespace Ui {
class Search;
}

class Search : public QMainWindow
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
