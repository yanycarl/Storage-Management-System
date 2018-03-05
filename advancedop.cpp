#include "advancedop.h"
#include "ui_advancedop.h"

AdvancedOp::AdvancedOp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdvancedOp)
{
    ui->setupUi(this);
    /*
     * CREATE TRIGGER tri_del1
     *ON goodstable FOR DELETE
     *AS
     *declare @goodsN NVARCHAR(MAX)
     *select @goodsN=goodsName from deleted
     *delete from ordertable where goodsName=@goodsN
    */
    /*
     * CREATE TRIGGER tri_del2
        ON consumertable FOR DELETE
        AS
        declare @id NVarchar(MAX)
        select @id=id from deleted
        delete from ordertable where consumer=@id
        delete from goodstable where id=@id
        delete from usertable where id=@id
        delete from storetable where id=@id
     *
     * */
}

AdvancedOp::~AdvancedOp()
{
    delete ui;
}

void AdvancedOp::on_pushButton_clicked()
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


        QString pwd;

        id=ui->lineEdit->text();
        pwd=ui->lineEdit_2->text();
        //----------------QUERY START---------------

           query.exec("delete from ordertable where orderId='"+ui->lineEdit->text()+"'");
           qDebug()<<"delete from ordertable where orderId='"+ui->lineEdit->text()+"'"<<endl;
        //----------------QUERY END-----------------

    }
    QMessageBox::warning(NULL, "warning", "操作成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    return;
}

void AdvancedOp::on_pushButton_2_clicked()
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


        QString pwd;

        id=ui->lineEdit->text();
        pwd=ui->lineEdit_2->text();
        //----------------QUERY START---------------

           query.exec("delete from goodstable where goodsName='"+ui->lineEdit_2->text()+"'");
           qDebug()<<"delete from goodstable where goodsName='"+ui->lineEdit_2->text()+"'"<<endl;
        //----------------QUERY END-----------------

           //----------------QUERY START---------------

              query.exec("delete from storetable where goodsName='"+ui->lineEdit_2->text()+"'");
              qDebug()<<"delete from storetable where goodsName='"+ui->lineEdit_2->text()+"'"<<endl;
           //----------------QUERY END-----------------
    }
    QMessageBox::warning(NULL, "warning", "操作成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    return;
}

void AdvancedOp::on_pushButton_3_clicked()
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


        QString pwd;

        id=ui->lineEdit->text();
        pwd=ui->lineEdit_2->text();
        //----------------QUERY START---------------

           query.exec("delete from usertable where id='"+ui->lineEdit_3->text()+"'");
           qDebug()<<"delete from usertable where id='"+ui->lineEdit_3->text()+"'"<<endl;
        //----------------QUERY END-----------------
        //----------------QUERY START---------------

            query.exec("delete from consumertable where id='"+ui->lineEdit_3->text()+"'");
            qDebug()<<"delete from consumertable where id='"+ui->lineEdit_3->text()+"'"<<endl;
        //----------------QUERY END-----------------

    }
    exit(0);
    return;
}

void AdvancedOp::on_pushButton_4_clicked()
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


        QString pwd;

        id=ui->lineEdit->text();
        pwd=ui->lineEdit_2->text();
        //----------------QUERY START---------------

           query.exec("backup database qtdatabase to disk='backup.bak'");
           qDebug()<<"backup database qtdatabase to disk='backup.bak'"<<endl;
        //----------------QUERY END-----------------

    }
    exit(0);
    return;
}

void AdvancedOp::on_pushButton_5_clicked()
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


        QString pwd;

        id=ui->lineEdit->text();
        pwd=ui->lineEdit_2->text();
        //----------------QUERY START---------------

           query.exec("use master; restore database qtdatabase from disk='backup.bak' with replace;");
           qDebug()<<"use master; restore database qtdatabase from disk='backup.bak' with replace;"<<endl;
        //----------------QUERY END-----------------

    }
    exit(0);
    return;
}
