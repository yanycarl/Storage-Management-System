#ifndef WINDOWCHANGEORDER_H
#define WINDOWCHANGEORDER_H

#include <QMainWindow>
#include <head.h>
#include <windoworderinfo.h>

namespace Ui {
class WindowChangeOrder;
}

class WindowChangeOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowChangeOrder(QWidget *parent = 0);
    ~WindowChangeOrder();
    setUpData();

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_2_doubleClicked(const QModelIndex &index);

    void on_commandLinkButton_clicked();

private:
    Ui::WindowChangeOrder *ui;
    WindowOrderInfo woi;
};

#endif // WINDOWCHANGEORDER_H
