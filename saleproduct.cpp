#include "saleproduct.h"
#include "ui_saleproduct.h"


SaleProduct::SaleProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaleProduct)
{
    ui->setupUi(this);
}
//=============================================
SaleProduct::SaleProduct(QVector<QString> & vec):
    ui(new Ui::SaleProduct)
{
    ui->setupUi(this);

    auto it = vec.begin();

    ui->lineEdit->setText(*it);
    std::advance(it,1);

    ui->lineEdit_2->setText(*it);
    std::advance(it,1);

    date = *it;
    std::advance(it,1);

    ui->dateEdit->setDate(QDate::currentDate());

    ui->lineEdit_5->setText(*it);
    std::advance(it,1);

    ui->lineEdit_4->setText(*it);
    std::advance(it,1);

}
//============================================
SaleProduct::~SaleProduct()
{
    delete ui;
}
//==============================================
void SaleProduct::on_pushButton_2_clicked()
{
    if(ui->lineEdit_3->text().toInt() > ui->lineEdit_2->text().toInt() || ui->lineEdit_3->text().toInt() <= 0){

        QMessageBox::information(this, "Информация", "Поле Колличество на реализацию заполнено не корректно");
   }

      tmp = ui->lineEdit_3->text().toDouble() * ui->lineEdit_5->text().toDouble();

      ui->lineEdit_6->setText(QString::number(tmp));

      ui->pushButton->setEnabled(true);
}
//==================================================
void SaleProduct::on_pushButton_clicked()
{

    vec.clear();
    vec.push_back(ui->lineEdit->text());
    vec.push_back(QString::number(ui->lineEdit_2->text().toInt() - ui->lineEdit_3->text().toInt()));
    vec.push_back(date);
    vec.push_back(ui->lineEdit_5->text());
    vec.push_back(ui->lineEdit_4->text());

    emit upd_data(vec);

    vec.clear();

    vec.push_back(ui->lineEdit->text());
    vec.push_back(ui->lineEdit_3->text());
    vec.push_back(ui->dateEdit->text());
    vec.push_back(ui->lineEdit_5->text());
    vec.push_back(ui->lineEdit_6->text());
    vec.push_back(ui->lineEdit_4->text());

    emit sale_data(vec);

    this->close();
}
