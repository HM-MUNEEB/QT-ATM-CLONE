#include "main_menu.h"
#include "mainwindow.h"
#include "ui_main_menu.h"
#include "showbalance.h"
#include "cash_withdraw.h"
#include "funds_transfer.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QPixmap>
#include "bill_payments.h"



main_menu::main_menu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);

    this->setWindowTitle("The United ATM Of Wasseypur | Main Menu");

    QString loginCre; //varibale for non-action processings
    QString fullName;

    loginCre = readAFile("source_files/LoginCredentials/LGI.txt");
    fullName = readAFile("source_files/"+loginCre+"/"+"full_name.txt");
    ui->username_ID->setText("User ID: "+loginCre);
    ui->user_full_name->setText(fullName);

    int w = ui->label_mainLogo->width();
    int h = ui->label_mainLogo->height();
    QPixmap logo("images_and_visuals/Wasseypur_logo.png");
    ui->label_mainLogo->setPixmap(logo.scaled(w, h, Qt:: KeepAspectRatio));
}

main_menu::~main_menu()
{
    delete ui;
}
void main_menu::on_cash_withdraw_btn_clicked()
{
    hide();
    cash_withdraw cashWithDraw;
    cashWithDraw.setModal(true);
    cashWithDraw.exec();

}
void main_menu::on_cash_withdraw_btn_2_clicked()
{
}
void main_menu::on_show_balance_btn_clicked()
{
    hide();
    showBalance show_balance;
    show_balance.setModal(true);
    show_balance.exec();
}

void main_menu::on_fund_transfer_clicked()
{
    hide();
    funds_transfer fundsTransfer;
    fundsTransfer.setModal(true);
    fundsTransfer.exec();
}

void main_menu::on_bill_payments_btn_clicked()
{
    hide();
    bill_payments billPayments;
    billPayments.setModal(true);
    billPayments.exec();
}

void main_menu::on_pushButton_quit_clicked()
{
    close();
}
