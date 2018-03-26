#include "search.h"
#include "ui_search.h"
#include "singletonlms.h"

Search::Search(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Search by title");
    ui->comboBox->addItem("Search by author");
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    singletonlms lms;
    if(ui->comboBox->currentText()=="Search by title")
    {
        if(lms.getMySystem()->search_items(ui->lineEdit->text().toStdString())!=nullptr)
            ui->label->setText("Found");
        else
            ui->label->setText("Not Found");
    }
    else if(ui->comboBox->currentText()=="Search by author")
    {
        if(lms.getMySystem()->search_by_author(ui->lineEdit->text().toStdString())!=nullptr)
            ui->label->setText("Found");
        else
            ui->label->setText("Not Found");
    }

}
void Search::on_lineEdit_textChanged(const QString &arg1)
{
    ui->label->setText("");
}
