#ifndef TICKETINGSYSTEM_H
#define TICKETINGSYSTEM_H

#include "shadowwidget.h"
#include "dbhelper.h"

namespace Ui {
class TicketingSystem;
}

class TicketingSystem : public ShadowWidget
{
    Q_OBJECT

public:
    explicit TicketingSystem(QWidget *parent = nullptr);
    void login();
    ~TicketingSystem();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_movies_clicked();

    void on_pushButton_personalInfo_clicked();

    void on_pushButton_movieManager_clicked();

    void on_pushButton_memManager_clicked();

    void on_pushButton_sales_clicked();

private:
    Ui::TicketingSystem *ui;
    DBHelper *m_db;
};

#endif // TICKETINGSYSTEM_H
