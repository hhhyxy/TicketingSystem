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
    // 插入用户
    void insertUser(User user);
    // 更新用户信息
    void updateUser(User user);
    // 查询电影列表（电影id，名称，海报）
    QList<Movie> queryAllMovie();
    // 查询指定电影详情
    Movie queryMovie(int id);
    // 插入电影
    void insertMovie(Movie movie);
    // 查询指定电影的所有场次
    Place queryPlace(int id);
    // 更新场次信息
    void updatePlace(Place &place);
    // 插入电影票
    void insertTicket(Ticket &ticket);
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
