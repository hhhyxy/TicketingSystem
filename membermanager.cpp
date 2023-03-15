#include "membermanager.h"
#include "ui_membermanager.h"
#include "dbhelper.h"
#include <QDebug>
#include <QTimer>
MemberManager::MemberManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberManager)
{
    ui->setupUi(this);
    ui->tableView_userInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_userInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView_userInfo->verticalHeader()->setVisible(false);

    ui->tableView_powerInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_powerInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_powerInfo->verticalHeader()->setVisible(false);
}

MemberManager::~MemberManager()
{
    delete ui;
}

void MemberManager::init()
{
    // 初始化model
    m_model = new QSqlTableModel(this);
    m_model->setTable("user");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 查询user表格所有数据
    m_model->select();
    // 设置表头，关联数据库字段
    m_model->setHeaderData(m_model->fieldIndex("u_name"),Qt::Horizontal,"用户名");
    m_model->setHeaderData(m_model->fieldIndex("password"),Qt::Horizontal,"密码");
    m_model->setHeaderData(m_model->fieldIndex("u_time"),Qt::Horizontal,"注册时间");
    m_model->setHeaderData(m_model->fieldIndex("grade"),Qt::Horizontal,"等级");
    m_model->setHeaderData(m_model->fieldIndex("score"),Qt::Horizontal,"积分");
    m_model->setHeaderData(m_model->fieldIndex("sex"),Qt::Horizontal,"性别");
    m_model->setHeaderData(m_model->fieldIndex("age"),Qt::Horizontal,"年龄");
    m_model->setHeaderData(m_model->fieldIndex("mail"),Qt::Horizontal,"邮箱");
    m_model->setHeaderData(m_model->fieldIndex("phone"),Qt::Horizontal,"电话");
    m_model->setHeaderData(m_model->fieldIndex("birthday"),Qt::Horizontal,"生日");
    // 给tableview设置model
    ui->tableView_userInfo->setModel(m_model);
    // 隐藏id和注册时间
    ui->tableView_userInfo->setColumnHidden(0, true);
    ui->tableView_userInfo->setColumnHidden(1, true);

    // 初始化model
    m_powerModel = new QSqlTableModel(this);
    m_powerModel->setTable("power");
    m_powerModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 查询power表格所有数据
    m_powerModel->select();
    // 设置表头，关联数据库字段
    m_powerModel->setHeaderData(m_powerModel->fieldIndex("grade"),Qt::Horizontal,"等级");
    m_powerModel->setHeaderData(m_powerModel->fieldIndex("min_score"),Qt::Horizontal,"积分条件");
    m_powerModel->setHeaderData(m_powerModel->fieldIndex("discount"),Qt::Horizontal,"折扣");
    // 给tableview设置model
    ui->tableView_powerInfo->setModel(m_powerModel);
    // 隐藏birthday_discount和member_discount
    ui->tableView_powerInfo->setColumnHidden(3, true);
    ui->tableView_powerInfo->setColumnHidden(4, true);
}

void MemberManager::on_pushButton_insert_clicked()
{
    // m_model每次只能最大缓存256个，所以需要先fetchMore
    while (m_model->canFetchMore()) {
        m_model->fetchMore();
    }
    // 总行数
    int rowCount = m_model->rowCount();
    // 在最后插入一条数据
    m_model->insertRow(rowCount);
    // 设置为第一列的值为当前时间
    m_model->setData(m_model->index(rowCount, 1), QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    // 将表格设置为可修改
    ui->tableView_userInfo->setEditTriggers(QTableView::DoubleClicked);
    // 滚动到尾行
    ui->tableView_userInfo->scrollToBottom();
}


void MemberManager::on_pushButton_update_clicked()
{
    // 将表格设置为可修改
    ui->tableView_userInfo->setEditTriggers(QTableView::DoubleClicked);
}


void MemberManager::on_pushButton_delete_clicked()
{
    // 删除选中行
    m_model->removeRow(ui->tableView_userInfo->currentIndex().row());
    // 提交所有更改
    m_model->submitAll();
}


void MemberManager::on_pushButton_commit_clicked()
{
    // 提交所有更改
    m_model->submitAll();
    // 表格设置为不可更改
    ui->tableView_userInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MemberManager::on_pushButton_cancel_clicked()
{
    // 取消更改
    m_model->revertAll();
    // 刷新表格
    m_model->select();
    // 表格设置为不可更改
    ui->tableView_userInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MemberManager::on_pushButton_insertPower_clicked()
{
    // m_model每次只能最大缓存256个，所以需要先fetchMore
    while (m_powerModel->canFetchMore()) {
        m_powerModel->fetchMore();
    }
    // 总行数
    int rowCount = m_powerModel->rowCount();
    // 在最后插入一条数据
    m_powerModel->insertRow(rowCount);
    // 将表格设置为可修改
    ui->tableView_powerInfo->setEditTriggers(QTableView::DoubleClicked);
    // 滚动到尾行
    ui->tableView_powerInfo->scrollToBottom();
}


void MemberManager::on_pushButton_updatePower_clicked()
{
    // 将表格设置为可修改
    ui->tableView_powerInfo->setEditTriggers(QTableView::DoubleClicked);
}


void MemberManager::on_pushButton_deletePower_clicked()
{
    // 删除选中行
    m_powerModel->removeRow(ui->tableView_powerInfo->currentIndex().row());
    m_powerModel->submitAll();
}


void MemberManager::on_pushButton_commitPower_clicked()
{
    // 提交修改
    m_powerModel->submitAll();
    ui->tableView_powerInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MemberManager::on_pushButton_cancelPower_clicked()
{
    // 撤回修改
    m_powerModel->revertAll();
    m_powerModel->select();
    // 表格设置为不可更改
    ui->tableView_powerInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

