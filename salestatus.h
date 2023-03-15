#ifndef SALESTATUS_H
#define SALESTATUS_H

#include <QWidget>
#include "dbhelper.h"
namespace Ui {
class SaleStatus;
}

class SaleStatus : public QWidget
{
    Q_OBJECT

public:
    explicit SaleStatus(QWidget *parent = nullptr);
    ~SaleStatus();
    void init();

private slots:
    void on_comboBox_date_currentIndexChanged(int index);

    void on_comboBox_movie_currentIndexChanged(int index);

    void on_comboBox_period_currentIndexChanged(int index);

    void on_comboBox_type_currentIndexChanged(int index);
private:
    void clearTable();
    void loadTable(QList<QStringList> table);
private:
    Ui::SaleStatus *ui;
    DBHelper *m_db;

    int total;
};

#endif // SALESTATUS_H
