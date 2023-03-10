#include "login.h"
#include <QApplication>
#include "tiplabel.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login login;
    login.show();

//    // 当登陆界面发出登录信号，显示主界面,关闭登录界面
//    QObject::connect(&login, &Login::signIn, [=] {
//        login.close();
//    });
    return a.exec();
}
