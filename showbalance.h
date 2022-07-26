#ifndef SHOWBALANCE_H
#define SHOWBALANCE_H
#include "main_menu.h"
#include <QDialog>

namespace Ui {
class showBalance;
}

class showBalance : public QDialog
{
    Q_OBJECT

public:
    explicit showBalance(QWidget *parent = nullptr);
    ~showBalance();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_done_clicked();

private:
    Ui::showBalance *ui;
};

#endif // SHOWBALANCE_H
