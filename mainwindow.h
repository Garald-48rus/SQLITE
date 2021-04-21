#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "db.h"

#include "addproduct.h"
#include "ui_addproduct.h"

#include "izmproduct.h"
#include "ui_izmproduct.h"

#include "saleproduct.h"
#include "ui_saleproduct.h"

#include "productsales.h"
#include "ui_productsales.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void add_product(QVector<QString> &);

    void upd_product(QVector<QString> &);

    void add_productsales(QVector<QString> &);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;

private:
DB mDB;
addProduct* maddPrd;
izmProduct* mizmPrd;
SaleProduct* msalePrd;
Productsales* mprdSales;

int id{};


};
#endif // MAINWINDOW_H
