#ifndef DBHELPER_H
#define DBHELPER_H
#include <QObject>
#include <QSqlDatabase>
#include "movie.h"
#include "user.h"
class DBHelper : public QObject
{
    Q_OBJECT
public:
    // 获取数据库实例
    static DBHelper *getInstance();
    // 打开数据库
    void open();
    // 根据用户名查询用户信息
    User queryUser(QString &name);
    // 查询所有用户信息
    QList<User> queryAllUser();
    // 插入用户
    void insertUser(User user);
    // 更新用户信息
    void updateUser(User user);
    QList<Power> queryPower();
    // 查询电影列表（电影id，名称，海报）
    QList<Movie> queryAllMovie();
    // 查询指定电影详情
    Movie queryMovie(int id);
    // 插入电影
    void insertMovie(Movie movie);
    // 查询指定电影的所有场次
    QList<Place> queryPlace(int id);
    // 更新场次信息
    void updatePlace(Place &place);
    // 插入电影票
    void insertTicket(Ticket &ticket);
    // 查询所有电影票的数量
    int queryTicketNumber();
    // 查询所有场次日期
    QList<QDate> queryPlaceForDate();
    // 查询指定日期电影售卖情况
    QList<QStringList> querySalesByDate(QDate date);
    // 查询指定时段电影售卖情况
    QList<QStringList> querySalesByPeriod(int period);
    // 查询指定电影的售卖情况
    QList<QStringList> querySalesById(int id);
    // 查询指定类型电影售卖情况
    QList<QStringList> querySalesByType(int type);
    // 关闭数据库
    void close();

private:
    // 禁用拷贝和移动构造函数
    Q_DISABLE_COPY_MOVE(DBHelper)
    explicit DBHelper(QObject *parent = nullptr);
    static DBHelper *instance;
    QSqlDatabase m_db;
};

#endif // DBHELPER_H
