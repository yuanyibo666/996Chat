#ifndef FRILIST_H
#define FRILIST_H

#include <QWidget>
#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QList>
#include <QDebug>
#include <QPushButton>
#include <QListWidget>
#include <dialoge.h>
#include <QTcpSocket>
#include <QMessageBox>
#include <QListWidget>
#include <QSizePolicy>


namespace Ui {
class Frilist;
}

class Frilist : public QWidget
{
    Q_OBJECT

public:
    explicit Frilist(QTcpSocket *s,QWidget *parent = 0,Qt::WindowFlags f=0);
    ~Frilist();
    dialoge *dia1, *dia2;
    QList <dialoge*> dialist;
    QString my_ID;
    QString my_username;

//    void setLayFri();   //好友页布局
//    void setLayGro();   //群组页布局
//    void addFriend(int id,QString user,QString icon,QString desc);  //添加好友
//    void addGroup(int id,QString name,QString icon,QString desc);   //添加群组


    void add_friend(QString ID, QString name);
    void add_group(QString ID, QString name);
    void friend_login(QString msg);
    void request_friend(QString friend_ID);
    void back_friend(QString msg);
    void recv_a_friendrequest(QString msg);
    void request_group(QString msg);
    void refresh_friendlist(QString msg);
    void refresh_grouplist(QString msg);
    void signalmsg(QString msg);
    void offlinemsg(QString msg);
    void groupmsg(QString msg);
    void set_grp_member(QString msg);
    dialoge* find(QString ID);

    void test();

private slots:
    void on_friButton_clicked();

    void on_groupButton_clilked();

    void on_cancelButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Frilist *ui;
    QTcpSocket *socket;
    QToolButton *friButton;
    QToolButton *groupButton;
    QList <QToolButton *>friend_list;   //好友列表
    QList <QToolButton *>group_list;    //群组列表
    QWidget *friendBox;
    QWidget *groupBox;
    QVBoxLayout *layout_fri;    //好友页布局
    QVBoxLayout *layout_group;  //群组页布局

signals:
    void back(); //返回登录界面的信号

};

#endif // FRILIST_H
