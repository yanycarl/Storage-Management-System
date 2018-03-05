#include "mainwindowui.h"
#include "ui_mainwindowui.h"

MainWindowUI::MainWindowUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowUI)
{
    ui->setupUi(this);
}

MainWindowUI::~MainWindowUI()
{
    delete ui;
}

void MainWindowUI::on_commandLinkButton_clicked()
{
    wci.show();
    wci.setUpData();
}

void MainWindowUI::on_commandLinkButton_2_clicked()
{
    wao.show();
    wao.setUpData();
}

void MainWindowUI::on_commandLinkButton_4_clicked()
{
    wag.show();
}

void MainWindowUI::on_commandLinkButton_6_clicked()
{
    wcg.show();
    wcg.setUpData();
}

void MainWindowUI::on_commandLinkButton_5_clicked()
{
    ws.show();
    ws.setUpData();
}

void MainWindowUI::on_commandLinkButton_3_clicked()
{
    wco.show();
    wco.setUpData();
}

void MainWindowUI::on_commandLinkButton_7_clicked()
{
    sui.show();
}

void MainWindowUI::on_commandLinkButton_8_clicked()
{
    t.show();
}
