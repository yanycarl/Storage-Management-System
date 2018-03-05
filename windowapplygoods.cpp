#include "windowapplygoods.h"
#include "ui_windowapplygoods.h"

QString oldName;

WindowApplyGoods::WindowApplyGoods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowApplyGoods)
{
    ui->setupUi(this);
}

WindowApplyGoods::~WindowApplyGoods()
{
    delete ui;
}

WindowApplyGoods::setUpData(){
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    return 0;
}

void WindowApplyGoods::on_pushButton_clicked()
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

        QString info;
        info=ui->lineEdit->text();
        QString info2;
        info2=ui->lineEdit_2->text();
        QString info3;
        info3=ui->lineEdit_3->text();
        QString info4;
        info4=ui->lineEdit_4->text();
        QString info5;
        info5=ui->lineEdit_5->text();
        QString info6;
        info6=ui->lineEdit_6->text();

        //----------------QUERY START---------------

        query.exec("insert into goodstable values('"+info+"','"+info2+"','"+info3+"','"+info4+"','"+info5+"','"+info6+"','"+id+"')");
        qDebug()<<"insert into goodstable values('"+info+"','"+info2+"','"+info3+"','"+info4+"','"+info5+"','"+info6+"','"+id+"')"<<endl;

        //----------------QUERY END-----------------

        int storeNo;
        srand(clock());
        storeNo=rand()%13;

        QString storeName;
        switch (storeNo) {
        case 0:storeName="北京";break;
        case 1:storeName="上海";break;
        case 2:storeName="深圳";break;
        case 3:storeName="广州";break;
        case 4:storeName="天津";break;
        case 5:storeName="大连";break;
        case 6:storeName="青岛";break;
        case 7:storeName="济南";break;
        case 8:storeName="武汉";break;
        case 9:storeName="南京";break;
        case 10:storeName="杭州";break;
        case 11:storeName="珠海";break;
        case 12:storeName="厦门";break;
        default:storeName="未知";
            break;
        }


        //----------------QUERY START---------------

        query.exec("insert into storetable values('"+info+"','"+ui->lineEdit_7->text()+"','"+storeName+"','"+ui->lineEdit_8->text()+"','"+id+"')");
        qDebug()<<"insert into storetable values('"+info+"','"+ui->lineEdit_7->text()+"','"+storeName+"','"+ui->lineEdit_8->text()+"','"+id+"')"<<endl;

        //----------------QUERY END-----------------
    }

    this->hide();
    return;
}

void WindowApplyGoods::on_lineEdit_editingFinished()
{

}

void WindowApplyGoods::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{

}
