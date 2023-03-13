#include "listwidget.h"
#include <QPixmap>
#include <QIcon>
ListWidget::ListWidget(QWidget *parent)
    : QListWidget{parent}
{
    manager = new QNetworkAccessManager(this);
    this->setIconSize(QSize(200, 330));
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setViewMode(QListView::IconMode);

    this->setSpacing(80);
}

void ListWidget::addPicture(Movie movie)
{
    QNetworkRequest request;
    request.setUrl(movie.picture());
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [=] {
        showPicture(reply, movie);
    });
}

void ListWidget::showPicture(QNetworkReply *reply, Movie movie)
{
    // 状态码
    int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << __FILE__ << __LINE__ << "status_code:" << status_code;

    //response
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap img;
        img.loadFromData(bytes);
        QListWidgetItem *item = new QListWidgetItem(QIcon(img.scaled(200, 300)), movie.name());
        item->setData(Qt::UserRole, movie.id());
        item->setSizeHint(QSize(200,330));
        this->addItem(item);
    }
    else
    {
        qDebug()<< __FILE__<<__LINE__ << "showMoviePic_Erro:" << reply->errorString().toUtf8();
    }
    reply->deleteLater();
}
