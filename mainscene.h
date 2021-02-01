#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"mypushbutton.h"
#include"chooselevelscene.h"
#include<QDebug>
namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    ~MainScene();

private:
    Ui::MainScene *ui;
    ChooseLevelScene * chooseLevelScene;

};

#endif // MAINSCENE_H
