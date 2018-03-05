#ifndef WINDOWSTORE_H
#define WINDOWSTORE_H

#include <QMainWindow>
#include <head.h>
#include <windowstoreinfo.h>

namespace Ui {
class WindowStore;
}

class WindowStore : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowStore(QWidget *parent = 0);
    ~WindowStore();
    setUpData();
private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_commandLinkButton_clicked();

    void on_listWidget_2_doubleClicked(const QModelIndex &index);

private:
    Ui::WindowStore *ui;
    WindowStoreInfo wsi;
};

#endif // WINDOWSTORE_H
