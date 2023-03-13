#ifndef DBHELPER_H
#define DBHELPER_H
#include <QObject>
#include <QSqlDatabase>

class DBHelper : public QObject
{
    Q_OBJECT
public:
    explicit DBHelper(QObject *parent = nullptr);
    void open();
    void insert();
    void query();
    void remove();
    void close();
signals:
private:
    QSqlDatabase m_db;
};

#endif // DBHELPER_H
