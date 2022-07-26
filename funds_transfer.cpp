#include "funds_transfer.h"
#include "ui_funds_transfer.h"
#include "main_menu.h"
#include "mainwindow.h"
#include "goodbye.h"
#include <QMessageBox>
#include <QDir>

funds_transfer::funds_transfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::funds_transfer)
{
    ui->setupUi(this);

    this->setWindowTitle("The United ATM Of Wasseypur | Funds Transfer");

    QString loginCre; //varibale for non-action processings
    loginCre = readAFile("source_files/LoginCredentials/LGI.txt");
    ui->username_ID->setText("User ID: "+loginCre);
}

funds_transfer::~funds_transfer()
{
    delete ui;
}
void funds_transfer::on_pushButton_check_credentials_clicked()
{
    QString account_number = ui->lineEdit_account_number->text();
    QString funds_transfer = ui->lineEdit_amount->text();
    QString thisUser =readAFile("source_files/LoginCredentials/LGI.txt");
    QString thisUserFunds = readAFile("source_files/"+thisUser+"/funds.txt");

    bool fundsCheck, accCheck;

    QDir transAcc("source_files/"+account_number); // Checking directory/User
    if (!transAcc.exists()){
        ui->label_account_no_warning->setText("The Account Number Does\nnot Exits!");
        ui->lineEdit_amount->setText("");
        ui->lineEdit_account_number->setText("");
        QMessageBox::warning(this, "Error 404", "The credentials you have entered does not exits!");
        accCheck = false;
    } else {// if the directory/User exits in the system
        accCheck = true;
    }
// As this is a funds tranfering module, hence the exection of checking for 500 multiples does not requires
    if(funds_transfer.toInt() <= thisUserFunds.toInt()){
        qDebug() << "User have enough funds for transfer!";
        fundsCheck =  true;// true if user have enough funds to transfer
    }else{
        qDebug() << "User does,nt have enough funds for transfer!";
        ui->label_funds_warning->setText("DO NOT HAVE ENOUGH FUNDS!");
        QMessageBox::information(this, "Information", "You do not have enough funds!");
        ui->lineEdit_amount->setText("");
        fundsCheck = false;
    }
    if(account_number == thisUser){
        QMessageBox::warning(this, "Warning", "Invalid account number!");
        ui->lineEdit_account_number->setText("");
        ui->lineEdit_amount->setText("");
        accCheck = false;
    }
    if(fundsCheck && accCheck){//If user have enough funds and the TO-BE_TRANSFER-TO acocunt also exists
            qDebug() << "Dirctory exists!" << account_number;
            ui->label_account_no_warning->setText("");

            QString funds = readAFile("source_files/"+account_number+"/funds.txt"); // to transfer
            QString fundsRetr = ui->lineEdit_amount->text();//to be transfered
            qDebug() << "This user funds are: " << thisUserFunds;
            qDebug() << "Retrived funds are: " << fundsRetr;
            qDebug() << "Specefied acoound funds are: " << funds;

            int remAmount = (thisUserFunds.toInt()) - (fundsRetr.toInt());
            QString x = QString::number(remAmount);
            qDebug() << "The value of x: " << x;
            writeAFile("funds", x, "source_files/"+thisUser+"/funds.txt");

            int finalAmount = (funds.toInt()) + (fundsRetr.toInt());
            QString s = QString::number(finalAmount);
            qDebug() << "The value of s: " << s;
            writeAFile("funds", s , "source_files/"+account_number+"/funds.txt");

            ui->lineEdit_amount->setText("");
            ui->lineEdit_account_number->setText("");


            QMessageBox::information(this, "Successfull!", "The Transaction was made Sucessfull to Account Number: "+account_number);
            hide();

            goodbye goodBye;
            goodBye.setModal(true);
            goodBye.exec();

    }else {
        qDebug() << "Requirement does not full fill!";
    }
}

void funds_transfer::on_pushButton_quit_clicked()
{
    hide();
    main_menu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}
