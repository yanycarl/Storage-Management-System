#include "windoworderinfo.h"
#include "ui_windoworderinfo.h"

WindowOrderInfo::WindowOrderInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowOrderInfo)
{
    ui->setupUi(this);
    ui->lineEdit->hide();
    ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();
    ui->lineEdit_11->hide();
}

WindowOrderInfo::~WindowOrderInfo()
{
    delete ui;
}

WindowOrderInfo::setUpData(QString on){
    tempName=on;
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
           if(superPower==0){
               query.exec("select orderId,c.consumerName,goodsName,destination,time,expressId,amount,e.expressMethod,fee,period,security from ordertable o,consumertable c,expresstable e where c.id=o.consumer and e.expressMethod=o.expressMethod and c.id='"+id+"' and orderId='"+on+"'");
               qDebug()<<"select orderId,c.consumerName,goodsName,destination,time,expressId,amount,e.expressMethod,fee,period,security " <<endl<<" from ordertable o,consumertable c,expresstable e " <<endl<<" where c.id=o.consumer and e.expressMethod=o.expressMethod and  c.id='"+id+"' and orderId='"+on+"'"<<endl;
                ui->lineEdit_4->hide();
                ui->lineEdit_5->hide();
                ui->lineEdit_6->hide();
                ui->lineEdit_7->hide();
                ui->lineEdit_8->hide();
                ui->lineEdit_9->hide();
                ui->lineEdit_10->hide();
                ui->lineEdit_11->hide();

           }
            else if(superPower==2){
               query.exec("select orderId,c.consumerName,goodsName,destination,time,expressId,amount,e.expressMethod,fee,period,security from ordertable o,consumertable c,expresstable e where c.id=o.consumer and e.expressMethod=o.expressMethod  and orderId='"+on+"'");
               qDebug()<<"select orderId,c.consumerName,goodsName,destination,time,expressId,amount,e.expressMethod,fee,period,security " <<endl<<" from ordertable o,consumertable c,expresstable e " <<endl<<" where c.id=o.consumer and e.expressMethod=o.expressMethod and orderId='"+on+"'"<<endl;
               ui->lineEdit_4->show();
               ui->lineEdit_5->show();
               ui->lineEdit_6->show();
               ui->lineEdit_7->show();
               ui->lineEdit_8->show();
               ui->lineEdit_9->show();
               ui->lineEdit_10->show();
               ui->lineEdit_11->show();
           }
        //----------------QUERY END-----------------

           ui->label_10->setText("");
           ui->label_11->setText("");
           ui->label_12->setText("");
           ui->label_13->setText("");
           ui->label_14->setText("");
           ui->label_15->setText("");
           ui->label_16->setText("");
           ui->label_17->setText("");
           ui->label_18->setText("");
           ui->label_22->setText("");
           ui->label_20->setText("");

        while(query.next()){
            ui->label_10->setText(query.value(0).toString());
            ui->label_11->setText(query.value(1).toString());
            ui->label_12->setText(query.value(2).toString());
            ui->label_13->setText(query.value(3).toString());
            ui->label_14->setText(query.value(4).toString());
            ui->label_15->setText(query.value(5).toString());
            ui->label_16->setText(query.value(6).toString());
            ui->label_17->setText(query.value(7).toString());
            ui->label_18->setText(query.value(8).toString());
            ui->label_22->setText(query.value(9).toString());
            ui->label_20->setText(query.value(10).toString());
            ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
            ui->lineEdit_6->setText(query.value(5).toString());
            ui->lineEdit_7->setText(query.value(6).toString());
            ui->lineEdit_8->setText(query.value(7).toString());
            ui->lineEdit_9->setText(query.value(8).toString());
            ui->lineEdit_10->setText(query.value(9).toString());
            ui->lineEdit_11->setText(query.value(10).toString());
        }
    }
    return 0;
}

void WindowOrderInfo::on_pushButton_clicked()
{
    this->hide();
}

void WindowOrderInfo::on_lineEdit_editingFinished()
{

}

void WindowOrderInfo::on_lineEdit_4_editingFinished()
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

           query.exec("update ordertable set expressId='"+ui->lineEdit_4->text()+"' where orderId='"+tempName+"' ");
           qDebug()<<"update ordertable set expressId='"+ui->lineEdit_4->text()+"' where orderId='"+tempName+"' "<<endl;

        //----------------QUERY END-----------------

    }
    return;
}

void WindowOrderInfo::on_lineEdit_5_editingFinished()
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

           query.exec("update ordertable set amount='"+ui->lineEdit_5->text()+"' where orderId='"+tempName+"' ");
           qDebug()<<"update ordertable set amount='"+ui->lineEdit_5->text()+"' where orderId='"+tempName+"' "<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowOrderInfo::on_lineEdit_6_editingFinished()
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

           query.exec("update ordertable set expressMethod='"+ui->lineEdit_6->text()+"' where orderId='"+tempName+"' ");
           qDebug()<<"update ordertable set expressMethod='"+ui->lineEdit_6->text()+"' where orderId='"+tempName+"' "<<endl;

        //----------------QUERY END-----------------

    }
    return;
}

void WindowOrderInfo::on_lineEdit_7_editingFinished()
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

           query.exec("update ordertable set destination='"+ui->lineEdit_7->text()+"' where orderId='"+tempName+"' ");
           qDebug()<<"update ordertable set destination='"+ui->lineEdit_7->text()+"' where orderId='"+tempName+"' "<<endl;

        //----------------QUERY END-----------------


    }
    return;
}

void WindowOrderInfo::on_lineEdit_8_editingFinished()
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

           query.exec("update ordertable set time='"+ui->lineEdit_8->text()+"' where orderId='"+tempName+"' ");
           qDebug()<<"update ordertable set time='"+ui->lineEdit_8->text()+"' where orderId='"+tempName+"' "<<endl;

        //----------------QUERY END-----------------


    }
    return;
}

void WindowOrderInfo::on_lineEdit_9_editingFinished()
{

}

void WindowOrderInfo::on_lineEdit_10_editingFinished()
{

}

void WindowOrderInfo::on_lineEdit_11_editingFinished()
{

}
