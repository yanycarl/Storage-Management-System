#ifndef WINDOWCHANGEGOODS_H
#define WINDOWCHANGEGOODS_H

#include <QMainWindow>
#include <head.h>
#include <windowreapplygoods.h>

namespace Ui {
class WindowChangeGoods;
}

class WindowChangeGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowChangeGoods(QWidget *parent = 0);
    ~WindowChangeGoods();
    setUpData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowChangeGoods *ui;
    WindowReApplyGoods wrag;
};

#endif // WINDOWCHANGEGOODS_H
