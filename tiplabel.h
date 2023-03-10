#ifndef TIPLABEL_H
#define TIPLABEL_H

#include <QLabel>

class TipLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TipLabel(QWidget *parent = nullptr);
    void showTip(QString tip, int x = 0, int y = 0);

};

#endif // TIPLABEL_H
