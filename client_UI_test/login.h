#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Widget.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_minimizeButton_clicked(); //最小化登陆界面

    void on_closeButton_clicked(); //关闭登陆界面

    void on_loginButton_clicked();

private:
    Ui::login *ui;
    Widget menu;
};

#endif // LOGIN_H
