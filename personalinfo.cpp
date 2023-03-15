#include "personalinfo.h"
#include "ui_personalinfo.h"

PersonalInfo::PersonalInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalInfo)
{
    ui->setupUi(this);
    m_db = DBHelper::getInstance();
}

PersonalInfo::~PersonalInfo()
{
    delete ui;
}

void PersonalInfo::showUserInfo(User user)
{
    this->user = user;
    ui->label_name->setText(user.name());
    ui->lineEdit_pwd->setText(user.pwd());
    ui->label_grade->setText(QString::number(user.grade()));
    ui->label_score->setText(QString::number(user.score()));
    ui->label_registerTime->setText(user.joinTime().toString("yyyy-MM-dd hh:mm:ss"));
    switch (user.sex()) {
    case User::Man:
        ui->radioButton_man->click();

        break;
    case User::Woman:
        ui->radioButton_woman->click();
        break;
    default:
        break;
    }
    ui->lineEdit_age->setText(QString::number(user.age()));
    ui->dateEdit_birthday->setDate(user.birthday());
    ui->lineEdit_mail->setText(user.mail());
    ui->lineEdit_phone->setText(user.phone());
}

void PersonalInfo::on_lineEdit_pwd_textChanged(const QString &arg1)
{
    user.setPwd(arg1);
}


void PersonalInfo::on_radioButton_man_clicked()
{
    user.setSex(User::Man);
}


void PersonalInfo::on_radioButton_woman_clicked()
{
    user.setSex(User::Woman);
}


void PersonalInfo::on_lineEdit_age_textChanged(const QString &arg1)
{
    user.setAge(arg1.toInt());
}


void PersonalInfo::on_dateEdit_birthday_userDateChanged(const QDate &date)
{
    user.setBirthday(date);
}


void PersonalInfo::on_lineEdit_mail_textChanged(const QString &arg1)
{
    user.setMail(arg1);
}


void PersonalInfo::on_lineEdit_phone_textChanged(const QString &arg1)
{
    user.setPhone(arg1);
}


void PersonalInfo::on_pushButton_save_clicked()
{
    m_db->updateUser(user);
}

