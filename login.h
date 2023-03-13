#ifndef LOGIN_H
#define LOGIN_H

#include <shadowwidget.h>
#include <QParallelAnimationGroup>
#include "dbhelper.h"
#include "http.h"

namespace Ui {
class Login;
}

class Login : public ShadowWidget
{
    Q_OBJECT

public:
    enum AnimType {
        LEFT,
        RIGHT
    };
    explicit Login(QWidget *parent = nullptr);
    void showThisTip(QString tip, int y = 250);
    ~Login();
signals:
    void loginSuccess(User user);
    void touristVisit();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_signIn_clicked();
    void on_pushButton_min_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_register_return_clicked();
    void on_pushButton_register_signIn_clicked();
    void on_pushButton_tourist_clicked();

private:
    Ui::Login *ui;
    DBHelper *m_db;
    Http http;

};

#endif // LOGIN_H
