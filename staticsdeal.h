#ifndef STATICSDEAL_H
#define STATICSDEAL_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class StaticsDeal;
}

class StaticsDeal : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaticsDeal(QWidget *parent = 0);
    ~StaticsDeal();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::StaticsDeal *ui;
};

#endif // STATICSDEAL_H
