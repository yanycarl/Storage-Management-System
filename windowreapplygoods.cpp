#include "windowreapplygoods.h"
#include "ui_windowreapplygoods.h"



WindowReApplyGoods::WindowReApplyGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowReApplyGoods)
{
    ui->setupUi(this);
}

WindowReApplyGoods::~WindowReApplyGoods()
{
    delete ui;
}


WindowReApplyGoods::setUpData(QString gn){
    tempName=gn;
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

           query.exec("select* from goodstable where id='"+id+"' and goodsName='"+gn+"'");
           qDebug()<<"select* from goodstable where id='"+id+"' and goodsName='"+gn+"'"<<endl;

        //----------------QUERY END-----------------



        while(query.next()){
            qDebug()<<"Search Successfully"<<endl;
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
            ui->lineEdit_6->setText(query.value(5).toString());
            ui->label_8->setText(query.value(0).toString());
        }
    }
    return 0;
}

void WindowReApplyGoods::on_lineEdit_2_editingFinished()
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

        //----------------QUERY START---------------

           query.exec("update goodstable set weight='"+ui->lineEdit_2->text()+"' where id='"+id+"' and goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set weight='"+ui->lineEdit_2->text()+"' where id='"+id+"' and goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowReApplyGoods::on_lineEdit_3_editingFinished()
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

        //----------------QUERY START---------------

           query.exec("update goodstable set cover='"+ui->lineEdit_3->text()+"' where id='"+id+"' and goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set cover='"+ui->lineEdit_3->text()+"' where id='"+id+"' and goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowReApplyGoods::on_lineEdit_4_editingFinished()
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

        //----------------QUERY START---------------

           query.exec("update goodstable set changePolicy='"+ui->lineEdit_4->text()+"' where id='"+id+"' and goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set changePolicy='"+ui->lineEdit_4->text()+"' where id='"+id+"' and goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowReApplyGoods::on_lineEdit_5_editingFinished()
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

        //----------------QUERY START---------------

           query.exec("update goodstable set creater='"+ui->lineEdit_5->text()+"' where id='"+id+"' and goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set creater='"+ui->lineEdit_5->text()+"' where id='"+id+"' and goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowReApplyGoods::on_lineEdit_6_editingFinished()
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

        //----------------QUERY START---------------

           query.exec("update goodstable set date='"+ui->lineEdit_6->text()+"' where id='"+id+"' and goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set date='"+ui->lineEdit_6->text()+"' where id='"+id+"' and goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowReApplyGoods::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{

}
