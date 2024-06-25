#include <iostream>
using namespace std;
#include "Point.h"
#include "Circle.h"
//判断圆与点的关系，在圆上、在圆内、在圆外
//公式：r = sqrt{(x1-x)^2 + (y1-y)^2)

//.h文件写成员函数的声明
//.cpp文件写成员函数的实现

//先利用全局函数进行判断
void isInCircle(Circle &c,Point &p)
{
    //获取圆心和点的距离 的平方
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    int rdistance = c.getR() * c.getR();

    if(distance == rdistance)
    {
        cout << "点在圆上"  << endl;
    }
    else if (distance < rdistance)
    {
        cout << "点在圆内" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }
    
    
}


void test01()
{
   Point p1;
   p1.setX(10);
   p1.setY(9);
   Circle c1;
   Point center;
   center.setX(10);
   center.setY(0);
   c1.setCenter(center);
   c1.setR(10);

    //利用全局函数
   isInCircle(c1,p1);
    //利用成员函数
    c1.isInCircleClass(p1);

}

int main()
{
    test01();
    return 0;
}