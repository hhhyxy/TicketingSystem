#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>
#include <QDate>
#include <QBitArray>

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
    Movie (int id, QString name, QString introduce, QString picture, QString directors, QString actors, QString duration, QString type);
    int id() const;

    QString name() const;
    void setName(const QString &newName);

    QString introduce() const;
    void setIntroduce(const QString &newIntroduce);

    QString actors() const;
    void setActors(const QString &newActors);

    QString duration() const;
    void setDuration(const QString &newDuration);

    QString type() const;
    void setType(const QString &newType);

    QString picture() const;
    void setPicture(const QString &newPicture);

    QString dirtectors() const;
    void setDirtectors(const QString &newDirtectors);

private:
    int m_id;                       // 电影id
    QString m_name;                 // 电影名称
    QString m_introduce;            // 电影简介
    QString m_picture;              // 电影海报
    QString m_dirtectors;           // 导演
    QString m_actors;               // 主演
    QString m_duration;             // 电影时长
    QString m_type;                 // 电影类型

};

class Place
{
public:
    Place();
    Place(int id, QString name, int movieId, QDate date, int price, QTime startTime, QTime endTime, int maxRow, int maxCol, QBitArray seat);
    int id() const;

    QString name() const;
    void setName(QString newName);

    QBitArray seat() const;
    void setSeat(const QBitArray &newSeat);

    int movieId() const;

    QDate getDate() const;
    void setDate(const QDate &newDate);

    int price() const;
    void setPrice(int newPrice);

    QTime startTime() const;
    void setStartTime(const QTime &newStartTime);

    QTime endTime() const;
    void setEndTime(const QTime &newEndTime);

    int maxRow() const;
    void setMaxRow(int newMaxRow);

    int maxCol() const;
    void setMaxCol(int newMaxCol);

private:
    int m_id;               // 场次id
    QString m_name;         // 场地名称
    int m_movieId;          // 电影id
    QDate m_date;           // 日期
    int m_price;            // 价格
    QTime m_startTime;      // 开场时间
    QTime m_endTime;        // 结束时间
    int m_maxRow;           // 最大行
    int m_maxCol;           // 最大列
    QBitArray m_seat;       // 座位

};

class Ticket
{
public:
    Ticket();
    Ticket(int userId, int movieId, int placeId, QTime time, int row, int col);
    Ticket(int id, int userId, int movieId, int placeId, QTime time, int row, int col);
    int userId() const;
    void setUserId(int newUserId);

    int movieId() const;
    void setMovieId(int newMovieId);

    int placeId() const;
    void setPlaceId(int newPlaceId);

    QTime time() const;
    void setTime(const QTime &newTime);

    int row() const;
    void setRow(int newRow);

    int col() const;
    void setCol(int newCol);

    int id() const;

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
