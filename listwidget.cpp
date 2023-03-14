#include "listwidget.h"
#include <QPixmap>
#include <QIcon>
#include <QScrollBar>

ListWidget::ListWidget(QWidget *parent)
    : QListWidget{parent}
{
    manager = new QNetworkAccessManager(this);
    this->setIconSize(QSize(200, 350));
    this->setSpacing(30);

    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setViewMode(QListView::IconMode);
    this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->verticalScrollBar()->setSingleStep(20);
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
        item->setToolTip(movie.name());
        item->setSizeHint(QSize(200,350));
        this->addItem(item);
    }
    else
    {
        qDebug()<< __FILE__<<__LINE__ << "showMoviePic_Erro:" << reply->errorString().toUtf8();
    }
    reply->deleteLater();
}
