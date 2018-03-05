#include "staticsconsumer.h"
#include "ui_staticsconsumer.h"

int** countList;
int counter;
int all;
int all2;

QVector<QWidget*> widgetvec;

StaticsConsumer::StaticsConsumer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StaticsConsumer)
{
    ui->setupUi(this);
    counter=0;
    countList=(int**)malloc(sizeof(int*)*1024);
    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
}

StaticsConsumer::~StaticsConsumer()
{
    delete ui;
}

StaticsConsumer::selectFunct(int funct)
{
    if(funct==1){
        ui->groupBox->show();
        ui->groupBox_2->hide();
    }
    else if(funct==2){
        ui->groupBox_2->show();
        ui->groupBox->hide();
    }
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();
    return 0;
}

void StaticsConsumer::on_radioButton_clicked()
{

    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();
    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select destination from ordertable where consumer='"+id+"'");
           qDebug()<<"select destination from ordertable where consumer='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}

void StaticsConsumer::on_radioButton_2_clicked()//商品喜好
{
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();

    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select goodsName from ordertable where consumer='"+id+"'");
           qDebug()<<"select goodsName from ordertable where consumer='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}

void StaticsConsumer::on_radioButton_3_clicked()
{
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();

    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select expressMethod from ordertable where consumer='"+id+"'");
           qDebug()<<"select expressMethod from ordertable where consumer='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}

void StaticsConsumer::on_radioButton_8_clicked()
{
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();

    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select environment from storetable where id='"+id+"'");
           qDebug()<<"select environment  from storetable where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}

void StaticsConsumer::on_radioButton_7_clicked()
{
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();

    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select date from goodstable where id='"+id+"'");
           qDebug()<<"select date  from goodstable where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}

void StaticsConsumer::on_radioButton_9_clicked()
{
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();

    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select creater from goodstable where id='"+id+"'");
           qDebug()<<"select creater from goodstable where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}

void StaticsConsumer::on_radioButton_10_clicked()
{
    for(int i = 0; i < widgetvec.count(); i++)
    {
        delete widgetvec[i];
    }
    widgetvec.clear();

    for(int i=0;i<1024;i++){
        countList[i]=(int*)malloc(sizeof(int)*2);
        countList[i][0]=0;
        countList[i][1]=0;
    }
    all=0;
    all2=0;
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

           query.exec("select changePolicy from goodstable where id='"+id+"'");
           qDebug()<<"select changePolicy  from goodstable where id='"+id+"'"<<endl;

        //----------------QUERY END-----------------
        QVector <QString> vec1;
        QVector <QString> vec2;

        while(query.next()){
            vec1.push_back(query.value(0).toString());
        }
        while(!vec1.isEmpty()){
            all++;
            qDebug()<<vec1.first()<<endl;
            counter=0;
            for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++){
                qDebug()<<"V2:"<<iter->toLower()<<endl;
                if(iter->toLower()==vec1.first()){
                    goto label1;
                }
                counter++;
            }
            vec2.push_back(vec1.first());
            all2++;
            countList[counter][0]=1;
            goto label2;
label1:
            countList[counter][0]++;
label2:
            vec1.pop_front();
        }
        for(QVector<QString>::iterator iter=vec2.begin();iter!=vec2.end();iter++)
            qDebug()<<"V2_END:"<<iter->toLower()<<endl;
        int max=0;
        int pos;

        for(int i=0;i<all2;i++)
         {
            qDebug()<<"Times:"<<i<<endl;
            max=0;
            for(int j=0;j<all2;j++)
            {
                if(countList[j][1]==1){
                    qDebug()<<"Jump:"<<j<<endl;
                    goto label3;
                }
                qDebug()<<"Continue List:"<<j<<endl;
                if(countList[j][0]>max){
                    max=countList[j][0];
                    pos=j;
                    qDebug()<<"Current MAX:"<<pos<<endl;
                }
    label3:{}
            }
            countList[pos][1]=1;
            qDebug()<<"POS:"<<pos<<endl;
            QProgressBar *bar;
            bar=new QProgressBar(ui->widget);
            bar->resize(521,20);
            bar->move(50,50+i*50);
            qDebug()<<"Value:"<<max<<all<<endl;
            bar->setMaximum(all);
            bar->setValue(max);
            bar->show();
            qDebug()<<"Successful Show:"<<vec2.at(pos).toLower()<<endl;
            QLabel *lab;
            lab=new QLabel(ui->widget);
            lab->move(50,50+i*50);
            lab->setText(vec2.at(pos).toLower());
            lab->show();
            widgetvec<<bar;
            widgetvec<<lab;
         }
    }
    return;
}
