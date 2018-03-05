#ifndef WINDOWSTOREINFO_H
#define WINDOWSTOREINFO_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class WindowStoreInfo;
}

class WindowStoreInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowStoreInfo(QWidget *parent = 0);
    ~WindowStoreInfo();
    setUpData(QString gn);

private slots:
    void on_toolButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_7_editingFinished();

    void on_lineEdit_8_editingFinished();

    void on_lineEdit_9_editingFinished();

private:
    Ui::WindowStoreInfo *ui;
};

#endif // WINDOWSTOREINFO_H
