#include "http.h"
#include <QEventLoop>
#include <QTimer>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>

Http::Http(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
    m_db = DBHelper::getInstance();
}

Http::~Http()
{
    manager->deleteLater();
}

void Http::getAllMovie()
{
    QNetworkRequest request;
    request.setUrl(QUrl(showingUrl));
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [=] {
        qDebug()<<"id";
        parseMovieId(reply);
    });
}

void Http::getMovieInfo(QString id)
{
    QNetworkRequest request;
    QString url = dataUrl.arg(id);
    request.setUrl(QUrl(url));
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [=] {
        parseMovieInfo(reply);
    });
}

void Http::parseMovieId(QNetworkReply *reply)
{
    // 状态码
    int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << __FILE__ << __LINE__ << "status_code:" << status_code;

    //response
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        // 将json解析为编码为UTF-8的json文档
        QJsonParseError json_error;
        QJsonDocument parse_doucment = QJsonDocument::fromJson(bytes, &json_error);
        // json解析错误处理
        if (json_error.error != QJsonParseError::NoError) {
            qDebug()<< __FILE__<<__LINE__ <<"parseForMusic_Erro:" << json_error.errorString();
            return ;
        }
        QJsonArray movieInfoArray = parse_doucment.array();
        for (int i = 0; i < movieInfoArray.size(); i++) {
            QString id = movieInfoArray.at(i).toObject().value("id").toString();
            getMovieInfo(id);
        }
    }
    else
    {
        qDebug()<< __FILE__<<__LINE__ << "parseMovieInfo_Erro:" << reply->errorString().toUtf8();
    }
    reply->deleteLater();
}

void Http::parseMovieInfo(QNetworkReply *reply)
{
    // 状态码
    int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << __FILE__ << __LINE__ << "status_code:" << status_code;

    //response
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        // 将json解析为编码为UTF-8的json文档
        QJsonParseError json_error;
        QJsonDocument parse_doucment = QJsonDocument::fromJson(bytes, &json_error);
        // json解析错误处理
        if (json_error.error != QJsonParseError::NoError) {
            qDebug()<< __FILE__<<__LINE__ <<"parseForMusic_Erro:" << json_error.errorString();
            return;
        }
        QJsonObject movieInfo = parse_doucment.toVariant().toJsonObject();
        int id = movieInfo.value("id").toString().toInt();
        QString title = movieInfo.value("title").toString();
        QString pic = movieInfo.value("pic").toObject().value("normal").toString();
        QString intro = movieInfo.value("intro").toString();
        QString card_subtitle = movieInfo.value("card_subtitle").toString();
        QStringList list = card_subtitle.split("/");
        QString type = list.at(2);
        QString directors = list.at(3);
        QString actors = list.at(4);
        QString durations = movieInfo.value("durations").toArray().at(0).toString();
        Movie movie(id, title, intro, pic, directors, actors, durations, type);
        m_db->insertMovie(movie);
    }
    else
    {
        qDebug()<< __FILE__<<__LINE__ << "parseMovieInfo_Erro:" << reply->errorString().toUtf8();
    }
    reply->deleteLater();
}
