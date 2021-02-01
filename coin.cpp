#include "coin.h"
#include<QTimer>


Coin::Coin(QString btnImg)
{
    QPixmap pix;
    if(!pix.load(btnImg)){
        qDebug()<<"路径加载失败";
    }
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    connect(this->timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        if(++min<=8){
            pix.load(QString(":/res/Coin000%1.png").arg(min));
            this->setFixedSize(pix.width(),pix.height());
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pix);
            this->setIconSize(QSize(pix.width(),pix.height()));
            if(min==8){
                min=1;
                timer1->stop();
                isAnimation=false;
            }
        }
    });
    connect(this->timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        if(--max>=1){
            pix.load(QString(":/res/Coin000%1.png").arg(max));
            this->setFixedSize(pix.width(),pix.height());
            this->setStyleSheet("QPushButton{border:0px;}");
            this->setIcon(pix);
            this->setIconSize(QSize(pix.width(),pix.height()));
            if(max==1){
                max=8;
                timer2->stop();
                isAnimation=false;
            }
        }
    });

}

void Coin::changeFlag()
{
    if(this->flag){//正面，执行以下代码
        timer1->start(40);
        this->flag=false;
        isAnimation=true;
    }
    else{
        timer2->start(40);
        this->flag=true;
        isAnimation=true;
    }
}

void Coin::mousePressEvent(QMouseEvent * e)
{
    if(isAnimation){
        return;
    }
    else{
        QPushButton::mousePressEvent(e);
    }
}

