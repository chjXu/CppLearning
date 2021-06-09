#include <iostream>
using namespace std;

class MyClass
{
private:
    /* data */
public:
    //MyClass()
    //{
    //    cout << "默认构造函数" << endl;
    //}

    MyClass(int a)
    {
        cout << "有参构造函数" << endl;
    }

    //MyClass(const MyClass& m)
    //{
//
    //}

    ~MyClass()
    {
        cout << "默认析构函数" << endl;
    }

    int m_A;
};

//系统默认给一个类提供3个函数 默认构造、拷贝函数、析构函数

//1.当我们提供有参的构造函数，那么系统就不会提供默认的构造函数了
//但是，系统还会提供默认的拷贝构造函数
void test01()
{
    MyClass c1(1);
    c1.m_A = 10;
    MyClass c2(c1);

    cout << c2.m_A << endl;
}

//2.当我们提供了 拷贝构造，那么析构就不会提供其他构造了
class MyClass2
{
    public:
    //MyClass2()
    //{
    //    cout << "默认构造函数" << endl;
    //}

    //MyClass2(int a)
    //{
    //    cout << "有参构造函数" << endl;
    //}

    MyClass2(const MyClass2& m)
    {

    }

    ~MyClass2()
    {
        cout << "默认析构函数" << endl;
    }

    int m_A;
};

void test02()
{
    //MyClass2 c1;

}

int main()
{
    test01();
    return 0;
}