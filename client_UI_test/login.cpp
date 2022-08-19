#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());   //去窗口边框

    //setAttribute(Qt::WA_TranslucentBackground); //把窗口背景设置为透明;
}

login::~login()
{
    delete ui;
}

void login::on_minimizeButton_clicked()
{
    showMinimized();
}

void login::on_closeButton_clicked()
{
    close();
}

void login::on_loginButton_clicked()
{
    this->hide();
    menu.show();
}
