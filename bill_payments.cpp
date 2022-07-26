#include "bill_payments.h"
#include "ui_bill_payments.h"
#include "main_menu.h"
#include "mainwindow.h"


bill_payments::bill_payments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bill_payments)
{
    ui->setupUi(this);

    this->setWindowTitle("The United ATM Of Wasseypur | Bill Payments");

    QString loginCre; //varibale for non-action processings
    loginCre = readAFile("source_files/LoginCredentials/LGI.txt");
    ui->username_ID->setText("User ID: "+loginCre);
}

bill_payments::~bill_payments()
{
    delete ui;
}

void bill_payments::on_pushButton_quit_clicked()
{
    close();
}

void bill_payments::on_pushButton_yes_clicked()
{
    hide();
    main_menu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}
