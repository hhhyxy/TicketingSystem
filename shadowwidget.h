#ifndef SHADOWWIDGET_H
#define SHADOWWIDGET_H

#include <QWidget>

class ShadowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShadowWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    void initWidget();
private:
    int m_alphaValue = 50;//透明度
    int m_radius = 6; //默认窗口的圆角半径
    QVector<int> m_blurValue;//阴影渐变的颜色
    QColor m_shadowColor = QColor("#65666e");//阴影的颜色
    QColor m_backgroundColor = Qt::white;//窗口的背景颜色
    //能够移动窗口的属性
    bool m_lefted = false;
    QPoint m_leftPoint;

};

#endif // SHADOWWIDGET_H
