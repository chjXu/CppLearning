#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base构造函数"  << endl;
    }
    ~Base()
    {
        cout << "Base析构函数" << endl;
    }

};

class Son :public Base
{
public:
    Son()
    {
        cout << "Son构造函数"  << endl;
    }
    ~Son()
    {
        cout << "Son析构函数" << endl;
    }
    
};

//子类可以继承父类的成员变量和函数
//但是，无法继承父类的构造函数和析构函数

void test01()
{
    //Base b1;

    Son s1;
}

int main()
{
    test01();
    
    return 0;
}