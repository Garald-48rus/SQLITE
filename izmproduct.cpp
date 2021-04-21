#include "izmproduct.h"
#include "ui_izmproduct.h"


izmProduct::izmProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::izmProduct)
{
    ui->setupUi(this);
}
//===============================================
izmProduct::izmProduct(QVector<QString> & vec):
    ui(new Ui::izmProduct)
{
    ui->setupUi(this);

    auto it = vec.begin();

    ui->lineEdit->setText(*it);
    std::advance(it,1);

    ui->lineEdit_2->setText(*it);
    std::advance(it,1);

    ui->lineEdit_3->setText(*it);
    std::advance(it,1);

    ui->lineEdit_4->setText(*it);
    std::advance(it,1);

    ui->lineEdit_5->setText(*it);



}
//===================================================
izmProduct::~izmProduct()
{
    delete ui;
}
//=============================================
void izmProduct::on_pushButton_clicked()
{

    vec.clear();
    vec.push_back(ui->lineEdit->text());
    vec.push_back(ui->lineEdit_2->text());
    vec.push_back(ui->lineEdit_3->text());
    vec.push_back(ui->lineEdit_4->text());
    vec.push_back(ui->lineEdit_5->text());

    emit izm_Prd(vec);

    this->close();

}
//==================================================
