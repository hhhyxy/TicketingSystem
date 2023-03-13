#ifndef SHOWINGMOVIE_H
#define SHOWINGMOVIE_H

#include <QStackedWidget>
#include "dbhelper.h"
namespace Ui {
class ShowingMovie;
}

class ShowingMovie : public QStackedWidget
{
    Q_OBJECT

public:
    explicit ShowingMovie(QWidget *parent = nullptr);
    ~ShowingMovie();

private:
    Ui::ShowingMovie *ui;
    DBHelper *m_db;

};

#endif // SHOWINGMOVIE_H
