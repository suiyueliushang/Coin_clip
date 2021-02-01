#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QTimer>
#include<QDebug>
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene),
    chooseLevelScene(new ChooseLevelScene)
{
    ui->setupUi(this);
    //配置主场景
    setFixedSize(320,580);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币主场景");
    //退出按钮
    connect(ui->actionQuit,&QAction::triggered,this,&QWidget::close);
    connect(chooseLevelScene,&ChooseLevelScene::chooseSceneBack,[=](){
        chooseLevelScene->hide();
        this->show();
    });

    //开始按钮
    MyPushButton * startButton=new MyPushButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move((this->width()-startButton->width())>>1,this->height()*0.6);
    connect(startButton,&QPushButton::clicked,[=](){
        startButton->zoom1();
        startButton->zoom2();
        //延时进入到选择关卡
        QTimer::singleShot(200,this,[=](){
            this->hide();
            chooseLevelScene->show();
        });

    });
}

void MainScene::paintEvent(QPaintEvent *)
{
       QPainter painter(this);
       painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/PlayLevelSceneBg.png"));
       //painter.drawPixmap(100,300,100,100,QPixmap(":/res/MenuSceneStartButton.png"));
       QPixmap pix(":/res/Title.png");
       pix=pix.scaled(pix.width()*0.7,pix.height()*0.7);
       painter.drawPixmap(0,0,pix);

}

MainScene::~MainScene()
{
    delete ui;
}
