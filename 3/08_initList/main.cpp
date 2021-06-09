#include <iostream>
using namespace std;

class Person
{
public:
    //Person(){}
    //初始化数据
    /*Person(int a,int b,int c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }*/
   
    Person() :m_a(10),m_b(30),m_c(50)
    {}
    //利用初始化列表 初始化数据
    //构造函数后面 + ：属性（参数），属性（参数）...
    Person(int a,int b,int c):m_a(a),m_b(b),m_c(c)
    {}

    int m_a;
    int m_b;
    int m_c;
};

void test01()
{
    Person p1(10,20,20);
    cout << p1.m_a << " " << p1.m_b << " " << p1.m_c << endl;

    Person p2;
    cout << p2.m_a << " " << p2.m_b << " " << p2.m_c << endl;
}

int main()
{
    test01();
    return 0;
}