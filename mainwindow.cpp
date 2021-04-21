#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//================================================
MainWindow::~MainWindow()
{
    delete ui;
    delete maddPrd;
    delete mizmPrd;
    delete msalePrd;
    delete mprdSales;
}

//================================================
void MainWindow::on_pushButton_clicked()
{
    if(!mDB.GreateDb()){


         QMessageBox::information(this, "Информация", "Соединение с базой данных не установлено");
    }
    else {
         QMessageBox::information(this, "Информация", "Соединение с базой данных установлено");

         ui->pushButton->setEnabled(false);
         ui->pushButton_2->setEnabled(true);
         ui->pushButton_3->setEnabled(true);
         ui->pushButton_7->setEnabled(true);
    }

}
//===================================================
void MainWindow::on_pushButton_2_clicked()
{

    ui->tableView->setModel(mDB.GetProduct());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();

}
//==================================================================
void MainWindow::on_pushButton_3_clicked()
{

   maddPrd = new addProduct();
   connect(maddPrd, &addProduct::refresh_table, this, &MainWindow::add_product);
   maddPrd->show();

}
//=============================================================
void MainWindow::add_product(QVector<QString> &vec)
{

    mDB.addProduct(vec);

    on_pushButton_2_clicked();
}
//============================================================

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    id = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt();
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
}
//====================================================
void MainWindow::on_pushButton_4_clicked()
{
    if(mDB.delProduct(id))
    {
        on_pushButton_2_clicked();
    }

    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
}
//=====================================================

void MainWindow::on_pushButton_5_clicked()
{
  mizmPrd = new izmProduct(mDB.getPoroductInfo(id));

  connect(mizmPrd, &izmProduct::izm_Prd, this, &MainWindow::upd_product);
  mizmPrd->show();


}
//===========================================================
void MainWindow::upd_product(QVector<QString> & v)
{

   if(mDB.updateProduct(v)) {

      on_pushButton_2_clicked();
      ui->pushButton_5->setEnabled(false);
      ui->pushButton_4->setEnabled(false);
      ui->pushButton_6->setEnabled(false);
   }

}
//=========================================================
void MainWindow::on_pushButton_6_clicked()
{
    msalePrd = new SaleProduct(mDB.getPoroductInfo(id));

    connect(msalePrd, &SaleProduct::upd_data, this, &MainWindow::upd_product);
    connect(msalePrd, &SaleProduct::sale_data, this, &MainWindow::add_productsales);
    msalePrd->show();
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);


}
//===============================================================
void MainWindow::add_productsales(QVector<QString> &vec)
{

   mDB.addProductSales(vec);
}
//=========================================================

void MainWindow::on_pushButton_7_clicked()
{
    mprdSales = new Productsales(mDB.GetProductSales());

    mprdSales->show();
}
//======================================================
void MainWindow::on_pushButton_8_clicked()
{

    this->close();
}
