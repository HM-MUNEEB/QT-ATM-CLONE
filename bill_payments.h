#ifndef BILL_PAYMENTS_H
#define BILL_PAYMENTS_H

#include <QDialog>

namespace Ui {
class bill_payments;
}

class bill_payments : public QDialog
{
    Q_OBJECT

public:
    explicit bill_payments(QWidget *parent = nullptr);
    ~bill_payments();

private slots:
    void on_pushButton_quit_clicked();

    void on_pushButton_yes_clicked();

private:
    Ui::bill_payments *ui;
};

#endif // BILL_PAYMENTS_H
