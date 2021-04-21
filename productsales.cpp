#include "productsales.h"
#include "ui_productsales.h"

#include "db.h"

Productsales::Productsales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Productsales)
{
    ui->setupUi(this);
}
//===============================================
Productsales::Productsales(QSqlTableModel* model):
    ui(new Ui::Productsales)
{
   ui->setupUi(this);
   ui->tableView->setModel(model);
   ui->tableView->resizeColumnsToContents();
   ui->tableView->show();

   ui->lineEdit->setText(QString::number(total));

}
//===========================================
Productsales::~Productsales()
{
    delete ui;
}
//==============================================
void Productsales::on_pushButton_clicked()
{
    this->close();
}
