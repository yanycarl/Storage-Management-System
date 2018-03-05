#ifndef STATICSUI_H
#define STATICSUI_H

#include <QMainWindow>
#include <head.h>
#include <staticsdeal.h>
#include <staticsconsumer.h>

namespace Ui {
class StaticsUI;
}

class StaticsUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaticsUI(QWidget *parent = 0);
    ~StaticsUI();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

private:
    Ui::StaticsUI *ui;
    StaticsDeal sd;
    StaticsConsumer sc;
};

#endif // STATICSUI_H
