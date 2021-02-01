#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include<QPainter>
#include<playscene.h>
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* );
    ~ChooseLevelScene();
signals:
    void chooseSceneBack();
public slots:
private:
    PlayScene * playScene=NULL;
};

#endif // CHOOSELEVELSCENE_H
