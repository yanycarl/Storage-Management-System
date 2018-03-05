#ifndef WINDOWCONSUMERINFO_H
#define WINDOWCONSUMERINFO_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class WindowConsumerInfo;
}

class WindowConsumerInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowConsumerInfo(QWidget *parent = 0);
    ~WindowConsumerInfo();
    setUpData();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_editingFinished();

    void on_toolButton_clicked();

private:
    Ui::WindowConsumerInfo *ui;
};

#endif // WINDOWCONSUMERINFO_H
