#include "windowstoreinfo.h"
#include "ui_windowstoreinfo.h"

QString tempName;

WindowStoreInfo::WindowStoreInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowStoreInfo)
{
    ui->setupUi(this);
    ui->toolButton->hide();
    ui->groupBox->hide();
}

WindowStoreInfo::~WindowStoreInfo()
{
    delete ui;
}

WindowStoreInfo::setUpData(QString gn){
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

           query.exec("select* from storetable where id LIKE '"+id+"' and goodsName='"+gn+"'");
           qDebug()<<"select* from storetable where id LIKE '"+id+"' and goodsName='"+gn+"'"<<endl;

        //----------------QUERY END-----------------

           ui->label_6->setText("");
           ui->label_7->setText("");
           ui->label_8->setText("");
           ui->label_9->setText("");
           ui->lineEdit->setText("");
           ui->lineEdit_2->setText("");
           ui->lineEdit_3->setText("");
           ui->lineEdit_4->setText("");

        while(query.next()){
            ui->label_6->setText(query.value(0).toString());
            ui->label_7->setText(query.value(1).toString());
            ui->label_8->setText(query.value(2).toString());
            ui->label_9->setText(query.value(3).toString());
            ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE '"+id+"' and goodsName='"+gn+"'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and goodsName='"+gn+"'"<<endl;

        //----------------QUERY END-----------------

           ui->label_15->setText("");
           ui->label_16->setText("");
           ui->label_17->setText("");
           ui->label_18->setText("");
           ui->label_19->setText("");
           ui->lineEdit_5->setText("");
           ui->lineEdit_6->setText("");
           ui->lineEdit_7->setText("");
           ui->lineEdit_8->setText("");
           ui->lineEdit_9->setText("");

        while(query.next()){
            ui->label_15->setText(query.value(1).toString());
            ui->label_16->setText(query.value(2).toString());
            ui->label_17->setText(query.value(3).toString());
            ui->label_18->setText(query.value(4).toString());
            ui->label_19->setText(query.value(5).toString());
            ui->lineEdit_5->setText(query.value(1).toString());
            ui->lineEdit_6->setText(query.value(2).toString());
            ui->lineEdit_7->setText(query.value(3).toString());
            ui->lineEdit_8->setText(query.value(4).toString());
            ui->lineEdit_9->setText(query.value(5).toString());
        }
    }
    if(superPower==2){
        ui->toolButton->show();
    }
    else{
        ui->toolButton->hide();
        ui->groupBox->hide();
    }
    return 0;
}

void WindowStoreInfo::on_toolButton_clicked()
{
    ui->groupBox->show();
    ui->lineEdit->hide();
}

void WindowStoreInfo::on_lineEdit_editingFinished()
{

}

void WindowStoreInfo::on_lineEdit_2_editingFinished()
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

           query.exec("update storetable set amount='"+ui->lineEdit_2->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update storetable set amount='"+ui->lineEdit_2->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_3_editingFinished()
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

           query.exec("update storetable set position='"+ui->lineEdit_3->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update storetable set position='"+ui->lineEdit_3->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_4_editingFinished()
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

           query.exec("update storetable set environment='"+ui->lineEdit_4->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update storetable set environment='"+ui->lineEdit_4->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_5_editingFinished()
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

           query.exec("update goodstable set weight='"+ui->lineEdit_5->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set weight='"+ui->lineEdit_5->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_6_editingFinished()
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

           query.exec("update goodstable set cover='"+ui->lineEdit_6->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set cover='"+ui->lineEdit_6->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_7_editingFinished()
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

           query.exec("update goodstable set changePolicy='"+ui->lineEdit_7->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set changePolicy='"+ui->lineEdit_7->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_8_editingFinished()
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

           query.exec("update goodstable set creater='"+ui->lineEdit_8->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set creater='"+ui->lineEdit_8->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}

void WindowStoreInfo::on_lineEdit_9_editingFinished()
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

           query.exec("update goodstable set date='"+ui->lineEdit_9->text()+"' where goodsName='"+tempName+"'");
           qDebug()<<"update goodstable set date='"+ui->lineEdit_9->text()+"' where goodsName='"+tempName+"'"<<endl;

        //----------------QUERY END-----------------
    }
    return;
}
