#ifndef SHOWINGMOVIE_H
#define SHOWINGMOVIE_H

#include <QStackedWidget>
#include "dbhelper.h"
#include <QListWidgetItem>

namespace Ui {
class ShowingMovie;
}

class ShowingMovie : public QStackedWidget
{
    Q_OBJECT

public:
    explicit ShowingMovie(QWidget *parent = nullptr);
    ~ShowingMovie();

private slots:
    void on_listWidget_movieList_itemClicked(QListWidgetItem *item);

private:
    Ui::ShowingMovie *ui;
    DBHelper *m_db;

};

#endif // SHOWINGMOVIE_H
