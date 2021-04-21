#include "addproduct.h"
#include "ui_addproduct.h"


addProduct::addProduct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addProduct)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

addProduct::~addProduct()
{
    delete ui;
}

void addProduct::on_pushButton_clicked()
{
    fl = true;

    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty())
    {
      QMessageBox::information(this, "Информация", "Не все поля заполнены");
      fl = false;

    }

    if(fl){
       for(auto &it: ui->lineEdit_3->text()){


           if(it.unicode() < 48 || it.unicode() > 57 ){
           if(it.unicode() == 46) continue;
           fl = false;
          QMessageBox::information(this, "Информация", "Поле цены заполнено не корректно");
          break;

       }

    }
  }
     if(fl){

         for(auto &it: ui->lineEdit_2->text()){
             if(it.unicode() < 48 || it.unicode() > 57 ){
             fl = false;
            QMessageBox::information(this, "Информация", "Поле колличество заполнено не корректно");
            break;
         }

      }

     }

    if(fl) {

       vec.clear();
      vec.push_back(ui->lineEdit->text());
      vec.push_back(ui->lineEdit_2->text());
      vec.push_back(ui->dateEdit->text());
      vec.push_back(ui->lineEdit_3->text());

      emit refresh_table(vec);

      this->close();
    }


}
//==================================================

