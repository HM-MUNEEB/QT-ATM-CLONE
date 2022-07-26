#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>

bool LoginAccess(QString accN, QString pin, QString path);
void writeAFile(QString filename,QString contents, QString path);
QString readAFile(QString path);


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_signIn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
