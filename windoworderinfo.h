#ifndef WINDOWORDERINFO_H
#define WINDOWORDERINFO_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class WindowOrderInfo;
}

class WindowOrderInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowOrderInfo(QWidget *parent = 0);
    ~WindowOrderInfo();
    setUpData(QString on);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_7_editingFinished();

    void on_lineEdit_8_editingFinished();

    void on_lineEdit_9_editingFinished();

    void on_lineEdit_10_editingFinished();

    void on_lineEdit_11_editingFinished();

private:
    Ui::WindowOrderInfo *ui;
};

#endif // WINDOWORDERINFO_H
