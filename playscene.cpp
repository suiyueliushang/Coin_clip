#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include "mypushbutton.h"
#include <QLabel>
#include <QFont>
#include <QTimer>
#include <QPixmap>
#include<QPropertyAnimation>
PlayScene::PlayScene(QWidget *parent) :
    QMainWindow(parent)
{

}

PlayScene::PlayScene(int levelNum):
    data(new DataConfig)
{
    this->levelNum=levelNum;
    //gameArray赋值
    for(int i=0;i<16;i++)
        gameArray[i]=data.mdata[(levelNum-1)*16+i];

    coinArray=new Coin*[16];
    victory=false;

    setFixedSize(320,580);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币场景");

    //创建菜单栏
    QMenuBar * menuBar=new QMenuBar();
    setMenuBar(menuBar);
    QMenu * startMenu=menuBar->addMenu("开始");
    QAction* quit_action=startMenu->addAction("退出");
    connect(quit_action,&QAction::triggered,this,&QWidget::close);

    //返回按钮
    MyPushButton* backButton=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backButton->setParent(this);
    backButton->move(this->width()-backButton->width(),this->height()-backButton->height());

    //点击返回
    connect(backButton,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(200,this,[=](){
            emit this->a();
        });
    });


    QLabel * label =new QLabel(this);
    label->setText(QString("Level %1").arg(this->levelNum));
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(30);
    label->setFont(font);
    label->setFixedSize(150,30);
    label->move(0,550);
    label->setAlignment(Qt::AlignHCenter);

    //显示金币背景图
    QPixmap pix(":/res/BoardNode.png");
    for(int i=0;i<16;i++){
        QLabel *label=new QLabel(this);
        label->setFixedSize(pix.width(),pix.height());
        label->move(45+i%4*50,180+(i/4)*50);
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        QString str;
        if(gameArray[i]==1)
            str=":/res/Coin0001.png";
        else
            str=":/res/Coin0008.png";
        Coin *coin =new Coin(str);
        coinArray[i]=coin;
        coin->setParent(label);
        coin->move(3,3);
        coin->Posx=i/4;
        coin->PosY=i%4;
        coin->flag=gameArray[i];
        connect(coin,&QPushButton::clicked,coin,[=](){
//            qDebug()<<QString("%1 %2").arg(coin->Posx).arg(coin->PosY);
            coin->changeFlag();
            this->gameArray[coin->Posx*4+coin->PosY]=!this->gameArray[coin->Posx*4+coin->PosY];

            QTimer::singleShot(300,this,[=](){
                //翻上
                if(coin->Posx-1>=0){
                    int a=(coin->Posx-1)*4+coin->PosY;
                   coinArray[a]->changeFlag();
                   this->gameArray[a]=!this->gameArray[a];
                }
                //翻下
                if(coin->Posx+1<=3){
                    int a=(coin->Posx+1)*4+coin->PosY;
                    coinArray[a]->changeFlag();
                    this->gameArray[a]=!this->gameArray[a];
                }
                //翻左
                if(coin->PosY-1>=0){
                    int a=coin->Posx*4+coin->PosY-1;
                    coinArray[a]->changeFlag();
                    this->gameArray[a]=!this->gameArray[a];
                }
                //翻右
                if(coin->PosY+1<=3){
                    int a=coin->Posx*4+coin->PosY+1;
                    coinArray[a]->changeFlag();
                    this->gameArray[a]=!this->gameArray[a];
                }
                for(int j=0;j<16;j+=4)
                    qDebug()<<QString("%1 %2 %3 %4").arg(gameArray[j]).arg(gameArray[j+1]).arg(gameArray[j+2]).arg(gameArray[j+3]);
                int j=0;
                for(;j<16&& gameArray[j];j++);
                    //qDebug()<<QString("%1").arg(j);
                if(j==16){
                    emit this->win();
                    qDebug()<<"win!!!!!!!!!!";

                }

//                QPropertyAnimation *animation =new QPropertyAnimation(label,"geometry");
//                animation->setDuration(1000);
//                animation->setStartValue(QRect(label->x(),label->y(),label->width(),label->height()));
//                animation->setEndValue(QRect(label->x(),label->y()+114,label->width(),label->height()));
//                animation->setEasingCurve(QEasingCurve::OutBounce);
//                animation->start();
            });

//            QTimer::singleShot(400,this,[=](){
//                for(int j=0;j<16;j+=4)
//                    qDebug()<<QString("%1 %2 %3 %4").arg(gameArray[j]).arg(gameArray[j+1]).arg(gameArray[j+2]).arg(gameArray[j+3]);


//            });
        });
        connect(this,&PlayScene::win,coin,[=](){
            coin->setEnabled(false);
        });
    }

    //胜利后显示
    connect(this,&PlayScene::win,[=](){
        QLabel* label=new QLabel(this);
        QPixmap *tmpPix=new QPixmap(":/res/LevelCompletedDialogBg.png");
        label->setFixedSize(tmpPix->width(),tmpPix->height());
        label->setPixmap(*tmpPix);
        label->move(50,100);
    });
}

void PlayScene::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/OtherSceneBg.png"));
}
