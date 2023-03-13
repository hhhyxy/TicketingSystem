#ifndef HTTP_H
#define HTTP_H


#include "movie.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "dbhelper.h"

class Http : public QObject
{
    Q_OBJECT
public:
    Http(QObject *parent = nullptr);
    ~Http();
    // 获取所有正在热映的电影
    void getAllMovie();
private:
    // 通过电影id 获取电影信息
    void getMovieInfo(QString id);
    // 解析电影id
    void parseMovieId(QNetworkReply *reply);
    // 解析电影所有信息
    void parseMovieInfo(QNetworkReply *reply);
    QNetworkAccessManager *manager;
    DBHelper *m_db;
    const QString showingUrl = "https://rank.8610000.xyz/hot/20230313/movie_showing.json";
    const QString dataUrl = "https://douban.8610000.xyz/data/%1.json";
};

#endif // HTTP_H
