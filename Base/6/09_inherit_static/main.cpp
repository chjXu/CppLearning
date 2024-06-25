#include <iostream>
using namespace std;

class Base
{
public:
    static void func()
    {
        cout << "Base func" << endl;
    }

    static void func(int a)
    {
        cout << "Base func(int)" << endl;
    }

    static int m_A; //静态变量 类内声明，类外初始化
};

int Base::m_A = 10;

class Son :public Base
{
public:
    static void func()
    {
        cout << "Son func" << endl;
    }

    static void func(int a)
    {
        cout << "Son func(int)" << endl;
    }
    static int m_A;
};

int Son::m_A = 20;

//静态成员属性可以被子类继承
void test01()
{
    cout << Son::m_A << endl;
    //想访问父类的值
    cout << Base::m_A << endl;

    Son::func();
    Base::func();

    Son::Base::func(10);    
}

int main()
{
    test01();
    
    return 0;
}