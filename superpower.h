#ifndef SUPERPOWER_H
#define SUPERPOWER_H

#include <QMainWindow>
#include <head.h>
#include <windowconsumerinfo.h>
#include <windowchangeorder.h>
#include <windowstore.h>
#include <adminuser.h>
#include <advancedop.h>

namespace Ui {
class SuperPower;
}

class SuperPower : public QMainWindow
{
    Q_OBJECT

public:
    explicit SuperPower(QWidget *parent = 0);
    ~SuperPower();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_5_clicked();

private:
    Ui::SuperPower *ui;
    WindowConsumerInfo wci;
    WindowChangeOrder wco;
    WindowStore ws;
    AdminUser au;
    AdvancedOp ao;
};

#endif // SUPERPOWER_H
