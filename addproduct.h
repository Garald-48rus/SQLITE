#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QMessageBox>

namespace Ui {
class addProduct;
}

class addProduct : public QWidget
{
    Q_OBJECT

public:
    explicit addProduct(QWidget *parent = nullptr);
    ~addProduct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addProduct *ui;

private:

    QVector<QString> vec;

    bool fl{true};

signals:
    void refresh_table(QVector<QString>&);
};

#endif // ADDPRODUCT_H
