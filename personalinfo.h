#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <QWidget>
#include "user.h"
#include "dbhelper.h"
namespace Ui {
class PersonalInfo;
}

class PersonalInfo : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalInfo(QWidget *parent = nullptr);
    ~PersonalInfo();
    void showUserInfo(User user);

private slots:
    void on_lineEdit_pwd_textChanged(const QString &arg1);


    void on_radioButton_man_clicked();

    void on_radioButton_woman_clicked();

    void on_lineEdit_age_textChanged(const QString &arg1);

    void on_dateEdit_birthday_userDateChanged(const QDate &date);

    void on_lineEdit_mail_textChanged(const QString &arg1);

    void on_lineEdit_phone_textChanged(const QString &arg1);

    void on_pushButton_save_clicked();

private:
    Ui::PersonalInfo *ui;
    User user;
    DBHelper *m_db;
};

#endif // PERSONALINFO_H
