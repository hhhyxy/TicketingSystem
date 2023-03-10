#include "shadowwidget.h"
#include <qmath.h>
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>

ShadowWidget::ShadowWidget(QWidget *parent)
    : QWidget{parent}
{
    initWidget();
}

void ShadowWidget::initWidget()
{
    //TODO: 设置默认窗口大小
    resize(400,400);

    //TODO: 设置窗口无边框/背景透明属性
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);//无边框的窗口
    setAttribute(Qt::WA_TranslucentBackground,true);//实现圆角的无边框窗口必须设置的属性

    //TODO: 初始化阴影的渐变值
    qreal factor = m_alphaValue / m_radius;
    for (int i = 0; i < m_radius; i++)
    {
        int level = (int)(m_alphaValue - qSqrt(i) * factor + 0.5);
        m_blurValue.push_back(qMax<int>(0, level - 2));
    }
}

void ShadowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    //TODO: 先填充背景，原来是透明的，用背景颜色进行填充
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRoundedRect(m_radius, m_radius, width() - m_radius * 2,
                        height() - m_radius * 2, m_radius, m_radius);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(m_backgroundColor));

    //TODO: 再绘制圆角矩形path，利用渐变的颜色。
    auto color = m_shadowColor;
    for (int i = 0; i < m_radius; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRoundedRect(m_radius - i, m_radius - i, width() - (m_radius - i) * 2,
                            height() - (m_radius - i) * 2, m_radius, m_radius);

        int alpha = 0;
        if (i < m_blurValue.size())
        {
            alpha = m_blurValue[i];
        }
        color.setAlpha(alpha);
        painter.setPen(color);
        painter.drawPath(path);
    }

}

void ShadowWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_lefted)
    {
        //TODO: 鼠标移动时计算 （当前鼠标的位置- 按下鼠标位置的差= 窗口移动的距离)
        QPoint offset = event->pos() - m_leftPoint;
        move(offset + pos());
    }
}

void ShadowWidget::mousePressEvent(QMouseEvent *event)
{
    this->setFocus(Qt::MouseFocusReason);
    if (event->button() == Qt::LeftButton)
    {
        //TODO: 记录鼠标按下时的位置(QPoint)
        m_lefted = true;
        m_leftPoint = event->pos();
    }
}

void ShadowWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //TODO: 鼠标释放时重置下记录的数据
        m_lefted = false;
        m_leftPoint.setX(0);
        m_leftPoint.setY(0);
    }
}


