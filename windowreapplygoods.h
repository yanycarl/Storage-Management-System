#ifndef WINDOWREAPPLYGOODS_H
#define WINDOWREAPPLYGOODS_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class WindowReApplyGoods;
}

class WindowReApplyGoods : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowReApplyGoods(QWidget *parent = 0);
    ~WindowReApplyGoods();
    setUpData(QString gn);

private slots:
    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_6_editingFinished();

private:
    Ui::WindowReApplyGoods *ui;
};

#endif // WINDOWREAPPLYGOODS_H
