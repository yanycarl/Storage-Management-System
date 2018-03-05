#ifndef WINDOWEXPRESSINFO_H
#define WINDOWEXPRESSINFO_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class WindowExpressInfo;
}

class WindowExpressInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowExpressInfo(QWidget *parent = 0);
    ~WindowExpressInfo();

    setUpData(QString en);
private slots:
    void on_pushButton_clicked();

private:
    Ui::WindowExpressInfo *ui;
};

#endif // WINDOWEXPRESSINFO_H
