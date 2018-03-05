#ifndef WINDOWAPPLYORDER_H
#define WINDOWAPPLYORDER_H

#include <QMainWindow>
#include <head.h>
#include <windowexpressinfo.h>

namespace Ui {
class WindowApplyOrder;
}

class WindowApplyOrder : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowApplyOrder(QWidget *parent = 0);
    ~WindowApplyOrder();
    setUpData();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_editingFinished();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::WindowApplyOrder *ui;
    WindowExpressInfo  wei;
};

#endif // WINDOWAPPLYORDER_H
