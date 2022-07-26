#include "goodbye.h"
#include "ui_goodbye.h"
#include "main_menu.h"
#include "mainwindow.h"

goodbye::goodbye(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::goodbye)
{
    ui->setupUi(this);

    this->setWindowTitle("The United ATM Of Wasseypur | Good Bye");

    QString loginCre; //varibale for non-action processings
    loginCre = readAFile("source_files/LoginCredentials/LGI.txt");
    ui->username_ID->setText("User ID: "+loginCre);
}

goodbye::~goodbye()
{
    delete ui;

}

void goodbye::on_pushButton_done_clicked()
{

}

void goodbye::on_pushButton_quit_clicked()
{
    close();
}

void goodbye::on_pushButton_yes_clicked()
{
    hide();
    main_menu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}
