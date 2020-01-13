#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"      //子窗口的头文件
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void mySlot();
    void changeWin();   //响应主窗口的操作
    void dealSub();     //处理子窗口的信号
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidget w;
};
#endif // MAINWIDGET_H
