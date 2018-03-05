#include "adminuser.h"
#include "ui_adminuser.h"

AdminUser::AdminUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminUser)
{
    ui->setupUi(this);
}

AdminUser::~AdminUser()
{
    delete ui;
}

AdminUser::setUpData(){

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

         query.exec("select* from consumertable");
         qDebug()<<"select* from consumertable"<<endl;

        //----------------QUERY END-----------------

        ui->listWidget->clear();

        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget->addItem(query.value(1).toString());
        }
    }
    return 0;
}

void AdminUser::on_pushButton_clicked()
{
    this->hide();
}


void AdminUser::on_listWidget_doubleClicked(const QModelIndex &index)
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

         query.exec("select* from consumertable where consumerName='"+ui->listWidget->currentItem()->text()+"'");
         qDebug()<<"select* from consumertable where consumerName='"+ui->listWidget->currentItem()->text()+"'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
            ui->lineEdit_6->setText(query.value(5).toString());
            ui->lineEdit_7->setText(query.value(6).toString());
        }
    }
    return;
}

void AdminUser::on_listView_doubleClicked(const QModelIndex &index)
{

}
