#include "dbhelper.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DBHelper *DBHelper::instance = new DBHelper();

DBHelper *DBHelper::getInstance()
{
    return instance;
}

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
    if (m_db.isOpen()) {
        return;
    }
    if (!m_db.open()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Failed to connect database." << m_db.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Succeed to connect database." ;
    }

    // 建立 movie 表
    QSqlQuery query(m_db);
    QString createSql = "CREATE TABLE IF NOT EXISTS movie ("
                        "m_id INTEGER NOT NULL,"
                        "m_name TEXT,"
                        "picture TEXT,"
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

    // 建立 place 表
    createSql = "CREATE TABLE IF NOT EXISTS place ("
                "p_id INTEGER NOT NULL,"
                "p_name TEXT"
                "m_id INTEGER,"
                "date DATE,"
                "price NUMBER,"
                "start_time DATE,"
                "end_time DATE,"
                "max_row TEXT,"
                "max_column TEXT,"
                "seat BLOB,"
                "PRIMARY KEY (p_id)"
              ");";
    query.prepare(createSql);
    if(!query.exec()) {
        qDebug() << __FILE__ << __LINE__ << "Error: Fail to create table." << query.lastError();
    } else {
        qDebug() << __FILE__ << __LINE__ << "Table created!";
    }
    query.clear();

    // 建立 power 表
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

    // 建立 ticket 表
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

    // 建立 user 表
    createSql = "CREATE TABLE IF NOT EXISTS user ("
                "u_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                "u_time DATE,"
                "u_name TEXT,"
                "password TEXT,"
                "grade TEXT,"
                "score TEXT,"
                "mail TEXT,"
                "phone TEXT,"
                "sex INTEGER,"
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

}

// 根据用户名查询用户
User DBHelper::queryUser(QString &name)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("SELECT u_id, u_time, password, grade, score, mail, phone, sex, age, birthday FROM user WHERE u_name = :u_name;");
    movieQuery.bindValue(":u_name", name);
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "query error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "query success!";
    }
    User user;
    if (movieQuery.next()) {
        int id = movieQuery.value(0).toInt();
        QDateTime time = movieQuery.value(1).toDateTime();
        QString pwd = movieQuery.value(2).toString();
        int grade = movieQuery.value(3).toInt();
        int score = movieQuery.value(4).toInt();
        QString mail = movieQuery.value(5).toString();
        QString phone = movieQuery.value(6).toString();
        int sex = movieQuery.value(7).toInt();
        int age = movieQuery.value(8).toInt();
        QDate birthday = movieQuery.value(9).toDate();
        user = User(id, name, pwd, time, grade, score, sex, age, birthday, mail, phone);
    }
    return user;
}

// 插入用户
void DBHelper::insertUser(User user)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("INSERT INTO user (u_time, u_name, password, grade, score, mail, phone, sex, age, birthday) VALUES (:u_time, :u_name, :password, :grade, :score, :mail, :phone, :sex, :age, :birthday)");
    movieQuery.bindValue(":u_time", user.joinTime());
    movieQuery.bindValue(":u_name", user.name());
    movieQuery.bindValue(":password", user.pwd());
    movieQuery.bindValue(":grade", user.grade());
    movieQuery.bindValue(":score", user.score());
    movieQuery.bindValue(":mail", user.mail());
    movieQuery.bindValue(":phone", user.phone());
    movieQuery.bindValue(":sex", user.sex());
    movieQuery.bindValue(":age", user.age());
    movieQuery.bindValue(":birthday", user.birthday());
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "insert error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "insert success!";
    }
}

// 查询电影列表（电影id，名称，海报）
QList<Movie> DBHelper::queryAllMovie()
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("SELECT m_id, m_name, picture FROM movie;");
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "query error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "query success!";
    }
    QList<Movie> movieList;
    while (movieQuery.next()) {
        int id = movieQuery.value(0).toInt();
        QString name = movieQuery.value(1).toString();
        QString picture = movieQuery.value(2).toString();
        movieList.push_back(Movie(id, name, picture));
    }
    return movieList;
}

// 插入电影
void DBHelper::insertMovie(Movie movie)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("INSERT INTO movie(m_id, m_name, picture, introduce, directors, actors, durations, type) VALUES (:m_id, :m_name, :picture, :introduce, :directors, :actors, :durations, :type)");
    movieQuery.bindValue(":m_id", movie.id());
    movieQuery.bindValue(":m_name", movie.name());
    movieQuery.bindValue(":picture", movie.picture());
    movieQuery.bindValue(":introduce", movie.introduce());
    movieQuery.bindValue(":picture", movie.picture());
    movieQuery.bindValue(":directors", movie.dirtectors());
    movieQuery.bindValue(":actors", movie.actors());
    movieQuery.bindValue(":durations", movie.duration());
    movieQuery.bindValue(":type", movie.type());
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "insert error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "insert success!";
    }
}

// 查询电影详情
Movie DBHelper::queryMovie(int id)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("SELECT m_name, introduce, picture, directors, actors, durations, type FROM movie WHERE m_id = :m_id;");
    movieQuery.bindValue(":m_id", id);
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "query error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "query success!";
    }
    Movie movie;
    if (movieQuery.next()) {
        QString name = movieQuery.value(0).toString();
        QString introduce = movieQuery.value(1).toString();
        QString picture = movieQuery.value(2).toString();
        QString directors = movieQuery.value(3).toString();
        QString actors = movieQuery.value(4).toString();
        QString durations = movieQuery.value(5).toString();
        QString type = movieQuery.value(6).toString();
        movie = Movie(id, name, introduce, picture, directors, actors, durations, type);
    }
    return movie;
}

// 查询指定电影的场次信息
Place DBHelper::queryPlace(int id)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("SELECT p_id, p_name, date, price, start_time, end_time, max_row, max_column, seat FROM place WHERE m_id = :m_id;");
    movieQuery.bindValue(":m_id", id);
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "query error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "query success!";
    }
    Place place;
    if (movieQuery.next()) {
        int p_id = movieQuery.value(0).toInt();
        QString name = movieQuery.value(1).toString();
        QDate date = movieQuery.value(2).toDate();
        int price = movieQuery.value(3).toInt();
        QTime startTime = movieQuery.value(4).toTime();
        QTime endTime = movieQuery.value(5).toTime();
        int maxRow = movieQuery.value(6).toInt();
        int maxCol = movieQuery.value(7).toInt();
        QBitArray seat = movieQuery.value(8).toBitArray();
        place = Place(p_id, name, id, date, price, startTime, endTime, maxRow, maxCol, seat);
    }
    return place;
}

// 更新场次信息
void DBHelper::updatePlace(Place &place)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("UPDATE place SET p_name = :p_name, m_id = :m_id, date = :date, price = :price, start_time = :start_time, end_time = :end_time, max_row = :max_row, max_column = :max_column, seat = :seat WHERE p_id = :p_id");
    movieQuery.bindValue(":p_name", place.name());
    movieQuery.bindValue(":m_id", place.movieId());
    movieQuery.bindValue(":date", place.getDate());
    movieQuery.bindValue(":price", place.price());
    movieQuery.bindValue(":start_time", place.startTime());
    movieQuery.bindValue(":end_time", place.endTime());
    movieQuery.bindValue(":max_row", place.maxRow());
    movieQuery.bindValue(":max_column", place.maxCol());
    movieQuery.bindValue(":seat", place.seat());
    movieQuery.bindValue(":p_id", place.id());
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "update error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "update success!";
    }
}

// 插入电影票
void DBHelper::insertTicket(Ticket &ticket)
{
    QSqlQuery movieQuery(m_db);
    movieQuery.prepare("INSERT INTO ticket (u_id, m_id, p_id, t_time, row, column) VALUES (:u_id, :m_id, p_id, :t_time, :row, :column)");

    movieQuery.bindValue(":u_id", ticket.userId());
    movieQuery.bindValue(":m_id", ticket.movieId());
    movieQuery.bindValue(":p_id", ticket.placeId());
    movieQuery.bindValue(":t_time", ticket.time());
    movieQuery.bindValue(":row", ticket.row());
    movieQuery.bindValue(":column", ticket.col());
    if(!movieQuery.exec()) {
        qDebug() << __FILE__ << __LINE__ << "insert error: " << movieQuery.lastError();
    }
    else {
        qDebug() << __FILE__ << __LINE__ << "insert success!";
    }
}

// 关闭数据库
void DBHelper::close()
{
    if (m_db.isOpen()) {
        m_db.close();
        qDebug() << __FILE__ << __LINE__ << "database closed";
    }
}
