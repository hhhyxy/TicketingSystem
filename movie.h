#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>
#include <QDate>

class Movie
{
public:
//    enum MovieType {
//        Action,         // 动作片
//        Comedy,         // 喜剧
//        Horror,         // 恐怖片
//        Love,           // 爱情片
//        Documentary,    // 纪录片
//        History,        // 历史片
//        War,            // 战争片
//        Science,        // 科幻片
//        Crime,          // 犯罪片
//        Cartoon,        // 动画片
//        Music           // 音乐片
//    };
    Movie ();
    Movie (int id, QString name, QString picture);
    Movie (int id, QString name, QString introduce, QString picture, QStringList directors, QStringList actors, QString duration, QStringList type);
    int id() const;

    QString name() const;
    void setName(const QString &newName);

    QString introduce() const;
    void setIntroduce(const QString &newIntroduce);

    QStringList actors() const;
    void setActors(const QStringList &newActors);

    QString duration() const;
    void setDuration(const QString &newDuration);

    QStringList type() const;
    void setType(const QStringList &newType);

    QString picture() const;
    void setPicture(const QString &newPicture);

private:
    int m_id;                   // 电影id
    QString m_name;             // 电影名称
    QString m_introduce;        // 电影简介
    QString m_picture;          // 电影海报
    QStringList m_dirtectors;   // 导演
    QStringList m_actors;       // 主演
    QString m_duration;         // 电影时长
    QStringList m_type;         // 电影类型
};

class Place
{
public:
    Place();
    int id() const;

private:
    int m_id;           // 场次id
    int m_movieName;    // 电影名称
    QDate date;         // 日期
    int m_price;        // 价格
    QTime m_startTime;  // 开场时间
    QTime m_endTime;    // 结束时间
    int m_maxRow;       // 最大行
    int m_maxCol;       // 最大列
};

class Ticket
{
public:
    Ticket();
    Ticket(int id, int userId, int movieId, int placeId, QTime time, int row, int col);
private:
    int m_id;       // 电影票id
    int m_userId;   // 用户id
    int m_movieId;  // 电影id
    int m_placeId;  // 场次id
    QTime m_time;   // 购票时间
    int m_row;      // 行
    int m_col;      // 列
};

#endif // MOVIE_H
