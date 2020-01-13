#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");    //点击按钮，关闭窗口
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("abc");
    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /*&b1 -- 信号发出者， 指针类型
     * &QpushButton::pressed -- 处理的信号； &发送者的类名::信号名
     * this -- 信号接收者
     * &MainWidget::close -- 槽函数， 信号处理函数，  &接收者的类名::槽函数名
    */

    /*自定义槽，普通函数的用法
     * Qt5：任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号都没有返回值， 故槽函数一定没有返回值
    */

    //将b2点击后，按钮内容变为123
    connect(b2, &QPushButton::released, this, &MainWidget::mySlot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);


    setWindowTitle("Boss");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);

    //显示子窗口
    //w.show();
    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

    //处理子窗口的信号
    connect(&w, &SubWidget::mySignal, this, &MainWidget::dealSub);
    resize(400, 300);   //设置窗口大小
}

//功能：
//在主窗口按下按钮，主窗口隐藏， 子窗口显示
//在子窗口按下按钮，子窗口隐藏， 主窗口显示
//  子窗口功能 -- 发送信号，写出对应信号的槽函数即可



//子窗口响应函数
void MainWidget::dealSub(){
    //子窗口隐藏， 主窗口显示
    w.hide();
    this->show();
}

//主窗口切换函数
void MainWidget::changeWin(){
    //本窗口隐藏， 子窗口显示
    w.show();
    this->hide();
}

void MainWidget::mySlot(){
    b2->setText("123");
}

MainWidget::~MainWidget()
{
}

