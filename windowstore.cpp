#include "windowstore.h"
#include "ui_windowstore.h"

WindowStore::WindowStore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowStore)
{
    ui->setupUi(this);
}

WindowStore::~WindowStore()
{
    delete ui;
}

WindowStore::setUpData(){
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
           query.exec("select* from goodstable where id ='"+id+"'");
           qDebug()<<"select* from goodstable where id ='"+id+"'"<<endl;
        }
        else if(superPower==2){
            query.exec("select* from goodstable");
            qDebug()<<"select* from goodstable"<<endl;
            id="%";
         }

        //----------------QUERY END-----------------

        ui->listWidget->clear();

        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget->addItem(query.value(0).toString());
        }
    }
    return 0;
}

void WindowStore::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.data().toString()<<endl;
    wsi.show();
    wsi.setUpData(index.data().toString());
    return;
}

void WindowStore::on_commandLinkButton_clicked()
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

        ui->listWidget_2->clear();

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE'"+id+"' and goodsName LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and goodsName LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE '"+id+"' and weight LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and weight LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE '"+id+"' and cover LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and cover LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE '"+id+"' and changePolicy LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and changePolicy LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE '"+id+"' and creater LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and creater LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from goodstable where id LIKE '"+id+"' and date LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from goodstable where id LIKE '"+id+"' and date LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from storetable where id LIKE '"+id+"' and amount LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from storetable where id LIKE '"+id+"' and amount LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from storetable where id LIKE '"+id+"' and position LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from storetable where id LIKE '"+id+"' and position LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

        //----------------QUERY START---------------

           query.exec("select* from storetable where id LIKE '"+id+"' and environment LIKE '%"+ui->lineEdit->text()+"%'");
           qDebug()<<"select* from storetable where id LIKE '"+id+"' and environment LIKE '%"+ui->lineEdit->text()+"%'"<<endl;

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

    }
    return;
}

void WindowStore::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.data().toString()<<endl;
    wsi.show();
    wsi.setUpData(index.data().toString());
    return;
}
