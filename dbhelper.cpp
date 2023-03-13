#include "dbhelper.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DBHelper::DBHelper(QObject *parent)
    : QObject{parent}
{

}

// 打开数据库，并初始化表
void DBHelper::open()
{
    //"qt_sql_default_connection"
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        m_db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("TicketingSystem.db");
    }
    if (!m_db.open()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Failed to connect database." << m_db.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Succeed to connect database." ;
    }

    QSqlQuery query(m_db);
    QString createSql = "CREATE TABLE IF NOT EXISTS movie ("
                        "m_id INTEGER NOT NULL,"
                        "m_name TEXT,"
                        "introduce TEXT,"
                        "directors TEXT,"
                        "actors TEXT,"
                        "durations TEXT,"
                        "type TEXT,"
                        "PRIMARY KEY ('m_id')"
                        ");";
    query.prepare(createSql);
    if(!query.exec()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Fail to create table." << query.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Table created!";
    }
    query.clear();

    createSql = "CREATE TABLE IF NOT EXISTS place ("
                "p_id INTEGER NOT NULL,"
                "m_id INTEGER,"
                "date DATE,"
                "price NUMBER,"
                "start_time DATE,"
                "end_time DATE,"
                "max_row TEXT,"
                "max_column TEXT,"
                "PRIMARY KEY ('p_id')"
              ");";
    query.prepare(createSql);
    if(!query.exec()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Fail to create table." << query.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Table created!";
    }
    query.clear();

    createSql = "CREATE TABLE IF NOT EXISTS power ("
                "grade INTEGER NOT NULL,"
                "min_score INTEGER,"
                "discount INTEGER,"
                "birthday_discount INTEGER,"
                "member_discount INTEGER,"
                "PRIMARY KEY (grade)"
              ");";
    query.prepare(createSql);
    if(!query.exec()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Fail to create table." << query.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Table created!";
    }
    query.clear();

    createSql = "CREATE TABLE IF NOT EXISTS ticket ("
                "t_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                "u_id INTEGER,"
                "m_id INTEGER,"
                "p_id INTEGER,"
                "t_time DATE,"
                "row TEXT,"
                "column TEXT"
              ");";
    query.prepare(createSql);
    if(!query.exec()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Fail to create table." << query.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Table created!";
    }
    query.clear();

    createSql = "CREATE TABLE IF NOT EXISTS user ("
                "u_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                "u_time DATE,"
                "u_name TEXT,"
                "password TEXT,"
                "grade TEXT,"
                "score TEXT,"
                "mail TEXT,"
                "phone TEXT,"
                "sex blob,"
                "age INTEGER,"
                "birthday TEXT"
              ");";
    query.prepare(createSql);
    if(!query.exec()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Fail to create table." << query.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Table created!";
    }
    query.clear();
    m_db.close();
}

// 关闭数据库
void DBHelper::close()
{
    if (m_db.isOpen())
        m_db.close();
}
