#include "tickets.h"
#include "ui_tickets.h"
QString on;

Tickets::Tickets(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tickets)
{
    ui->setupUi(this);
    ui->groupBox->move(210,260);
}

Tickets::~Tickets()
{
    delete ui;
}

void Tickets::on_commandLinkButton_clicked()
{

    on=ui->lineEdit->text();
    ui->groupBox->hide();
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

           query.exec("select* "
                      "from ordertable o,consumertable c,expresstable e,storetable s "
                      "where c.id=o.consumer and e.expressMethod=o.expressMethod and c.id='"+id+"' and s.id=c.id and s.goodsName=o.goodsName and orderId='"+on+"'");
           qDebug()<<"select* "
                     "from ordertable o,consumertable c,expresstable e,storetable s "
                     "where c.id=o.consumer and e.expressMethod=o.expressMethod and c.id='"+id+"' and s.id=c.id and s.goodsName=o.goodsName and orderId='"+on+"'"<<endl;

        //----------------QUERY END-----------------



        while(query.next()){
            ui->label_20->setText(query.value(0).toString());
            ui->label_21->setText(query.value(3).toString());
            ui->label_22->setText(query.value(7).toString());
            ui->label_23->setText(query.value(2).toString());
            ui->label_24->setText(query.value(17).toString());
            ui->label_25->setText(query.value(19).toString());
            ui->label_26->setText(query.value(13).toString());
            ui->label_27->setText(query.value(9).toString());
            ui->label_28->setText(query.value(4).toString());
            ui->label_29->setText(query.value(22).toString());
            ui->label_30->setText(query.value(6).toString());
            ui->label_31->setText(query.value(18).toString());
            ui->label_32->setText(query.value(12).toString());
            ui->label_33->setText(query.value(10).toString());
            ui->label_34->setText(query.value(16).toString());
            ui->label_35->setText(query.value(5).toString());
        }
    }
    return;
}

void Tickets::on_pushButton_clicked()
{
    ui->groupBox->show();
    ui->pushButton->hide();
    this->hide();
}

void Tickets::on_pushButton_2_clicked()
{
    if (QApplication::activeWindow()) {
            QPixmap currentScreenPixmap = QPixmap::grabWindow( QApplication::activeWindow()->winId(), 0, 50, QApplication::activeWindow()->width()-150, QApplication::activeWindow()->height()-100);
            //currentScreenPixmap = QPixmap::grabWindow( QApplication::activeWindow()->winId());
            currentScreenPixmap.save("C:\\Users\\PC\\Desktop\\Reception Ticket_"+on+".jpg","jpg");

    }
    QMessageBox::warning(NULL, "warning", "截图成功！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}
