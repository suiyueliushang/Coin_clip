#ifndef COIN_H
#define COIN_H

#include <QWidget>
#include <QPushButton>
#include<QDebug>
#include<QTimer>
#include<QPixmap>
#include<QMouseEvent>
class Coin : public QPushButton
{
    Q_OBJECT
public:
    Coin(QString btnImg);//参数代表金币路径还是银币路径
    void changeFlag();//改变标志，执行翻转效果
    void mousePressEvent(QMouseEvent*);//重写按下事件

    int Posx,PosY;
    bool flag;
signals:

public slots:
private:
    QTimer *timer1;//正面翻反面 定时器
    QTimer *timer2;//反面翻正面 定时器
    int min=1;
    int max=8;
    bool isAnimation=false;
};

#endif // COIN_H
