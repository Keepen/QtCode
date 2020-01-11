#include<QApplication>
#include <QWidget> //窗口控件基类
#include <QPushButton>
int main(int argc, char** argv){
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("WZ");   //设置窗口的标题


    QPushButton b;
    b.setText("^_^");   //给按钮设定内容
    /*如果不指定父对象，默认各对象（窗口）之间没有联系，各自独立
     * 若b是a的父对象，则a在b上面
     * 指定父对象，2种方式：
     *          1）setParent
     *          2)通过构造函数传参
     * 指定父对象后，只需要调用父对象的显示函数，则其子类均会显示
    */
    //1.通过setParent函数指定父对象
    b.setParent(&w);    //为b设置父对象
    b.move(100,100);    //移动坐标

    //2.通过构造函数传参指定父对象
    QPushButton b1(&w);
    b1.setText("abc");
    w.show();
    app.exec();
    return 0;
}

