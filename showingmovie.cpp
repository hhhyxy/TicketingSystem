#include "showingmovie.h"
#include "ui_showingmovie.h"

ShowingMovie::ShowingMovie(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::ShowingMovie)
{
    ui->setupUi(this);
    m_db = DBHelper::getInstance();
    m_db->open();
    QList<Movie> movieList = m_db->queryAllMovie();
    foreach (Movie movie, movieList) {
        ui->listWidget_movieList->addPicture(movie.picture(), movie.name());
    }
}

ShowingMovie::~ShowingMovie()
{
    delete ui;
}
