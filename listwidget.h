#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "movie.h"
#include <QListWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);
    void addPicture(Movie movie);
private:
    void showPicture(QNetworkReply *reply, Movie movie);
private:

    QNetworkAccessManager *manager;
};

#endif // LISTWIDGET_H
