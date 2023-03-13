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

