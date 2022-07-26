#ifndef CASH_WITHDRAW_H
#define CASH_WITHDRAW_H

#include <QDialog>

namespace Ui {
class cash_withdraw;
}

class cash_withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit cash_withdraw(QWidget *parent = nullptr);
    ~cash_withdraw();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_done_clicked();

private:
    Ui::cash_withdraw *ui;
};

#endif // CASH_WITHDRAW_H
