#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QMessageBox>
#include <QMouseEvent>
#include <Qt>
#include <frilist.h>
#include<regist.h>
#include <dialoge.h>
#include<QTcpSocket>
#include<QHostAddress>
#include<QDebug>
#include<QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    Frilist *fr;//之前是一个公有无指针，一个私有有指针，这里我让两个成员统一一下形式
    regist *r;
    dialoge *di;

protected:
    void mouseMoveEvent(QMouseEvent *e); //鼠标移动
    void mousePressEvent(QMouseEvent *e); //鼠标按下移动
    void mouseReleaseEvent();
   /* bool eventFilter(QObject *obj, QEvent *event);*/

private slots:
    void on_cancelButton_clicked();

    void on_changeButton_clicked();

    void on_loginButton_clicked();

    void on_hideButton_clicked();

    void on_closeButton_clicked();

    void on_registButton_clicked();

    void back_from_frilist();  //与back信号关联的槽函数

    void back_from_regist();  //从regist返回widget界面

private:
    Ui::Widget *ui;
    QPoint p;
    bool login_in; //判断账号是否已经登录，true为已登陆，false为未登录，默认为false
    QString ID;
    QString Password;
    QTcpSocket *socket;
    bool mouse_press;
  /*  //标题拖动、双击最大化
        bool mDrag;
        QPoint mDragPos;
        bool mIsMax;
        QRect mLocation;
        QFont mIconFont;

        //与缩放相关的变量
        int mZoom;
        QRect mZoomLocation;
        QPoint mZoomPos;*/

    void login_feedback(QString msg);//得对每个需要服务器指令的操作建立一个函数
};

#endif // WIDGET_H
