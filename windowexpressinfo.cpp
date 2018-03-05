#include "windowexpressinfo.h"
#include "ui_windowexpressinfo.h"

WindowExpressInfo::WindowExpressInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowExpressInfo)
{
    ui->setupUi(this);
}

WindowExpressInfo::~WindowExpressInfo()
{
    delete ui;
}

WindowExpressInfo::setUpData(QString en){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接ODBC的Driver
    QString dsn = QString::fromLocal8Bit("qtodbc");
    db.setHostName("127.0.0.1");//设置名称、用户名、密码
    db.setDatabaseName(dsn);
    db.setUserName("sa");
    db.setPassword("131415926");
    if(!db.open())
    {
        qDebug()<<db.lastError().text()<<endl;
        return 0;
    }
    else
    {
        qDebug()<<"database open success!"<<endl;
        QSqlQuery query(db);


        //----------------QUERY START---------------

           query.exec("select* from expresstable where expressMethod='"+en+"'");
           qDebug()<<"select* from expresstable where expressMethod='"+en+"'"<<endl;

        //----------------QUERY END-----------------

           ui->label_6->setText("");
           ui->label_7->setText("");
           ui->label_8->setText("");
           ui->label_10->setText("");
           ui->label_9->setText("");

        while(query.next()){
            ui->label_6->setText(query.value(0).toString());
            ui->label_7->setText(query.value(1).toString());
            ui->label_8->setText(query.value(2).toString());
            ui->label_10->setText(query.value(3).toString());
            ui->label_9->setText(query.value(4).toString());
        }
    }
    return 0;
}

void WindowExpressInfo::on_pushButton_clicked()
{
    this->hide();
}
