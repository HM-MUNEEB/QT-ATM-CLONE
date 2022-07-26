#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class main_menu;
}

class main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = nullptr);
    ~main_menu();

private slots:
    void on_cash_withdraw_btn_clicked();

    void on_cash_withdraw_btn_2_clicked();

    void on_show_balance_btn_clicked();

    void on_fund_transfer_clicked();

    void on_bill_payments_btn_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::main_menu *ui;
};




#endif // MAIN_MENU_H
