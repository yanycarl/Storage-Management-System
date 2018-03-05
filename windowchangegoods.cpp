#include "windowchangegoods.h"
#include "ui_windowchangegoods.h"

WindowChangeGoods::WindowChangeGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowChangeGoods)
{
    ui->setupUi(this);

}

WindowChangeGoods::~WindowChangeGoods()
{
    delete ui;
}

WindowChangeGoods::setUpData(){
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
           query.exec("select* from goodstable where id='"+id+"'");
           qDebug()<<"select* from goodstable where id='"+id+"'"<<endl;
        }
        else if(superPower==2){
            query.exec("select* from goodstable");
            qDebug()<<"select* from goodstable"<<endl;
         }

        //----------------QUERY END-----------------

        ui->comboBox->clear();

        while(query.next()){
            qDebug()<<"SearchSuccessfully"<<endl;
            ui->comboBox->addItem(query.value(0).toString());
        }

    }
    return 0;
}

void WindowChangeGoods::on_pushButton_clicked()
{
    wrag.show();
    Sleep(500);
    wrag.setUpData(ui->comboBox->currentText());
}
