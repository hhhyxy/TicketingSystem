#include "ticketingsystem.h"
#include "ui_ticketingsystem.h"
#include <QFile>

TicketingSystem::TicketingSystem(QWidget *parent) :
    ShadowWidget(parent),
    ui(new Ui::TicketingSystem)
{
    ui->setupUi(this);

    QFile file(":/style/style.css");
    file.open(QIODevice::ReadOnly);
    this->setStyleSheet(QString(file.readAll()));
    file.close();
}

TicketingSystem::~TicketingSystem()
{
    delete ui;
}

// 关闭窗口
void TicketingSystem::on_pushButton_close_clicked()
{
    this->close();
}

// 最大化
void TicketingSystem::on_pushButton_max_clicked()
{
    if (this->isMaximized()) {
        this->showNormal();
    } else {
        this->showMaximized();
    }
}

// 最小化
void TicketingSystem::on_pushButton_min_clicked()
{
    this->showMinimized();
}

// 选座购票
void TicketingSystem::on_pushButton_movies_clicked()
{
    ui->stackedWidget_content->setCurrentWidget(ui->page_hitFilm);
}

// 个人中心
void TicketingSystem::on_pushButton_personalInfo_clicked()
{
    ui->stackedWidget_content->setCurrentWidget(ui->page_personalCenter);
}

// 电影管理
void TicketingSystem::on_pushButton_movieManager_clicked()
{
    ui->stackedWidget_content->setCurrentWidget(ui->page_filmManager);
}

// 用户管理
void TicketingSystem::on_pushButton_memManager_clicked()
{
    ui->stackedWidget_content->setCurrentWidget(ui->page_userManager);
}

// 销售情况
void TicketingSystem::on_pushButton_sales_clicked()
{
    ui->stackedWidget_content->setCurrentWidget(ui->page_sales);
}

