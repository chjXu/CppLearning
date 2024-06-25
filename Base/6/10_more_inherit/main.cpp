#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        m_A = 10;
        m_E = 100;
    }

    int m_A;
    int m_E;
};

class Base2
{
public:
    Base2()
    {
        m_B = 20;
        m_E = 50;
    }

    int m_B;
    int m_E;
};

//多继承
class Son :public Base1,public Base2
{
public:
    int m_C;
    int m_D;
};


void test01()
{
    cout << sizeof(Son) << endl;
    Son s1;
    cout << s1.m_A << endl;

    //如果2个基类有同名的成员,要加上作用域
    cout << s1.Base1::m_E << endl;
}

int main()
{
    test01();
    
    return 0;
}