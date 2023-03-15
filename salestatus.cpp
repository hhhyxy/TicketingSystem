#include "salestatus.h"
#include "ui_salestatus.h"

SaleStatus::SaleStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaleStatus)
{
    ui->setupUi(this);
    m_db = DBHelper::getInstance();
}

SaleStatus::~SaleStatus()
{
    delete ui;
}

void SaleStatus::init()
{
    // 总票数
    total = m_db->queryTicketNumber();
    // 电影列表
    QList<Movie> movieList = m_db->queryAllMovie();
    // 日期列表
    QList<QDate> dateList = m_db->queryPlaceForDate();
    // 时段列表
    QStringList periodList;
    periodList << "" << "08:00-11:59" << "12:00-17:59" << "18:00-23:59";
    // 类型列表
    QStringList typeList;
    typeList << "" << "动作" << "剧情" << "科幻" << "喜剧";
    ui->comboBox_movie->addItem("");
    // 将电影名加入下拉框
    foreach (Movie movie, movieList) {
        ui->comboBox_movie->addItem(movie.name(), movie.id());
    }
    ui->comboBox_date->addItem("");
    // 将日期加入下拉框
    foreach (QDate date, dateList) {
        ui->comboBox_date->addItem(date.toString("MM-dd"), date);
    }
    // 将时段加入下拉框
    ui->comboBox_period->addItems(periodList);
    // 将类型加入下拉框
    ui->comboBox_type->addItems(typeList);
    // 添加表头
    QStringList headers;
    headers << "电影" << "销售量" << "占比";
    ui->tableWidget_dataShow->setColumnCount(3);
    ui->tableWidget_dataShow->setHorizontalHeaderLabels(headers);
    // 表头可伸缩
    ui->tableWidget_dataShow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 表格颜色交替变化
    ui->tableWidget_dataShow->setAlternatingRowColors(true);
}

void SaleStatus::on_comboBox_date_currentIndexChanged(int index)
{
    // 清空列表内容
    clearTable();
    if (index == 0)
        return;
    // 获取点击的日期
    QDate date= ui->comboBox_date->currentData().toDate();
    // 根据日期查询数据
    QList<QStringList> table = m_db->querySalesByDate(date);
    // 加载数据到列表
    loadTable(table);
}


void SaleStatus::on_comboBox_movie_currentIndexChanged(int index)
{
    // 清空列表内容
    clearTable();
    if (index == 0)
        return;
    // 获取选中电影的id
    int id = ui->comboBox_movie->currentData().toInt();
    // 通过电影id查询数据
    QList<QStringList> table = m_db->querySalesById(id);
    // 加载数据到列表
    loadTable(table);
}


void SaleStatus::on_comboBox_period_currentIndexChanged(int index)
{
    // 清空列表内容
    clearTable();
    if (index == 0)
        return;
    // 通过时段查找数据
    QList<QStringList> table = m_db->querySalesByPeriod(index - 1);
    // 加载数据到列表
    loadTable(table);
}


void SaleStatus::on_comboBox_type_currentIndexChanged(int index)
{
    // 清空列表内容
    clearTable();
    if (index == 0)
        return;
    // 通过电影类型查找数据
    QList<QStringList> table = m_db->querySalesByType(index - 1);
    // 加载数据到列表
    loadTable(table);
}

void SaleStatus::clearTable()
{
    int rowNum=  ui->tableWidget_dataShow->rowCount();
    for(int i = 0 ; i < rowNum ; i++)//清空列表
    {
        ui->tableWidget_dataShow->removeRow(0);
    }
}

void SaleStatus::loadTable(QList<QStringList> table)
{
    for (int i = 0; i < table.size(); i++) {
        QStringList list = table.at(i);
        QString name = list.at(0);
        QString number = list.at(1);
        int ratio = number.toInt() * 100 / total;

        ui->tableWidget_dataShow->insertRow(i);

        QTableWidgetItem *item1 = new QTableWidgetItem(name);
        item1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget_dataShow->setItem(i, 0, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(number);
        item2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget_dataShow->setItem(i, 1, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem("%" + QString::number(ratio));
        item3->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget_dataShow->setItem(i, 2, item3);
    }

}

