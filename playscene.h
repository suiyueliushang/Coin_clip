#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPainter>
#include "dataconfig.h"
#include "coin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levleNum);
    void paintEvent(QPaintEvent *);
signals:
    void a();
    void win();
public slots:

private:
    int levelNum;
    DataConfig data;
    int gameArray[16];
    Coin** coinArray;
    bool victory;
};

#endif // PLAYSCENE_H
