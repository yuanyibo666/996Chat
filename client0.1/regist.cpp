//由Widget跳转

#include "regist.h"
#include "ui_regist.h"

regist::regist(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);
    socket=s;
}

regist::~regist()
{
    delete ui;
}

void regist::on_pushButton_clicked()
{
    QString msg= "regist|"+ui->lineEdit->text()+"|"+ui->lineEdit_2->text();
    qDebug()<<msg;
    socket->write(msg.toLocal8Bit());
}

void regist::on_delete2botton_clicked()
{
    ui->lineEdit_2->clear();
}

void regist::on_delete1Botton_clicked()
{
     ui->lineEdit->clear();
}

void regist::register_feedback(QString msg)
{
    QString s = "您的ID为：" + msg + "! 请牢记，用于登录。";
    QMessageBox::information(this,"注册成功！",s);
}

//void regist::on_backButton_clicked()
//{
//    emit back_to_widget();
//}

void regist::on_backButton_clicked()
{
    emit back_to_widget();
}
