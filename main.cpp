#include "login.h"
#include "ticketingsystem.h"
#include "QtSingleApplication"
#include <QtGui>

int main(int argc, char *argv[])
{
    QtSingleApplication  a("ticketing_system", argc, argv);
    // 判断实例是否已经在运行
    if (a.isRunning()) {
//        a.sendMessage("app is running", 2000); // 两秒后激活前一个实例
        return EXIT_SUCCESS;
    }
    Login login;
    login.show();
    return a.exec();
}
