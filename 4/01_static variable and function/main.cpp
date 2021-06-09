#include <iostream>
using namespace std;

class Person
{
private:
   static int m_other;//类外不能访问

   static void func2()
   {
       cout << "func2的调用" << endl;
   }
public:
   Person()
   {
       //m_Age = 10;//不建议在类中初始化
   }
    static int m_Age; //加入static就是 静态成员变量，会共享数据
    //静态成员变量，在类中声明，类外进行初始化 原因是：如果不通过对象访问的话，是不会执行构造函数中的初始化

    int m_a;
    //静态函数
    //不能访问 普通成员变量
    static void func()
    {   
        //m_a = 10;
        cout << "func的调用" << endl;
    }
    //普通成员函数，可以访问普通成员函数，也可以访问静态成员函数
    void myFunc()
    {
        m_a = 100;
        m_Age = 1000;
    }
};


int Person::m_Age = 0;//类外初始化
//int Person::m_other;

void test01()
{
    //1.通过对象访问属性
    Person p1;
    p1.m_Age = 10;
    Person p2;
    p2.m_Age = 20;

    //共享数据 都为20
    cout << "p1 = " << p1.m_Age << endl;
    cout << "p2 = " << p2.m_Age << endl;

    //2.通过类名访问
    cout << "通过类名访问" << Person::m_Age << endl;

    //静态函数
    p1.func();
    Person::func();

    //静态成员函数 也是有权限的
    //Person::func2(); //无法访问
    p1.myFunc();
    cout << "m_a = " << p1.m_a << endl;
    cout << "m_Age = " << p1.m_Age << endl;
}

int main()
{
    test01();
    return 0;
}