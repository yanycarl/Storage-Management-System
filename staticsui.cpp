#include "staticsui.h"
#include "ui_staticsui.h"

StaticsUI::StaticsUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaticsUI)
{
    ui->setupUi(this);
}

StaticsUI::~StaticsUI()
{
    delete ui;
}

void StaticsUI::on_commandLinkButton_clicked()
{
    sd.show();
}

void StaticsUI::on_commandLinkButton_2_clicked()
{
    sc.show();
    sc.selectFunct(1);
}

void StaticsUI::on_commandLinkButton_3_clicked()
{
    sc.show();
    sc.selectFunct(2);
}
