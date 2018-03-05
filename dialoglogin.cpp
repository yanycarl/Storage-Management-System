#include "dialoglogin.h"
#include "ui_dialoglogin.h"

int superPower;

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    superPower=0;
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

DialogLogin::selectFunct(int funct){
    if(funct==1){
        ui->pushButton_3->hide();
        ui->pushButton->show();
        superPower=0;
    }
    else if(funct==2){
        ui->pushButton->hide();
        ui->pushButton_3->show();
        superPower=0;
    }
    else if(funct==3){
        ui->pushButton_3->hide();
        ui->pushButton->show();
        superPower=1;
    }
    return 0;
}

void DialogLogin::on_pushButton_clicked()
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

        if(superPower==0){
           query.exec("select* from usertable where id='"+id+"' and pwd='"+pwd+"'");
           qDebug()<<"select* from usertable where id='"+id+"' and pwd='"+pwd+"'"<<endl;
        }
        else if(superPower==1){
            query.exec("select* from adminlogin where  pwd='"+pwd+"' and adminId='"+id+"'");
            qDebug()<<"select* from adminlogin where  pwd='"+pwd+"' and adminId='"+id+"'"<<endl;
        }

        //----------------QUERY END-----------------


        while(query.next()){
            qDebug()<<"LoginSuccessfully"<<endl;
            qDebug()<<query.value(0).toString()<<endl;
            qDebug()<<query.value(1).toString()<<endl;
            if(superPower==0)
                mainWindowui.show();
            else if(superPower==1){
                sp.show();
                superPower=2;
            }
            this->hide();
        }
    }
    return;
}

void DialogLogin::on_pushButton_2_clicked()
{
    this->hide();
}

void DialogLogin::on_pushButton_3_clicked()
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

           query.exec("alter trigger trigger1 on usertable for insert as insert into consumertable values('"+id+"','NULL','NULL','NULL','NULL','NULL','0')");
           qDebug()<<"create trigger trigger1 on usertable for insert as insert into consumertable values('"+id+"','NULL','NULL','NULL','NULL','NULL','0')"<<endl;
        //----------------QUERY END-----------------

        //----------------QUERY START---------------

           query.exec("insert into usertable values('"+id+"','"+pwd+"')");
           qDebug()<<"insert into usertable values('"+id+"','"+pwd+"')"<<endl;

        //----------------QUERY END-----------------


        qDebug()<<"Register Successfully"<<endl;
        ui->pushButton_3->hide();
        ui->pushButton->show();

    }
    return;
}
