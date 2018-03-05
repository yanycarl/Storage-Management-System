#ifndef ADMINUSER_H
#define ADMINUSER_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class AdminUser;
}

class AdminUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminUser(QWidget *parent = 0);
    ~AdminUser();
    setUpData();
private slots:
    void on_pushButton_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::AdminUser *ui;
};

#endif // ADMINUSER_H
