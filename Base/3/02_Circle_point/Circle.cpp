#include "Circle.h"
#include "Point.h"
//添加作用域
 //设置半径
    void Circle::setR(int r)
    {
        m_r = r;
    }
    //获取半径
    int Circle::getR()
    {
        return m_r;
    }

    //设置圆心
    void Circle::setCenter(Point p)
    {
        m_Center = p;
    }
    //获取圆心
    Point Circle::getCenter()
    {
        return m_Center;
    }

    //利用成员函数来判断点和圆的关系
    void Circle::isInCircleClass(Point &p)
    {
        int distance = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());
        int rdistance = m_r * m_r;
        
        if(distance == rdistance)
        {
            cout << "成员函数：点在圆上"  << endl;
        }
        else if (distance < rdistance)
        {
            cout << "成员函数：点在圆内" << endl;
        }
        else
        {
            cout << "成员函数：点在圆外" << endl;
        }
    
    }