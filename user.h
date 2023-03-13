#ifndef USER_H
#define USER_H

#include <QTime>

class User
{
public:
    // 性别
    enum Sex{
        Man,
        Woman
    };
    User();
    User(QString name, QString pwd);

    // Setter and Getter
    int id() const;

    QString name() const;

    QString pwd() const;
    void setPwd(const QString &newPwd);

    QTime joinTime() const;

    QString grade() const;

    QString score() const;

    int sex() const;
    void setSex(int newSex);

    int age() const;
    void setAge(int newAge);

    QDate birthday() const;
    void setBirthday(const QDate &newBirthday);

    QString mail() const;
    void setMail(const QString &newMail);

    QString getPhone() const;
    void setPhone(const QString &newPhone);

private:
    int m_id;           // 用户id
    QString m_name;     // 用户名
    QString m_pwd;      // 密码
    QTime m_joinTime;   // 注册时间
    QString m_grade;    // 会员等级
    QString m_score;    // 会员积分
    int m_sex;          // 性别
    int m_age;          // 年龄
    QDate m_birthday;   // 生日
    QString m_mail;     // 邮箱
    QString phone;      // 电话
};

class Power
{
public:
    Power();
    Power(int grade, int minScore, int discnt, int birthDiscnt, int memDiscnt);
    int grade() const;

    int minScore() const;
    void setMinScore(int newMinScore);

    int discnt() const;
    void setDiscnt(int newDiscnt);

    int birthDiscnt() const;
    void setBirthDiscnt(int newBirthDiscnt);

    int memDiscnt() const;
    void setMemDiscnt(int newMemDiscnt);

private:
    int m_grade;
    int m_minScore;
    int m_discnt;
    int m_birthDiscnt;
    int m_memDiscnt;
};

#endif // USER_H
