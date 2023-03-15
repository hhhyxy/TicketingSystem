#ifndef MEMBERMANAGER_H
#define MEMBERMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <dbhelper.h>

namespace Ui {
class MemberManager;
}

class MemberManager : public QWidget
{
    Q_OBJECT

public:
    explicit MemberManager(QWidget *parent = nullptr);
    ~MemberManager();
    void init();

private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_commit_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_insertPower_clicked();

    void on_pushButton_updatePower_clicked();

    void on_pushButton_deletePower_clicked();

    void on_pushButton_commitPower_clicked();

    void on_pushButton_cancelPower_clicked();

private:
    Ui::MemberManager *ui;
    QSqlTableModel *m_model = nullptr;
    QSqlTableModel *m_powerModel = nullptr;

    DBHelper *m_db;
};

#endif // MEMBERMANAGER_H
