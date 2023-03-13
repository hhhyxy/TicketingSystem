#include "user.h"

User::User()
{

}

User::User(QString name, QString pwd)
{
    m_name = name;
    m_pwd = pwd;
}

int User::id() const
{
    return m_id;
}

QString User::name() const
{
    return m_name;
}

QString User::pwd() const
{
    return m_pwd;
}

void User::setPwd(const QString &newPwd)
{
    m_pwd = newPwd;
}

QTime User::joinTime() const
{
    return m_joinTime;
}

QString User::grade() const
{
    return m_grade;
}

QString User::score() const
{
    return m_score;
}

int User::sex() const
{
    return m_sex;
}

void User::setSex(int newSex)
{
    m_sex = newSex;
}

int User::age() const
{
    return m_age;
}

void User::setAge(int newAge)
{
    m_age = newAge;
}

QDate User::birthday() const
{
    return m_birthday;
}

void User::setBirthday(const QDate &newBirthday)
{
    m_birthday = newBirthday;
}

QString User::mail() const
{
    return m_mail;
}

void User::setMail(const QString &newMail)
{
    m_mail = newMail;
}

QString User::getPhone() const
{
    return phone;
}

void User::setPhone(const QString &newPhone)
{
    phone = newPhone;
}


Power::Power()
{

}

Power::Power(int grade, int minScore, int discnt, int birthDiscnt, int memDiscnt)
{
    m_grade = grade;
    m_minScore = minScore;
    m_discnt = discnt;
    m_birthDiscnt = birthDiscnt;
    m_memDiscnt = memDiscnt;
}

int Power::grade() const
{
    return m_grade;
}

int Power::minScore() const
{
    return m_minScore;
}

void Power::setMinScore(int newMinScore)
{
    m_minScore = newMinScore;
}

int Power::discnt() const
{
    return m_discnt;
}

void Power::setDiscnt(int newDiscnt)
{
    m_discnt = newDiscnt;
}

int Power::birthDiscnt() const
{
    return m_birthDiscnt;
}

void Power::setBirthDiscnt(int newBirthDiscnt)
{
    m_birthDiscnt = newBirthDiscnt;
}

int Power::memDiscnt() const
{
    return m_memDiscnt;
}

void Power::setMemDiscnt(int newMemDiscnt)
{
    m_memDiscnt = newMemDiscnt;
}
