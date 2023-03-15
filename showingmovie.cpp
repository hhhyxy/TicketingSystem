#include "showingmovie.h"
#include "ui_showingmovie.h"

ShowingMovie::ShowingMovie(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::ShowingMovie)
{
    ui->setupUi(this);
    m_db = DBHelper::getInstance();
    m_db->open();
    // 查询所有电影
    QList<Movie> movieList = m_db->queryAllMovie();
    // 显示电影图片和名称
    foreach (Movie movie, movieList) {
        ui->listWidget_movieList->addPicture(movie);
    }
}

ShowingMovie::~ShowingMovie()
{
    delete ui;
}

// 列表点击时间
void ShowingMovie::on_listWidget_movieList_itemClicked(QListWidgetItem *item)
{
    // 获取点击的电影的id
    int id = item->data(Qt::UserRole).toInt();
    qDebug()<<id;
    // 通过id获取电影详情
    Movie movie = m_db->queryMovie(id);
    // 切换到详情界面
    this->setCurrentWidget(ui->page_details);
}

