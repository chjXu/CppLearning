#include <iostream>
using namespace std;
#include <typeinfo>

template <class T>
class Base
{
public:
    T m_A;
};

//child 继承base，必须告诉Base中的类型，否则T无法分配内存
//class Child:public Base
//{
//报错，不知道类型
//};
class Child:public Base<int>
{

};

//child2也是模板类
template<class T1, class T2>
class Child2:public Base<T2>
{
public:
    T1 m_B;

    Child2()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
};

void test01()
{
    Child2<int, double> child;  //由用户指定类型
}


int main()
{
    test01();

    return 0;
}