#ifndef LOGIN_H
#define LOGIN_H

#include "tiplabel.h"
#include <shadowwidget.h>
#include <QParallelAnimationGroup>

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
    ~Login();
signals:
    void signIn();
private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_signIn_clicked();
    void on_pushButton_min_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_register_return_clicked();

    void on_pushButton_register_signIn_clicked();

private:
    void showTip(QString tip, int x = 0, int y = 230);
    void turnAnimation(int animType = AnimType::RIGHT);
private:
    Ui::Login *ui;

    TipLabel *tipLabel = nullptr;
    QLabel *leftLabel = nullptr;
    QLabel *rightLabel = nullptr;
    QParallelAnimationGroup *group = nullptr;
};

#endif // LOGIN_H
