#include "mypushbutton.h"
#include<QPixmap>
#include<QDebug>

MyPushButton::MyPushButton(QPushButton *parent) : QPushButton(parent)
{
}

MyPushButton::MyPushButton(QString norImg, QString pressImg)
{
    this->norImg=norImg;
    this->pressImg=pressImg;
    QPixmap pixMap;
    if(!pixMap.load(norImg)){
       qDebug()<<"button norImg 加载失败";
    }
    this->setFixedSize(pixMap.width(),pixMap.height());
    //设置不规则样式
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixMap);
    this->setIconSize(QSize(pixMap.width(),pixMap.height()));
}

void MyPushButton::mousePressEvent(QMouseEvent * e)
{
    if(pressImg!=""){
        QPixmap pixMap(pressImg);
        this->setFixedSize(pixMap.width(),pixMap.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixMap);
        this->setIconSize(QSize(pixMap.width(),pixMap.height()));
    }
    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent * e)
{
    if(this->pressImg!=""){
        QPixmap pixMap(norImg);
        this->setFixedSize(pixMap.width(),pixMap.height());
        //设置不规则样式
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixMap);
        this->setIconSize(QSize(pixMap.width(),pixMap.height()));
    }
    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}

//弹跳特效
void MyPushButton::zoom1()
{
    QPropertyAnimation * animational =new QPropertyAnimation(this,"geometry");
    animational->setDuration(200);
    //设置起始位置
    animational->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置结束位置
    animational->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳曲线
    animational->setEasingCurve(QEasingCurve::OutBounce);
    animational->start();
    //设置起始位置
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animational =new QPropertyAnimation(this,"geometry");
    animational->setDuration(200);
    //设置起始位置
    animational->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置结束位置
    animational->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳曲线
    animational->setEasingCurve(QEasingCurve::OutBounce);
    animational->start();
}



