#include "superpower.h"
#include "ui_superpower.h"

SuperPower::SuperPower(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SuperPower)
{
    ui->setupUi(this);
}

SuperPower::~SuperPower()
{
    delete ui;
}

void SuperPower::on_commandLinkButton_clicked()
{
    wci.show();
    wci.setUpData();
}

void SuperPower::on_commandLinkButton_2_clicked()
{
    wco.show();
    wco.setUpData();
}

void SuperPower::on_commandLinkButton_4_clicked()
{
    ws.show();
    ws.setUpData();
}

void SuperPower::on_commandLinkButton_3_clicked()
{
    au.show();
    au.setUpData();
}

void SuperPower::on_commandLinkButton_5_clicked()
{
    ao.show();
}
