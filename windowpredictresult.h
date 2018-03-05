#ifndef WINDOWPREDICTRESULT_H
#define WINDOWPREDICTRESULT_H

#include <QMainWindow>

namespace Ui {
class WindowPredictResult;
}

class WindowPredictResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowPredictResult(QWidget *parent = 0);
    ~WindowPredictResult();

private:
    Ui::WindowPredictResult *ui;
};

#endif // WINDOWPREDICTRESULT_H
