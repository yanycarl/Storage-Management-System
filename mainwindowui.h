#ifndef MAINWINDOWUI_H
#define MAINWINDOWUI_H

#include <QMainWindow>
#include <head.h>
#include <windowconsumerinfo.h>
#include <windowapplygoods.h>
#include <windowchangegoods.h>
#include <windowstore.h>
#include <windowapplyorder.h>
#include <windowchangeorder.h>
#include <staticsui.h>
#include <tickets.h>

namespace Ui {
class MainWindowUI;
}

class MainWindowUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUI(QWidget *parent = 0);
    ~MainWindowUI();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_8_clicked();

private:
    Ui::MainWindowUI *ui;
    WindowConsumerInfo wci;
    WindowApplyGoods wag;
    WindowChangeGoods wcg;
    WindowStore ws;
    WindowApplyOrder wao;
    WindowChangeOrder wco;
    StaticsUI sui;
    Tickets t;
};

#endif // MAINWINDOWUI_H
