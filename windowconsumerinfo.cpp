#include "windowconsumerinfo.h"
#include "ui_windowconsumerinfo.h"

WindowConsumerInfo::WindowConsumerInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowConsumerInfo)
{
    ui->setupUi(this);
    ui->lineEdit_6->hide();
}

WindowConsumerInfo::~WindowConsumerInfo()
{
    delete ui;
}

WindowConsumerInfo::setUpData(){

    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_11->show();
    ui->label_12->show();
    ui->label_13->show();

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

        if(superPower==2) id="admin";

        //----------------QUERY START---------------

           query.exec("select* from consumertable where id='"+id+"'");
           qDebug()<<"select* from consumertable where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------



        while(query.next()){
            qDebug()<<"Search Successfully"<<endl;
            ui->lineEdit->setText(query.value(1).toString());
            ui->lineEdit_2->setText(query.value(2).toString());
            ui->lineEdit_3->setText(query.value(3).toString());
            ui->lineEdit_4->setText(query.value(4).toString());
            ui->lineEdit_5->setText(query.value(5).toString());
            ui->label_8->setText(query.value(6).toString());
            ui->label_9->setText(query.value(1).toString());
            ui->label_10->setText(query.value(2).toString());
            ui->label_11->setText(query.value(3).toString());
            ui->label_12->setText(query.value(4).toString());
            ui->label_13->setText(query.value(5).toString());
        }
    }
    return 0;
}


void WindowConsumerInfo::on_lineEdit_editingFinished()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接ODBC的Driver
    QString dsn = QString::fromLocal8Bit("qtodbc");
    db.setHostName("127.0.0.1");//设置名称、用户名、密码
    db.setDatabaseName(dsn);
    db.setUserName("sa");
    db.setPassword("131415926");
    if(!db.open())
    {
        qDebug()<<db.lastError().text()<<endl;
        return;
    }
    else
    {
        qDebug()<<"database open success!"<<endl;
        QSqlQuery query(db);

        QString info;
        info=ui->lineEdit->text();

        //----------------QUERY START---------------

           query.exec("update consumertable set consumerName='"+info+"'  where id='"+id+"'");
           qDebug()<<"update consumertable set consumerName='"+info+"'  where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}


void WindowConsumerInfo::on_lineEdit_2_editingFinished()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接ODBC的Driver
    QString dsn = QString::fromLocal8Bit("qtodbc");
    db.setHostName("127.0.0.1");//设置名称、用户名、密码
    db.setDatabaseName(dsn);
    db.setUserName("sa");
    db.setPassword("131415926");
    if(!db.open())
    {
        qDebug()<<db.lastError().text()<<endl;
        return;
    }
    else
    {
        qDebug()<<"database open success!"<<endl;
        QSqlQuery query(db);

        QString info;
        info=ui->lineEdit_2->text();

        //----------------QUERY START---------------

           query.exec("update consumertable set address='"+info+"'  where id='"+id+"'");
           qDebug()<<"update consumertable set address='"+info+"'  where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowConsumerInfo::on_lineEdit_3_editingFinished()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接ODBC的Driver
    QString dsn = QString::fromLocal8Bit("qtodbc");
    db.setHostName("127.0.0.1");//设置名称、用户名、密码
    db.setDatabaseName(dsn);
    db.setUserName("sa");
    db.setPassword("131415926");
    if(!db.open())
    {
        qDebug()<<db.lastError().text()<<endl;
        return;
    }
    else
    {
        qDebug()<<"database open success!"<<endl;
        QSqlQuery query(db);

        QString info;
        info=ui->lineEdit_3->text();

        //----------------QUERY START---------------

           query.exec("update consumertable set telphone='"+info+"'  where id='"+id+"'");
           qDebug()<<"update consumertable set telphone='"+info+"'  where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowConsumerInfo::on_lineEdit_4_editingFinished()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接ODBC的Driver
    QString dsn = QString::fromLocal8Bit("qtodbc");
    db.setHostName("127.0.0.1");//设置名称、用户名、密码
    db.setDatabaseName(dsn);
    db.setUserName("sa");
    db.setPassword("131415926");
    if(!db.open())
    {
        qDebug()<<db.lastError().text()<<endl;
        return;
    }
    else
    {
        qDebug()<<"database open success!"<<endl;
        QSqlQuery query(db);

        QString info;
        info=ui->lineEdit_4->text();

        //----------------QUERY START---------------

           query.exec("update consumertable set present='"+info+"'  where id='"+id+"'");
           qDebug()<<"update consumertable set present='"+info+"'  where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowConsumerInfo::on_lineEdit_5_editingFinished()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接ODBC的Driver
    QString dsn = QString::fromLocal8Bit("qtodbc");
    db.setHostName("127.0.0.1");//设置名称、用户名、密码
    db.setDatabaseName(dsn);
    db.setUserName("sa");
    db.setPassword("131415926");
    if(!db.open())
    {
        qDebug()<<db.lastError().text()<<endl;
        return;
    }
    else
    {
        qDebug()<<"database open success!"<<endl;
        QSqlQuery query(db);

        QString info;
        info=ui->lineEdit_5->text();

        //----------------QUERY START---------------

           query.exec("update consumertable set paymentMethod='"+info+"'  where id='"+id+"'");
           qDebug()<<"update consumertable set paymentMethod='"+info+"'  where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowConsumerInfo::on_toolButton_clicked()
{
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
}

void WindowConsumerInfo::on_lineEdit_6_editingFinished()
{

}
