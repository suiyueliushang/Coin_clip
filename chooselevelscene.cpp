#include "chooselevelscene.h"
#include<QMenuBar>
#include<mypushbutton.h>
#include<QDebug>
#include<QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(320,580);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("选择关卡");

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
    connect(backButton,&QPushButton::clicked,[=](){
        emit this->chooseSceneBack();
    });

    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            MyPushButton * button =new MyPushButton(":/res/LevelIcon.png");
            button->setParent(this);
            button->move(25+j*70,i*70+130);
            QLabel *label=new QLabel();
            label->setParent(button);
            label->setFixedSize(button->width(),button->height());
            label->setText(QString::number(i*4+j+1));
            label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            connect(button,&QPushButton::clicked,[=](){
                qDebug()<<QString("xuanguan %1").arg(i*4+j+1);
                button->zoom1();
                button->zoom2();
                //创建关卡界面
                this->hide();
                playScene=new PlayScene(i*4+j+1);
                playScene->show();
                connect(playScene,&PlayScene::a,[=](){
                   this->show();
                   delete playScene;
                   playScene=NULL;
                });
            });
        }
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/PlayLevelSceneBg.png"));
    QPixmap title(":/res/Title.png");
    painter.drawPixmap((this->width()-title.width())>>1,30,title.width(),title.height(),title);
}

ChooseLevelScene::~ChooseLevelScene()
{
    qDebug()<<"choose level scene xigou";
}

