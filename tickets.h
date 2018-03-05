#ifndef TICKETS_H
#define TICKETS_H

#include <QMainWindow>
#include <head.h>

namespace Ui {
class Tickets;
}

class Tickets : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tickets(QWidget *parent = 0);
    ~Tickets();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Tickets *ui;
};

#endif // TICKETS_H
