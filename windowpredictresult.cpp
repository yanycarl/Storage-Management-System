#include "windowpredictresult.h"
#include "ui_windowpredictresult.h"

WindowPredictResult::WindowPredictResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowPredictResult)
{
    ui->setupUi(this);
}

WindowPredictResult::~WindowPredictResult()
{
    delete ui;
}
