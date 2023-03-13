#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);
    void addPicture(QString url, QString name);
private:
    void showPicture(QNetworkReply *reply, QString name);
private:

    QNetworkAccessManager *manager;
};

#endif // LISTWIDGET_H
