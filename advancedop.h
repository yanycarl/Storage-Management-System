#ifndef ADVANCEDOP_H
#define ADVANCEDOP_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class AdvancedOp;
}

class AdvancedOp : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdvancedOp(QWidget *parent = 0);
    ~AdvancedOp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AdvancedOp *ui;
};

#endif // ADVANCEDOP_H
