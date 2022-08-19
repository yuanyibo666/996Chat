#include "Widget.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login l;    //登录界面
    l.show();

    return a.exec();
}
