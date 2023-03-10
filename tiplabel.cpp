#include "tiplabel.h"
#include <QTimer>
TipLabel::TipLabel(QWidget *parent)
    : QLabel{parent}
{
    // 设置样式
    this->setStyleSheet("QLabel{color:blue;background:transparent;}");
    // 垂直、水平中心对齐
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    // 与父窗口宽度相同
    this->setFixedWidth(parent->width());
}

void TipLabel::showTip(QString tip, int x, int y)
{
    // 显示提示，两秒后消失
    this->move(x, y);
    this->setText(tip);
    this->show();
    QTimer::singleShot(2000, this, &TipLabel::hide);
}
