#include "mywidget.h"

#include <QApplication>
//QApplication -- QT应用程序类
//包含头文件时没有.h
//头文件和类名一样
//前两个字母大写
int main(int argc, char *argv[])
{
    //有且只有一个QApplication类的对象
    QApplication a(argc, argv);

    //MyWidget继承于Widget
    //QWidget是一个窗口基类
    //w就是一个窗口
    MyWidget w;
    //窗口创建默认隐藏，需要认为调用显示
    w.show();

    //a.exec() -- 让程序一直执行
    //等待事件发生
    return a.exec();
}
