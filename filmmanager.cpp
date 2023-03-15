#include "filmmanager.h"
#include "ui_filmmanager.h"

FilmManager::FilmManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilmManager)
{
    ui->setupUi(this);
    ui->tableView_movieInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_movieInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_movieInfo->verticalHeader()->setVisible(false);

    ui->tableView_placeInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_placeInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_placeInfo->verticalHeader()->setVisible(false);
}

FilmManager::~FilmManager()
{
    delete ui;
}

void FilmManager::init()
{
    // 初始化model
    m_movieModel = new QSqlTableModel(this);
    m_movieModel->setTable("movie");
    m_movieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 查询user表格所有数据
    m_movieModel->select();
    // 设置表头，关联数据库字段
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("m_id"),Qt::Horizontal,"id");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("m_name"),Qt::Horizontal,"电影名称");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("picture"),Qt::Horizontal,"图片链接");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("introduce"),Qt::Horizontal,"简介");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("dictors"),Qt::Horizontal,"导演");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("actors"),Qt::Horizontal,"演员");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("durations"),Qt::Horizontal,"时长");
    m_movieModel->setHeaderData(m_movieModel->fieldIndex("type"),Qt::Horizontal,"类型");
    // 给tableview设置model
    ui->tableView_movieInfo->setModel(m_movieModel);

    // 初始化model
    m_placeModel = new QSqlTableModel(this);
    m_placeModel->setTable("place");
    m_placeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 查询power表格所有数据
    m_placeModel->select();
    // 设置表头，关联数据库字段
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("p_name"),Qt::Horizontal,"场地名称");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("m_id"),Qt::Horizontal,"电影id");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("m_name"),Qt::Horizontal,"电影名称");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("date"),Qt::Horizontal,"日期");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("price"),Qt::Horizontal,"价格");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("start_time"),Qt::Horizontal,"开场时间");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("end_time"),Qt::Horizontal,"结束时间");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("max_row"),Qt::Horizontal,"排");
    m_placeModel->setHeaderData(m_placeModel->fieldIndex("max_column"),Qt::Horizontal,"座");
    // 给tableview设置model
    ui->tableView_placeInfo->setModel(m_placeModel);
    // 隐藏id和seat
    ui->tableView_placeInfo->setColumnHidden(0, true);
    ui->tableView_placeInfo->setColumnHidden(10, true);
}

void FilmManager::on_pushButton_insertMovie_clicked()
{
    // m_model每次只能最大缓存256个，所以需要先fetchMore
    while (m_movieModel->canFetchMore()) {
        m_movieModel->fetchMore();
    }
    // 总行数
    int rowCount = m_movieModel->rowCount();
    // 在最后插入一条数据
    m_movieModel->insertRow(rowCount);
    // 将表格设置为可修改
    ui->tableView_movieInfo->setEditTriggers(QTableView::DoubleClicked);
    // 滚动到尾行
    ui->tableView_movieInfo->scrollToBottom();
}


void FilmManager::on_pushButton_updateMovie_clicked()
{
    // 表格设置为可修改
    ui->tableView_movieInfo->setEditTriggers(QTableView::DoubleClicked);
}


void FilmManager::on_pushButton_deleteMovie_clicked()
{
    // 删除选中行
    m_movieModel->removeRow(ui->tableView_movieInfo->currentIndex().row());
    // 提交
    m_movieModel->submitAll();
}


void FilmManager::on_pushButton_commitMovie_clicked()
{
    // 提交修改
    m_movieModel->submitAll();
    ui->tableView_movieInfo->setEditTriggers(QTableView::NoEditTriggers);
}


void FilmManager::on_pushButton_cancelMovie_clicked()
{
    // 撤回修改
    m_movieModel->revertAll();
    // 刷新
    m_movieModel->select();
}


void FilmManager::on_pushButton_insertPlace_clicked()
{
    // m_model每次只能最大缓存256个，所以需要先fetchMore
    while (m_placeModel->canFetchMore()) {
        m_placeModel->fetchMore();
    }
    // 总行数
    int rowCount = m_placeModel->rowCount();
    // 在最后插入一条数据
    m_placeModel->insertRow(rowCount);
    m_placeModel->setData(m_placeModel->index(rowCount, 10), QVariant::fromValue(QBitArray()));
    // 将表格设置为可修改
    ui->tableView_placeInfo->setEditTriggers(QTableView::DoubleClicked);
    // 滚动到尾行
    ui->tableView_placeInfo->scrollToBottom();
}


void FilmManager::on_pushButton_updatePlace_clicked()
{
    // 将表格设置为可修改
    ui->tableView_placeInfo->setEditTriggers(QTableView::DoubleClicked);
}


void FilmManager::on_pushButton_deletePlace_clicked()
{
    // 删除选中行并提交事务
    m_placeModel->removeRow(ui->tableView_placeInfo->currentIndex().row());
    m_placeModel->submitAll();
}


void FilmManager::on_pushButton_commitPlace_clicked()
{
    // 提交事物
    m_placeModel->submitAll();
    ui->tableView_placeInfo->setEditTriggers(QTableView::NoEditTriggers);
}


void FilmManager::on_pushButton_cancelPlace_clicked()
{
    // 撤销事物
    m_placeModel->revertAll();
    m_placeModel->select();
}

