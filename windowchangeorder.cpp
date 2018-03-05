#include "windowchangeorder.h"
#include "ui_windowchangeorder.h"

WindowChangeOrder::WindowChangeOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowChangeOrder)
{
    ui->setupUi(this);
}

WindowChangeOrder::~WindowChangeOrder()
{
    delete ui;
}

WindowChangeOrder::setUpData(){
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

           query.exec("select* from ordertable where consumer='"+id+"'");
           qDebug()<<"select* from ordertable where consumer='"+id+"'"<<endl;
        }
        else if(superPower==2){
           query.exec("select* from ordertable");
           qDebug()<<"select* from ordertable"<<endl;
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

void WindowChangeOrder::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.data().toString()<<endl;
    woi.show();
    woi.setUpData(index.data().toString());
    return;
}

void WindowChangeOrder::on_commandLinkButton_clicked()
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

        if(superPower==0){

           query.exec("select o.orderId "
                      "from ordertable o,expresstable e,consumertable c "
                      "where c.id='"+id+"' and o.consumer=c.id and o.expressMethod=e.expressMethod and"
                                        "(o.goodsName LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "o.orderId LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "o.expressMethod LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "destination LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "time LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "expressId LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "amount LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "fee LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "period LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "security LIKE '%"+ui->lineEdit->text()+"%')");
           qDebug()<<"select o.orderId "
                     "from ordertable o,expresstable e,consumertable c "
                     "where c.id='"+id+"' and o.consumer=c.id and o.expressMethod=e.expressMethod and"
                                       "(o.goodsName LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "o.orderId LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "o.expressMethod LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "destination LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "time LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "expressId LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "amount LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "fee LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "period LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "security LIKE '%"+ui->lineEdit->text()+"%')"<<endl;
        }
        else if(superPower==2){

           query.exec("select o.orderId "
                      "from ordertable o,expresstable e,consumertable c "
                      "where  o.consumer=c.id and o.expressMethod=e.expressMethod and"
                                        "(o.goodsName LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "o.orderId LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "o.expressMethod LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "destination LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "time LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "expressId LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "amount LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "fee LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "period LIKE '%"+ui->lineEdit->text()+"%' or "
                                         "security LIKE '%"+ui->lineEdit->text()+"%')");
           qDebug()<<"select o.orderId "
                     "from ordertable o,expresstable e,consumertable c "
                     "where  and o.consumer=c.id and o.expressMethod=e.expressMethod and"
                                       "(o.goodsName LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "o.orderId LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "o.expressMethod LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "destination LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "time LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "expressId LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "amount LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "fee LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "period LIKE '%"+ui->lineEdit->text()+"%' or "
                                        "security LIKE '%"+ui->lineEdit->text()+"%')"<<endl;
        }

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->listWidget_2->addItem(query.value(0).toString());
        }

    }
    return;
}

void WindowChangeOrder::on_listWidget_2_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.data().toString()<<endl;
    woi.show();
    woi.setUpData(index.data().toString());
    return;
}

