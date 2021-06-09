#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A = 100;
        //cout << "Base构造函数"  << endl;
    }

    void func()
    {
        cout << "Base func" << endl;
    }

    ~Base()
    {
        //cout << "Base析构函数" << endl;
    }

    int m_A;
};

class Son :public Base
{
public:
    Son()
    {
        m_A = 200;
        //cout << "Son构造函数"  << endl;
    }

    void func()
    {
        cout << "Son func" << endl;
    }

    ~Son()
    {
        //cout << "Son析构函数" << endl;
    }
    int m_A;
};

//如果子类和父类拥有同名的函数 属性，子类会覆盖父类的成员吗？ 不会
//如果子类与父类的成员函数名称相同，子类会把父类所有的同名版本都隐藏掉
//想调用父类的方法，必须加作用域

void test01()
{
    //Base b1;

    Son s1;
    cout << s1.m_A << endl;
    //想调用父类中的 m_A
    cout << s1.Base::m_A << endl;

    s1.func();
    s1.Base::func();
}

int main()
{
    test01();
    
    return 0;
}