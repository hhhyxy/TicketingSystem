#include "login.h"
#include "ui_login.h"
#include "tiplabel.h"
#include <QFile>
#include <QDebug>
#include <QPropertyAnimation>


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

    // 设置tab键焦点切换顺序
    this->setTabOrder(ui->lineEdit_usrName, ui->lineEdit_pwd);
    this->setTabOrder(ui->lineEdit_pwd, ui->pushButton_login);
//    this->setTabOrder(ui->pushButton_login, ui->lineEdit_usrName);
//    this->setTabOrder(ui->pushButton_signIn, ui->lineEdit_usrName);

    this->setTabOrder(ui->lineEdit_register_usrName, ui->lineEdit_register_pwd);
    this->setTabOrder(ui->lineEdit_register_pwd, ui->lineEdit_register_ackPwd);
//    this->setTabOrder(ui->lineEdit_register_ackPwd, ui->pushButton_register_signIn);
//    this->setTabOrder(ui->pushButton_register_signIn, ui->lineEdit_register_usrName);


}

Login::~Login()
{
    delete ui;
}

// 显示提示信息
void Login::showTip(QString tip, int x, int y)
{
    if (nullptr == tipLabel) {
        tipLabel = new TipLabel(this);
    }
    tipLabel->move(x, y);
    tipLabel->showTip(tip);
}

// 页面跳转动画
void Login::turnAnimation(int animType)
{
    if (group == nullptr) {
        leftLabel = new QLabel(ui->stackedWidget);
        leftLabel->resize(ui->page_login->size());
        leftLabel->raise();

        rightLabel = new QLabel(ui->stackedWidget);
        rightLabel->resize(ui->page_register->size());
        rightLabel->raise();

        QPropertyAnimation *animLeft = new QPropertyAnimation(leftLabel, "geometry");
        animLeft->setDuration(600);
        animLeft->setStartValue(ui->page_login->geometry());
        animLeft->setEndValue(QRect(-(ui->page_login->width()), 0, ui->page_login->width(), ui->page_login->height()));
        animLeft->setEasingCurve(QEasingCurve::OutCubic);

        QPropertyAnimation *animRight = new QPropertyAnimation(rightLabel, "geometry");
        animRight->setDuration(600);
        animRight->setStartValue(QRect(ui->page_register->width(), 0, 0, ui->page_register->height()));
        animRight->setEndValue(ui->page_register->geometry());
        animRight->setEasingCurve(QEasingCurve::OutCubic);

        group = new QParallelAnimationGroup(this);
        group->addAnimation(animLeft);
        group->addAnimation(animRight);
    }

    leftLabel->setPixmap(ui->page_login->grab());
    rightLabel->setPixmap(ui->page_register->grab());
    leftLabel->show();
    leftLabel->raise();
    rightLabel->show();
    rightLabel->raise();

    if (AnimType::RIGHT == animType) {
        group->setDirection(QAbstractAnimation::Forward);
    } else {
        group->setDirection(QAbstractAnimation::Backward);
    }

    group->start(QAbstractAnimation::KeepWhenStopped);
    connect(group, &QParallelAnimationGroup::finished, [=] {
        leftLabel->hide();
        rightLabel->hide();
    });
}

// 登录
void Login::on_pushButton_login_clicked()
{

}

// 跳转注册页面
void Login::on_pushButton_signIn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_register);
    turnAnimation();

}

// 返回登录界面
void Login::on_pushButton_register_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    turnAnimation(AnimType::LEFT);
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



