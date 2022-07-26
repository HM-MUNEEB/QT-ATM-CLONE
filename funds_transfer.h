#ifndef FUNDS_TRANSFER_H
#define FUNDS_TRANSFER_H

#include <QDialog>

namespace Ui {
class funds_transfer;
}

class funds_transfer : public QDialog
{
    Q_OBJECT

public:
    explicit funds_transfer(QWidget *parent = nullptr);
    ~funds_transfer();

private slots:
    void on_pushButton_check_credentials_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::funds_transfer *ui;
};

#endif // FUNDS_TRANSFER_H
