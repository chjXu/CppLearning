#pragma once
#include <iostream>
using namespace std;

class Circle
{
public:
    //设置半径
    void setR(int r);
    /*{
        m_r = r;
    }*/
    //获取半径
    int getR();
    /*{
        return m_r;
    }*/

    //设置圆心
    void setCenter(Point p);
    /*{
        m_Center = p;
    }*/
    //获取圆心
    Point getCenter();
    /*{
        return m_Center;
    }*/

    //利用成员函数来判断点和圆的关系
    void isInCircleClass(Point &p);
    /*{
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
    
    }*/
private:
    int m_r;//半径
    Point m_Center;//圆心
};