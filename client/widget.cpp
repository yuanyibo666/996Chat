//开始页面

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //di = new dialoge("ID","name");  //随便填的

    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //把窗口背景设置为透明
    setAttribute(Qt::WA_TranslucentBackground);
    //setWindowFlags(Qt::FramelessWindowHint);    //隐藏标题栏（无边框）
    setAttribute(Qt::WA_StyledBackground);      //启用样式背景绘制
    //setAttribute(Qt::WA_TranslucentBackground); //背景透明
    setAttribute(Qt::WA_Hover);
  /*  mLocation = this->geometry();
    mIsMax = false;
    mDrag = false;
    mZoom = false;*/

    socket = new QTcpSocket(this);

    fr = new Frilist(socket);
    r = new regist(socket);

    connect(fr,Frilist::back,this,Widget::back_from_frilist);
    connect(r,regist::back_to_widget,this,Widget::back_from_regist);


    QString IP="127.0.0.1";
    QString port="8888";
    socket->connectToHost(QHostAddress(IP),port.toShort());//链接服务器
    connect(socket,&QTcpSocket::connected,this,[=]()
    {
        QMessageBox::information(this,"链接提示","链接成功");
    });
    connect(socket,&QTcpSocket::disconnected,this,[=]()
    {
        QMessageBox::warning(this,"链接异常","网络断开");
    });//确定是否连接到服务器，最后可以删掉




    connect(socket,&QTcpSocket::readyRead,this,[=](){
        QByteArray recv = socket->readAll();
        QString temp = recv;
        QStringList msglist = temp.split("@");
        int listlenth = msglist.length();
        for(int i = 0; i < listlenth; i++)
        {
            QString s = msglist[i];
            if(s!=NULL)
            {
                int index = s.indexOf("|",0);
                int len = s.length();
                QString msgtype = s.left(index);
                QString msgcontent = s.right(len-index-1);
                qDebug()<<msgtype<<"msgtype";
                qDebug()<<msgcontent<<"msgcontent";
                if(msgtype=="login"){
                    Widget::login_feedback(msgcontent);
                }
                else if(msgtype =="logout"){

                }
                else if(msgtype =="register"){
                    r->register_feedback(msgcontent);
                }
                else if(msgtype =="friendlogin"){
                    fr->friend_login(msgcontent);
                }
                else if(msgtype =="signalmsg"){
                    fr->signalmsg(msgcontent);
                }
                else if(msgtype =="offlinemsg"){
                    fr->offlinemsg(msgcontent);
                }
                else if(msgtype =="groupmsg"){
                    fr->groupmsg(msgcontent);
                }
                else if(msgtype =="requestfriend"){
                    fr->request_friend(msgcontent);
                }
                else if(msgtype =="backfriend"){
                    fr->back_friend(msgcontent);
                }
                else if(msgtype== "addgroup"){
                    fr->request_group(msgcontent);
                }
                else if(msgtype== "grouplist"){
                    fr->refresh_grouplist(msgcontent);
                }
                else if(msgtype == "friendlist"){
                    fr->refresh_friendlist(msgcontent);
                }
                else if(msgtype == "groupmember"){
                    fr->set_grp_member(msgcontent);
                }
            }
        }
    });

    login_in = false;

}

Widget::~Widget()
{
    delete ui;
}
/*bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->widgetTitle)
        {
            if(e->type() == QEvent::MouseButtonDblClick)
            {
                on_btnMax_clicked();
                return true;
            }
        }
        else if (obj == ui->labelZoom)
        {
            //实现拖动右下角缩放窗口
            if(e->type() == QEvent::MouseButtonPress)
            {
                QMouseEvent *event = (QMouseEvent *)e;
                if (event->buttons() & Qt::LeftButton)
                {
                    if(mIsMax)
                    {
                        //已最大化，就不让再拖动
                        return true;
                    }
                    mZoom = true;
                    mZoomLocation = geometry();
                    mZoomPos = event->globalPos();
                    return true;
                }
            }
            else if(e->type() == QEvent::MouseMove)
            {
                QMouseEvent *event = (QMouseEvent *)e;
                if (mZoom && (event->buttons() & Qt::LeftButton))
                {
                    int dx = event->globalPos().x() - mZoomPos.x();
                    int dy = event->globalPos().y() - mZoomPos.y();
                    QRect rc = mZoomLocation;
                    rc.setRight(rc.right() + dx);
                    rc.setBottom(rc.bottom() + dy);
                    setGeometry(rc);
                    update();
                    return true;
                }
            }
            else if(e->type() == QEvent::MouseButtonRelease)
            {
                mZoom = false;
                return true;
            }
        }
        return QObject::eventFilter(obj, e);
}
*/
void Widget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        mouse_press = true;
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this ->frameGeometry().topLeft();
    }
    else if(e->button() == Qt::RightButton)
    {
        //如果是右键
        this->close();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(mouse_press)
    {
        move(e->globalPos() - p);
    }
}

void Widget::mouseReleaseEvent()
{
    mouse_press = false;
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}

void Widget::on_changeButton_clicked()
{
    ID.clear();
    ui->IDlineEdit->clear();
    ui->PswlineEdit->clear();
    QMessageBox::information(this,"提示","请重新输入账号和密码！");
}

void Widget::on_loginButton_clicked()
{
    ID = ui->IDlineEdit->text();
    Password = ui->PswlineEdit->text();
    QString msg = "login|"+ID+"|"+Password;
    socket->write(msg.toLocal8Bit());
    fr->my_ID=ID;
    if(ID == "111" || ID == "222") //判断用户是否存在
    {
        if((ID == "111" && Password == "123")||(ID == "222" && Password == "456")) //判断密码是否正确
        {
            if(login_in == false) //判断是否已经登录
            {
                login_in = true; //标识为已登录

                qDebug("%s",qPrintable(ID));
                qDebug("%s",qPrintable(Password));

                this->hide();

                //好友信息和群聊信息载入
//                fr->addFriend(10001,"tdl","01","私聊好友");
//                fr->addGroup(11111,"itKim","02","群聊空间");
                fr->add_friend("111","tdl");
                fr->add_group("222","itKim");

                //打开好友列表页
                fr->show();
            }
            else
            {
                QMessageBox::critical(this,"提示","该用户已登录！");
                //删除lineEdit中内容
                ui->PswlineEdit->clear();
                ui->IDlineEdit->clear();
            }
        }
        else
        {
            QMessageBox::warning(this,"警告","用户名或密码错误！");
            ui->PswlineEdit->clear();
        }
    }
    else
    {
        QMessageBox::critical(this,"提示","用户不存在！");
        ui->PswlineEdit->clear();
        ui->IDlineEdit->clear();
    }
}

void Widget::login_feedback(QString msg){
    if(msg=="iderror")
    {
        QMessageBox::critical(this,"提示","ID不存在，请重试");
    }
    else if(msg=="pswerror")
    {
        QMessageBox::critical(this,"提示","密码错误，请重试");
    }
    else{
        QStringList list = msg.split("|");

        //list[0]=="success";
        fr->my_username= list[1];

        this->hide();
        fr->show();
    }
}

void Widget::on_hideButton_clicked()
{
    this->hide();
}

void Widget::on_closeButton_clicked()
{
    this->close();
}

void Widget::on_registButton_clicked()
{
    r->show();
}

void Widget::back_from_frilist()
{
    fr->close();
    this->show();
}

void Widget::back_from_regist()
{
    r->close();
    this->show();
}

