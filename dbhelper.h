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
    explicit DBHelper(QObject *parent = nullptr);
    // 打开数据库
    void open();
    // 根据用户名查询用户信息
    User queryUser(QString &name);
    // 插入用户
    void insertUser(User user);
    // 查询电影列表（电影id，名称，海报）
    QList<Movie> queryAllMovie();
    // 查询指定电影详情
    Movie queryMovie(int id);
    // 查询指定电影的所有场次
    Place queryPlace(int id);
    // 更新场次信息
    void updatePlace(Place &place);
    // 插入电影票
    void inseartTicket(Ticket &ticket);
    // 关闭数据库
    void close();
private:
    QSqlDatabase m_db;
};

#endif // DBHELPER_H
