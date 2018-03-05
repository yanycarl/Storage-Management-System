#include "staticsdeal.h"
#include "ui_staticsdeal.h"

QTableWidget *table;

StaticsDeal::StaticsDeal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaticsDeal)
{
    ui->setupUi(this);
}

StaticsDeal::~StaticsDeal()
{
    delete ui;
}



void StaticsDeal::on_radioButton_clicked()
{
    int row=0;
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

           query.exec("select orderId,c.consumerName,e.fee,amount "
                      "from ordertable o,consumertable c,expresstable e "
                      "where o.consumer=c.id and o.expressMethod=e.expressMethod and id='"+id+"' "
                      "order by e.fee DESC");
           qDebug()<<"select orderId,c.consumerName,e.fee,amount "
                     "from ordertable o,consumertable c,expresstable e "
                     "where o.consumer=c.id and o.expressMethod=e.expressMethod and id='"+id+"' "
                     "order by e.fee DESC"<<endl;

        //----------------QUERY END-----------------

        if(table==0){
            table = new QTableWidget(10,4,ui->centralwidget);
            table->move(420,130);
            table->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
            table->setMinimumSize(550,380);
        }
        else{
            table->clear();
        }

        QStringList headerLabels;
        headerLabels << "订单号" << "客户名"<< "交易额"<< "交易量";
        table->setHorizontalHeaderLabels(headerLabels);
        table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

        while(query.next()){
            QTableWidgetItem *item0, *item1, *item2, *item3;
            QString content;
            item0 = new QTableWidgetItem;
            item1 = new QTableWidgetItem;
            item2 = new QTableWidgetItem;
            item3 = new QTableWidgetItem;
            content = query.value(0).toString();
            item0->setText(content);
            content = query.value(1).toString();
            item1->setText(content);
            content = query.value(2).toString();
            item2->setText(content);
            content = query.value(3).toString();
            item3->setText(content);
            table->setItem(row, 0, item0);
            table->setItem(row, 1, item1);
            table->setItem(row, 2, item2);
            table->setItem(row, 3, item3);
            row++;
            table->setRowCount(row+10);
        }
        table->show();
    }
}

void StaticsDeal::on_radioButton_2_clicked()
{
    int row=0;
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

           query.exec("select orderId,c.consumerName,e.fee,amount "
                      "from ordertable o,consumertable c,expresstable e "
                      "where o.consumer=c.id and o.expressMethod=e.expressMethod and id='"+id+"' "
                      "order by amount DESC");
           qDebug()<<"select orderId,c.consumerName,e.fee,amount "
                     "from ordertable o,consumertable c,expresstable e "
                     "where o.consumer=c.id and o.expressMethod=e.expressMethod and id='"+id+"' "
                     "order by amount DESC"<<endl;

        //----------------QUERY END-----------------

        if(table==0){
            table = new QTableWidget(10,4,ui->centralwidget);
            table->move(420,130);
            table->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
            table->setMinimumSize(550,380);
        }
        else{
            table->clear();
        }

        QStringList headerLabels;
        headerLabels << "订单号" << "客户名"<< "交易额"<< "交易量";
        table->setHorizontalHeaderLabels(headerLabels);
        table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

        while(query.next()){
            QTableWidgetItem *item0, *item1, *item2, *item3;
            QString content;
            item0 = new QTableWidgetItem;
            item1 = new QTableWidgetItem;
            item2 = new QTableWidgetItem;
            item3 = new QTableWidgetItem;
            content = query.value(0).toString();
            item0->setText(content);
            content = query.value(1).toString();
            item1->setText(content);
            content = query.value(2).toString();
            item2->setText(content);
            content = query.value(3).toString();
            item3->setText(content);
            table->setItem(row, 0, item0);
            table->setItem(row, 1, item1);
            table->setItem(row, 2, item2);
            table->setItem(row, 3, item3);
            row++;
            table->setRowCount(row+10);
        }
        table->show();
    }
}
