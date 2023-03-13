#ifndef TICKETINGSYSTEM_H
#define TICKETINGSYSTEM_H

#include "shadowwidget.h"

namespace Ui {
class TicketingSystem;
}

class TicketingSystem : public ShadowWidget
{
    Q_OBJECT

public:
    explicit TicketingSystem(QWidget *parent = nullptr);
    ~TicketingSystem();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_min_clicked();

private:
    Ui::TicketingSystem *ui;
};

#endif // TICKETINGSYSTEM_H
