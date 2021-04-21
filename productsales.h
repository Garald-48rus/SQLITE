#ifndef PRODUCTSALES_H
#define PRODUCTSALES_H

#include <QWidget>
#include <QSqlTableModel>


namespace Ui {
class Productsales;
}

class Productsales : public QWidget
{
    Q_OBJECT

public:
    explicit Productsales(QWidget *parent = nullptr);
    explicit Productsales(QSqlTableModel*);
    ~Productsales();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Productsales *ui;
};

#endif // PRODUCTSALES_H
