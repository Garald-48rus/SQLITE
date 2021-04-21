#ifndef IZMPRODUCT_H
#define IZMPRODUCT_H

#include <QWidget>
#include <QVector>
#include <QString>

namespace Ui {
class izmProduct;
}

class izmProduct : public QWidget
{
    Q_OBJECT

public:
    explicit izmProduct(QWidget *parent = nullptr);
    explicit izmProduct(QVector<QString> &);

    ~izmProduct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::izmProduct *ui;

private:
    QVector<QString> vec;

signals:

    void izm_Prd(QVector<QString> &);
};

#endif // IZMPRODUCT_H
