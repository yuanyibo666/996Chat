//由Widget页面跳转

#include "frilist.h"
#include "ui_frilist.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTcpSocket>


Frilist::Frilist(QTcpSocket *s,QWidget *parent,Qt::WindowFlags f) :
    QWidget(parent,f),
    ui(new Ui::Frilist)
{
    ui->setupUi(this);

    socket = s;

    friendBox = ui->page;
    groupBox = ui->page_2;

    layout_fri = new QVBoxLayout(friendBox);
    layout_group = new QVBoxLayout(groupBox);


    test();


//    this->setLayFri();
//    this->setLayGro();

//    friButton = new QToolButton;
//    groupButton = new QToolButton;

//    dia1 = new dialoge("ID","name");
//    dia1 = new dialoge("ID","name");

//    dialist << dia1 << dia2;

//    //去窗口边框
//    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
//    //把窗口背景设置为透明
//    setAttribute(Qt::WA_TranslucentBackground);

//    connect(friButton,&QToolButton::clicked,this,&Frilist::on_friButton_clicked);
//    connect(groupButton,&QToolButton::clicked,this,&Frilist::on_groupButton_clilked);

}

//void Frilist::setLayFri()
//{
//    //好友页布局
//    layout_fri = new QVBoxLayout(friendBox);
//    layout_fri->setMargin(45);
//    layout_fri->setAlignment(Qt::AlignLeft);
//}
//void Frilist::setLayGro()
//{
//    //群组页布局
//    layout_group = new QVBoxLayout(groupBox);
//    layout_fri->setMargin(45);
//    layout_fri->setAlignment(Qt::AlignLeft);
//}

//void Frilist::addFriend(int id, QString user, QString icon, QString desc)
//{
//    QString iconpath = QString(":/pic/%1.ico").arg(icon);
//    QString text = QString("%1 <%2>").arg(user).arg(desc);
//    friButton->setText(text);
//    qDebug()<<iconpath;
//    friButton->setIcon(QPixmap(iconpath));
//    friButton->setIconSize(QSize(100,30)); //设置按钮尺寸
//    friButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
//    friButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
//    friend_list.append(friButton);
//    layout_fri->addWidget(friend_list.last());
//}

//void Frilist::addGroup(int id, QString name, QString icon, QString desc)
//{
//    QString iconpath = QString(":/pic/%1.ico").arg(icon);
//    QString text = QString("%1 <%2>").arg(name).arg(desc);
//    groupButton->setText(text);
//    qDebug()<<iconpath;
//    groupButton->setIcon(QPixmap(iconpath));
//    groupButton->setIconSize(QSize(100,30)); //设置按钮尺寸
//    groupButton->setAutoRaise(true);   //当鼠标离开时，按钮恢复为弹起状态
//    groupButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); //设置按钮文字显示在图标旁边
//    group_list.append(groupButton);
//    layout_group->addWidget(group_list.last());

//}

void Frilist::add_friend(QString ID, QString name)
{
    qDebug()<<"add_friend"<<ID<<name;
    QToolButton *newfriend = new QToolButton;
    newfriend->setText(ID+name);

    friend_list.append(newfriend);
    layout_fri->addWidget(friend_list.last());

    dialoge *newdia = new dialoge(socket,ID,name);
    newdia->set_my_ID_and_name(my_ID,my_username);
    dialist.append(newdia);

    connect(newfriend,&QToolButton::clicked,newdia,[=](){
        newdia->show();
    });

    newdia->set_member(ID, name);
}

void Frilist::add_group(QString ID, QString name)
{
    qDebug()<<"add_group"<<ID<<name;
    QToolButton *newgroup = new QToolButton;
    newgroup->setText(ID+name);

    group_list.append(newgroup);
    layout_group->addWidget(group_list.last());

    dialoge *newdia = new dialoge(socket,ID,name);
    newdia->set_my_ID_and_name(my_ID,my_username);
    dialist.append(newdia);

    connect(newgroup,&QToolButton::clicked,newdia,[=](){
        newdia->show();
    });


}

void Frilist::on_friButton_clicked()
{
//    this->hide(); //改界面不隐藏便于寻找
//    连接特定的私聊聊天框
//    使用list
//    dia = new dialoge("ID","name");
    dialist[0]->show();
}

void Frilist::on_groupButton_clilked()
{
//    this->hide(); //改界面不隐藏便于寻找
    //连接特定群聊聊天框
    //使用list
//    dia = new dialoge("ID","name");
    dialist[1]->show();
}

void Frilist::friend_login(QString msg)
{
    QStringList list = msg.split("|");
    QString friend_ID = list[0];
    QString friend_username = list[1];
    //。。。。//改变好友列表的在线/离线状态函数
}

void Frilist::request_friend(QString friend_ID)
{
    QString msg = "requestfriend|" + my_ID + "|" + friend_ID;
    socket->write(msg.toLocal8Bit());
}

void Frilist::back_friend(QString msg)
{
    qDebug()<<msg<<"back_friend";
    if(msg=="already"){
        QMessageBox::information(this,"提示","已经添加该用户！");
    }
    else{
        QStringList list = msg.split("|");
        if(list[2]=="yes"){
            QString friend_ID = list[0];
            QString friend_username = list[1];
            add_friend(friend_ID, friend_username);
        }
    }
}

void Frilist::recv_a_friendrequest(QString msg){
    QStringList list = msg.split("|");
    QString friend_ID = list[0];
    QString friend_username = list[1];
    //......//弹出一个窗口问是否同意
    QString msg2 = "backfriend|" + my_ID + "|" + my_username;
//    if(agree){
//        ......//好友列表中添加
//        msg2.append("|yes");
//    }
//    else msg2.append("|no");
    socket->write(msg2.toLocal8Bit());
}

void Frilist::request_group(QString msg)
{
    if(msg=="already"){
        QMessageBox::information(this,"提示","已经添加该群！");
    }
    else{
        QStringList list = msg.split("|");
        if(list[2]=="yes"){
            QString group_ID = list[0];
            QString group_name = list[1];
            add_friend(group_ID, group_name);
        }
    }
}

void Frilist::refresh_friendlist(QString msg)
{
    QStringList list = msg.split("|");
    QString friend_ID = list[0];
    QString friend_name = list[1];
    QString friend_state = list[2];
    //.....//设置好友列表在线/离线状态
    add_friend(friend_ID, friend_name);
}

void Frilist::refresh_grouplist(QString msg)
{
    QStringList list = msg.split("|");
    QString group_ID = list[0];
    QString group_name = list[1];

    add_group(group_ID,group_name);
}

void Frilist::signalmsg(QString msg)
{
    QStringList list = msg.split("|");
    QString from_ID = list[0];
    QString to_ID = list[1];
    QString time = list[2];
    QString content = list[3];
    dialoge* d = find(from_ID);
    //d->show_msg(content);
    //找到对应的窗口以后显示文本
}

void Frilist::offlinemsg(QString msg)
{
    QStringList list = msg.split("|");
    QString from_ID = list[0];
    QString to_ID = list[1];
    QString time = list[2];
    QString content = list[3];
    dialoge* d = find(from_ID);
    //d->show_msg(content);
    //找到对应的窗口以后显示文本
}

void Frilist::groupmsg(QString msg)
{
    QStringList list = msg.split("|");
    QString from_ID = list[0];
    QString to_ID = list[1];
    QString time = list[2];
    QString content = list[3];
    dialoge* d = find(to_ID);
    //d->show_msg(content);
    //找到对应的窗口以后显示文本
}

dialoge* Frilist::find(QString ID)
{
    int lenth = dialist.length(), i;
    for(i = 0; i < lenth; i++){
        if(dialist[i]->get_ID() == ID) break;
    }
    return dialist[i];
}

void Frilist::set_grp_member(QString msg)
{
    QStringList list = msg.split("|");
    QString group_ID = list[0];
    QString user_ID = list[1];
    QString username = list[2];
    dialoge *d = find(group_ID);
    d->set_member(user_ID, username);
}

Frilist::~Frilist()
{
    delete ui;
}

void Frilist::on_cancelButton_clicked()
{
    this->close();
}

void Frilist::on_backButton_clicked()
{
    emit back();
}

void Frilist::test()
{
    add_friend("123","liyu");
}
