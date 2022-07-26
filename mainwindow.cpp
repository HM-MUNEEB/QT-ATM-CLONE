#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main_menu.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QPixmap>
#include <QTransform>

bool LoginAccess(QString accN, QString pin, QString path);
void writeAFile(QString filename,QString contents, QString path);
QString readAFile(QString path);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("The United ATM Of Wasseypur");

    int w = ui->label_mainLogo->width();
    int h = ui->label_mainLogo->height();

    QPixmap logo("images_and_visuals/Wasseypur_logo.png");
    ui->label_mainLogo->setPixmap(logo.scaled(w, h, Qt:: KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
// Funtion which creates a file; if it does not exists
void writeAFile(QString filename,QString contents, QString path){
    QFile loginCre(path);
    if ( !loginCre.open(QFile::WriteOnly | QFile::Text) )
        {
            qDebug() << "Acc File Not located: " <<path;
        }
    QTextStream out(&loginCre);
    out << contents;
    loginCre.flush();
    loginCre.close();
}
// Funtion which read a file that if it does exists

QString readAFile(QString path){
    QFile loginCreFile(path);
    if (!loginCreFile.open(QFile::ReadOnly | QFile::Text) )
        {
            qDebug() << "File Not located: " << path;

        }
    QTextStream in(&loginCreFile);
    QString dumy = in.readAll();
    loginCreFile.close();
    return dumy;
}

bool LoginAccess(QString accN, QString pin,QString Filepath){

    //this funtion checks whether the login credentials are valid or not
    QFile loginAccFile(Filepath+"accN.txt");
    if ( !loginAccFile.open(QFile::ReadOnly | QFile::Text) )
        {
            qDebug() << "Acc File Not located: " << Filepath+"accN.txt";
            return false;
        }
    QTextStream in(&loginAccFile);
    QString fileAC = in.readAll();
    loginAccFile.close();

    // Checking for pin and its file
    QFile loginPinFile(Filepath+"pin.txt");
    if ( !loginPinFile.open(QFile::ReadOnly | QFile::Text) )
        {
            qDebug() << "Pin File Not located: " << Filepath+"pin.txt";
            return false;
        }
    QTextStream inPin(&loginPinFile);
    QString filePC = inPin.readAll();
    loginPinFile.close();

    qDebug() << "The retrived acc is: " << fileAC;
    //checking the given credentials are valid

    if(fileAC == accN && filePC == pin){
        return true;
    } else {
        return false;
    }

}

void MainWindow::on_pushButton_signIn_clicked()
{
    qDebug() << "Login clicked!" << endl;
    QString login_accN = ui->lineEdit_accN->text();
    QString login_password = ui->lineEdit_pin->text();
    QDir dir;
    qDebug() << QDir().currentPath(); // checking for current dirctory
    bool login_access = LoginAccess(login_accN, login_password,"source_files/"+login_accN+"/");
    qDebug() << login_access;

    // if the provided credentials match the actual
    // credentials then, program shifts to new window
    if(login_access){
        ui->login_page_warning->setText("");
        QDir dirLogin("source_files/LoginCredentials"); // Checking directory
        if (!dirLogin.exists()){
            dirLogin.mkpath("."); // creates directory "Login Credentials"
        } else {
            qDebug() << "Dirctory exists: LogiCredentials";
        }
        writeAFile(login_accN,login_accN, "source_files/LoginCredentials/LGI.txt");
        hide();
        main_menu mainMenu;
        mainMenu.setModal(true);
        mainMenu.exec();
    } else {
        ui->login_page_warning->setText("Account Number or pin is wrong!");
    }

}
