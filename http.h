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
    void getAllMovie();
    void getMovieInfo(QString id);
private:
    void parseMovieId(QNetworkReply *reply);
    void parseMovieInfo(QNetworkReply *reply);
    QNetworkAccessManager *manager;
    DBHelper *m_db;
    const QString showingUrl = "https://rank.8610000.xyz/hot/20230313/movie_showing.json";
    const QString dataUrl = "https://douban.8610000.xyz/data/%1.json";
};

#endif // HTTP_H
