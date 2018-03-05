#include "mainwindow.h"
#include "ui_mainwindow.h"

QString id;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButton_clicked()
{
    dialogLogin.show();
    dialogLogin.selectFunct(1);
    //this->hide();
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    dialogLogin.show();
    dialogLogin.selectFunct(2);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    dialogLogin.show();
    dialogLogin.selectFunct(3);
}
