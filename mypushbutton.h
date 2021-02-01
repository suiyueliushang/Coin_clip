#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include<QMouseEvent>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QPushButton *parent = nullptr);
    MyPushButton(QString norImg,QString PressImg="");
    //动画效果
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

signals:

public slots:
    void zoom1();
    void zoom2();
private:
    QString norImg;
    QString pressImg;
};

#endif // MYPUSHBUTTON_H
