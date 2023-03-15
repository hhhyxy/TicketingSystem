#include "login.h"
#include "ticketingsystem.h"
#include "QtSingleApplication"

int main(int argc, char *argv[])
{
    QtSingleApplication  a("ticketing_system", argc, argv);
    // 判断实例是否已经在运行
    if (a.isRunning()) {
//        a.sendMessage("app is running", 2000); // 两秒后激活前一个实例
        return EXIT_SUCCESS;
    }
    DBHelper::getInstance()->open();
    TicketingSystem ts;
    ts.setGeometry(253, 32, 1503, 970);
    ts.login();
    return a.exec();
}
