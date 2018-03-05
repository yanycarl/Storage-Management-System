#ifndef STATICSCONSUMER_H
#define STATICSCONSUMER_H

#include <QMainWindow>
#include <head.h>

typedef struct{
    QString str;
    int count;
}doublelist;

namespace Ui {
class StaticsConsumer;
}

class StaticsConsumer : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaticsConsumer(QWidget *parent = 0);
    ~StaticsConsumer();
    selectFunct(int funct);

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_8_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_10_clicked();

private:
    Ui::StaticsConsumer *ui;
};

#endif // STATICSCONSUMER_H
