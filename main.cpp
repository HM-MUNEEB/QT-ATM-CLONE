#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./   images_and_visuals/icon.ico"));
    MainWindow w;
    //w.setStyleSheet("background-image:url(:Main_window.jpg)");
    w.show();
    return a.exec();
}
