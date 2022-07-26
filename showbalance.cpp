#include "showbalance.h"
#include "ui_showbalance.h"
#include "mainwindow.h"
#include "goodbye.h"

showBalance::showBalance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showBalance)
{
    ui->setupUi(this);

    this->setWindowTitle("The United ATM Of Wasseypur | Show Balance");

    QString loginCre; //varibale for non-action processings
    QString fullName;
    QString funds;
    loginCre = readAFile("source_files/LoginCredentials/LGI.txt");
    fullName = readAFile("source_files/"+loginCre+"/"+"full_name.txt");
    ui->username_ID->setText("User ID: "+loginCre);
    funds = readAFile("source_files/"+loginCre+"/funds.txt");
    ui->label_show_balance->setText(funds+" Rs");
}

showBalance::~showBalance()
{
    delete ui;
}

void showBalance::on_pushButton_back_clicked()
{
    hide();
    main_menu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();

}

void showBalance::on_pushButton_done_clicked()
{
    hide();
    goodbye goodBye;
    goodBye.setModal(true);
    goodBye.exec();
}
