#ifndef SALEPRODUCT_H
#define SALEPRODUCT_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QMessageBox>

namespace Ui {
class SaleProduct;
}

class SaleProduct : public QWidget
{
    Q_OBJECT

public:
    explicit SaleProduct(QWidget *parent = nullptr);
    explicit SaleProduct(QVector<QString> &);
    ~SaleProduct();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::SaleProduct *ui;

private:

    QVector<QString> vec;

    double tmp{};
    QString date{};

signals:
    void upd_data(QVector<QString> &);
    void sale_data(QVector<QString> &);
};


#endif // SALEPRODUCT_H
