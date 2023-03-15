#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QDebug>
#include <QTimer>


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
    this->setTabOrder(ui->lineEdit_register_usrName, ui->lineEdit_register_pwd);
    this->setTabOrder(ui->lineEdit_register_pwd, ui->lineEdit_register_ackPwd);
    // 在密码编辑框按确认登录
    connect(ui->lineEdit_pwd, &QLineEdit::returnPressed, this, &Login::on_pushButton_login_clicked);
    // 获取数据库
    m_db = DBHelper::getInstance();
}

void Login::showThisTip(QString tip, int y)
{
    this->showTip(tip, 0, y, this);
}

Login::~Login()
{
    delete ui;
}

// 游客登录
void Login::on_pushButton_tourist_clicked()
{
    emit touristVisit();
    this->close();
}

// 登录
void Login::on_pushButton_login_clicked()
{
    QString name = ui->lineEdit_usrName->text().trimmed();
    QString pwd = ui->lineEdit_pwd->text().trimmed();
    if (name.isEmpty()) {
        this->showThisTip("用户名不能为空！");
        return;
    }
    if (pwd.isEmpty()) {
        this->showThisTip("密码不能为空！");
        return;
    }
    User user = m_db->queryUser(name);
    if (user.name().isEmpty()) {
        this->showThisTip("用户名不存在！");
        return;
    }
    if (pwd != user.pwd()) {
        this->showThisTip("密码错误！");
        return;
    }
    if (pwd == user.pwd()) {
        this->showThisTip("登录成功！");
    }
    emit loginSuccess(user);
    this->close();
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
    QString name = ui->lineEdit_register_usrName->text().trimmed();
    QString pwd = ui->lineEdit_register_pwd->text().trimmed();
    QString ackPwd = ui->lineEdit_register_ackPwd->text().trimmed();
    if (name.isEmpty()) {
        this->showThisTip("用户名不能为空！", 270);
        return;
    }
    if (pwd.isEmpty()) {
        this->showThisTip("密码不能为空！", 270);
        return;
    }
    if (ackPwd.isEmpty()) {
        this->showThisTip("请确认密码！", 270);
        return;
    }
    if (pwd != ackPwd) {
        this->showThisTip("两次输入的密码不匹配！", 270);
        return;
    }
    User res = m_db->queryUser(name);
    if (res.name() == name) {
        this->showThisTip("用户名已存在", 270);
        return;
    }
    User user(name, pwd, QDateTime::currentDateTime());
    m_db->insertUser(user);
    showThisTip("注册成功！", 270);
    on_pushButton_register_return_clicked();
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


