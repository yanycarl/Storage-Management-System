#ifndef WINDOWAPPLYGOODS_H
#define WINDOWAPPLYGOODS_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class WindowApplyGoods;
}

class WindowApplyGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowApplyGoods(QWidget *parent = 0);
    ~WindowApplyGoods();
    setUpData();

private slots:
    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::WindowApplyGoods *ui;

};

#endif // WINDOWAPPLYGOODS_H
