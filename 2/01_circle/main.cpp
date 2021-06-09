#include <iostream>
using namespace std;

const double pi = 3.14;//const 代替 define

//设计一个类
//周长公式：l = 2*PI*r
class Circle{
    public: //公共权限
    //定义成员函数
    double calculateZC()
    {
        return 2 * pi * m_R;
    }
    //也可以设置半径定义的函数
    void setR(int r)
    {
        m_R = r;
    }
    //半径   属性
    int m_R;
};

void test01(){
    //通过类来定义一个圆
    Circle c1; //对象
    //c1.m_R = 5;
    //调用类中的半径定义函数
    c1.setR(10);
    cout << "c1的周长是：  "<< c1.calculateZC() << endl;
}

int main(){

    test01();

    return 0;
}
