#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QPropertyAnimation>
#include "ticketingsystem.h"

Login::Login(QWidget *parent) :
    ShadowWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    // 加载样式表
    QFile file(":/style/style.css");
    file.open(QIODevice::ReadOnly);
    this->setStyleSheet(QString(file.readAll()));
    file.close();
    // 设置主界面
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    // 设置tab键焦点切换顺序
    this->setTabOrder(ui->lineEdit_usrName, ui->lineEdit_pwd);
    this->setTabOrder(ui->lineEdit_pwd, ui->pushButton_login);
    this->setTabOrder(ui->lineEdit_register_usrName, ui->lineEdit_register_pwd);
    this->setTabOrder(ui->lineEdit_register_pwd, ui->lineEdit_register_ackPwd);
    m_db.open();
}

Login::~Login()
{
    delete ui;
}

// 游客登录
void Login::on_pushButton_tourist_clicked()
{
//    emit loginSuccess(0);
    onLogin(0);
}

void Login::onLogin(int u_id)
{
    Q_UNUSED(u_id)
    TicketingSystem *ts = new TicketingSystem();
    ts->setAttribute(Qt::WA_DeleteOnClose);
    ts->setGeometry(253, 32, 1503, 970);
    ts->show();
    this->close();
}

// 登录
void Login::on_pushButton_login_clicked()
{

}

// 跳转注册页面
void Login::on_pushButton_signIn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_register);
    this->siwtchingAnimation(ui->stackedWidget, ui->page_login, ui->page_register);
    QTimer::singleShot(animTime-100, [=] {
        ui->label_title->setText("注册");
    });
}

// 返回登录界面
void Login::on_pushButton_register_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    this->siwtchingAnimation(ui->stackedWidget, ui->page_login, ui->page_register, AnimDirection::Backward);
    QTimer::singleShot(animTime-100, [=] {
        ui->label_title->setText("登录");
    });
}

// 注册
void Login::on_pushButton_register_signIn_clicked()
{
    showTip("sign in", 0, 250);
}

// 最小化
void Login::on_pushButton_min_clicked()
{
    this->showMinimized();
}

// 关闭
void Login::on_pushButton_close_clicked()
{
    this->close();
}


