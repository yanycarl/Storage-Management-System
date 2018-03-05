#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <head.h>
#include <QDialog>
#include <mainwindowui.h>
#include <superpower.h>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = 0);
    ~DialogLogin();
    selectFunct(int funct);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DialogLogin *ui;
    MainWindowUI mainWindowui;
    SuperPower sp;
};

#endif // DIALOGLOGIN_H
