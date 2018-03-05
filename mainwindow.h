#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialoglogin.h>
#include <head.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_2_clicked();

private:
    Ui::MainWindow *ui;
    DialogLogin dialogLogin;
};

#endif // MAINWINDOW_H
