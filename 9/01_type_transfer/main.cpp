#include <iostream>
using namespace std;

//1.静态转换
//基础类型
void test01()
{
    char a='a';

    double d = static_cast<double>(a);
    cout << d << endl;
}

//2.父子之间转换
class Base
{

};

class Child:public Base
{

};

class Other
{

};

void test02()
{
    Base *base = NULL;
    Child *child = NULL;

    //把Base转为Child，向下不安全
    Child *child2 = static_cast<Child*>(base);

    //把child转为base，向上安全
    Base *base2 = static_cast<Base*>(child);

    //转other
    //转换无效，非父子关系
    //Other *other = static_cast<Other*>(Base);
}


//3.动态转换
void test03()
{
    //基础类型不能转化
    char c = 'b';
    //dynamic_cast非常严格，失去精度 或不安全的都不可以转换
    //double d = dynamic_cast<double>(c);

    //cout << d << endl;
}

class Base2{
    virtual void func(){};
};
class Child2:public Base2{
    virtual void func(){};
};
class Other2{};

void test04()
{
    Base2 *base = NULL;
    Child2 *child = NULL;

    //把child转为base，向上安全
    Base2 * base2 = dynamic_cast<Base2*>(child);

    //把Base转为Child，向下不安全
    //Child2 *child2 = dynamic_cast<Child2*>(base);

    //发生了多态,安全
    Base2 *base3 = new Child2;
    Child2* child3 = dynamic_cast<Child2*>(base3);
}
//dynamic_cast如果发生了多态，那么基类可以转为派生类，安全



//4.常量转换（const_cast）
void test05()
{
    const int *p = NULL;
    int *newP = const_cast<int *>(p);

    int *p2 = NULL;
    const int *newp2 = const_cast<const int *>(p2);

    //不能对非指针 或 非引用的 变量进行变换
    //const int a = 10;
    //int b = const_cast<int>(a);
}

int main()
{
    test01();
    test02();

    return 0;
}