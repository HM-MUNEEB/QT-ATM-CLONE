#include "cash_withdraw.h"
#include "ui_cash_withdraw.h"
#include "mainwindow.h"
#include "main_menu.h"
#include "goodbye.h"
#include <QMessageBox>
#include <QDebug>

cash_withdraw::cash_withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cash_withdraw)
{
    ui->setupUi(this);

    this->setWindowTitle("The United ATM Of Wasseypur | Cash Withdraw");

    QString loginCre; //varibale for non-action processings

    loginCre = readAFile("source_files/LoginCredentials/LGI.txt");
    ui->username_ID->setText("User ID: "+loginCre);
}

cash_withdraw::~cash_withdraw()
{
    delete ui;
}

void cash_withdraw::on_pushButton_back_clicked()
{
    hide();
    main_menu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();

}

void cash_withdraw::on_pushButton_done_clicked()
{
    QString userID = readAFile("source_files/LoginCredentials/LGI.txt");
    QString funds = readAFile("source_files/"+userID+"/funds.txt");
    qDebug() << "User ID: " << userID;
    qDebug() << "Retrived funds: " << funds;

    QString fundsRetr = ui->lineEdit_funds->text();

    bool fundsCheck = false;
    if(fundsRetr.toInt() % 500 == 0){
        qDebug() << "Cash withdraw funds are infact multiples of 500";
        if(fundsRetr.toInt() <= funds.toInt()){
            qDebug() << "User have enough funds for transfer!";
            fundsCheck =  true;// true if user have enough funds to transfer
        }else{
            qDebug() << "User does,nt have enough funds for transfer!";
            ui->label_funds_warning->setText("DO NOT HAVE ENOUGH FUNDS!");
            QMessageBox::information(this, "Information", "You do not have enough funds!");
            ui->lineEdit_funds->setText("");
            fundsCheck = false;
        }
    } else {
        ui->label_funds_warning->setText("PLEASE ENTER MULTIPLES OF 500");
        ui->lineEdit_funds->setText("");
        qDebug() << "Cash withdraw funds are not multiples of 500";
        fundsCheck = false;
    }
    if(fundsCheck){
        int finalAmount = funds.toInt() - fundsRetr.toInt();
        qDebug() << "Final amount : " << finalAmount;
        QString s = QString::number(finalAmount);
        writeAFile(funds, s , "source_files/"+userID+"/funds.txt");
        ui->lineEdit_funds->setText("");
        ui->label_funds_warning->setText("");
        QMessageBox::information(this, "Information", "The given funds have been withdrawn through your account: " + fundsRetr+" Rs");
        hide();
        goodbye goodBye;
        goodBye.setModal(true);
        goodBye.exec();
    }else {
        qDebug() << "Credentials not valid!";
    }

}
