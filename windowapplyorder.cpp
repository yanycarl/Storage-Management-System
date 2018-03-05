#include "windowapplyorder.h"
#include "ui_windowapplyorder.h"
#include "windowpredictresult.h"

int remain;
int ok;

WindowApplyOrder::WindowApplyOrder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowApplyOrder)
{
    ui->setupUi(this);
    ok=0;
}

WindowApplyOrder::~WindowApplyOrder()
{
    delete ui;
}

WindowApplyOrder::setUpData(){
    ok=0;
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

           query.exec("select* from goodstable where id='"+id+"'");
           qDebug()<<"select* from goodstable where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------

        ui->comboBox->clear();
        ui->comboBox->addItem("Please Select One Goods");

        while(query.next()){
            qDebug()<<"Search Successfully"<<endl;
            ui->comboBox->addItem(query.value(0).toString());
        }


        //----------------QUERY START---------------

           query.exec("select* from expresstable");
           qDebug()<<"select* from expresstable"<<endl;

        //----------------QUERY END-----------------

        ui->comboBox_2->clear();

        while(query.next()){
            qDebug()<<"Search Successfully"<<endl;
            ui->comboBox_2->addItem(query.value(0).toString());
        }
    }
    ok=1;
    return 0;
}

void WindowApplyOrder::on_pushButton_clicked()
{
    long orderNo;
    srand(clock());
    orderNo=rand()%100000000;
    QString orderNoString;
    orderNoString=QString::number(orderNo);
    long orderNo2;
    srand(clock());
    orderNo2=rand()%100000000;
    QString orderNoString2;
    orderNoString2=QString::number(orderNo2);
    QString orderInfo="";
    orderInfo=orderInfo+ui->lineEdit->text();
    orderInfo=orderInfo+ui->lineEdit_2->text();
    orderInfo=orderInfo+ui->lineEdit_3->text();

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

        query.exec("select* from storetable where id='"+id+"' and goodsName='"+ui->comboBox->currentText()+"'");
        qDebug()<<"select* from storetable where id='"+id+"' and goodsName='"+ui->comboBox->currentText()+"'"<<endl;

        //----------------QUERY END-----------------

        query.next();

           remain=query.value(1).toInt();

           if(remain<ui->spinBox->value()||ui->spinBox->value()==0){
               QMessageBox::warning(NULL, "warning", "存货量不足或选择商品数为零！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
               return;
           }
           else{

               remain=remain-ui->spinBox->value();

            //----------------QUERY START---------------

               query.exec("insert into ordertable values('"+orderNoString+"','"+id+"','"+ui->comboBox_2->currentText()+"','"+ui->comboBox->currentText()+"','"+orderInfo+"','"+"2017.06.05"+"','"+orderNoString2+"','"+QString::number(ui->spinBox->value())+"')");
               qDebug()<<"insert into ordertable values('"+orderNoString+"','"+id+"','"+ui->comboBox_2->currentText()+"','"+ui->comboBox->currentText()+"','"+orderInfo+"','"+"2017.06.05"+"','"+orderNoString2+",'"+QString::number(ui->spinBox->value())+"')"<<endl;

            //----------------QUERY END-----------------

            //----------------QUERY START---------------

                  query.exec("update storetable set amount='"+QString::number(remain)+"' where id='"+id+"' and goodsName='"+ui->comboBox->currentText()+"'");
                  qDebug()<<"update storetable set amount='"+QString::number(remain)+"' where id='"+id+"' and goodsName='"+ui->comboBox->currentText()+"'"<<endl;

            //----------------QUERY END-----------------
           }

    }
    this->hide();
    return;

}

void WindowApplyOrder::on_spinBox_editingFinished()
{
    if(remain<ui->spinBox->value()){
        QMessageBox::warning(NULL, "warning", "存货量不足！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        ui->spinBox->setValue(remain);
    }
}

void WindowApplyOrder::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ok==1){

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

            query.exec("select* from storetable where id='"+id+"' and goodsName='"+ui->comboBox->currentText()+"'");
            qDebug()<<"select* from storetable where id='"+id+"' and goodsName='"+ui->comboBox->currentText()+"'"<<endl;

        //----------------QUERY END-----------------

           query.next();
           remain=query.value(1).toInt();
           QString temp=QString::number(remain);
           qDebug()<<"Current Remain:"+temp<<endl;

        }

        if(arg1=="Please Select One Goods"){
            QMessageBox::warning(NULL, "warning", "请选择一项货物！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            ui->comboBox->setCurrentIndex(1);
        }
    }
}

void WindowApplyOrder::on_pushButton_2_clicked()
{
    wei.show();
    wei.setUpData(ui->comboBox_2->currentText());
}

void WindowApplyOrder::on_comboBox_activated(const QString &arg1)
{

}
