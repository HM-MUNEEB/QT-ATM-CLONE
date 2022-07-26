#ifndef GOODBYE_H
#define GOODBYE_H

#include <QDialog>

namespace Ui {
class goodbye;
}

class goodbye : public QDialog
{
    Q_OBJECT

public:
    explicit goodbye(QWidget *parent = nullptr);
    ~goodbye();

private slots:
    void on_pushButton_done_clicked();

    void on_pushButton_quit_clicked();

    void on_pushButton_yes_clicked();

private:
    Ui::goodbye *ui;
};

#endif // GOODBYE_H
