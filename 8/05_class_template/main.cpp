#include <iostream>
using namespace std;

template<class NameType,class AgeType = int> //类模板可以默认类型
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void show()
    {
        cout << this->m_Name << endl;
        cout << this->m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    //类模板不支持 自动类型推导
    //Person p("孙悟空",100);

    //显示指定类型
    Person<string,int> p("孙悟空",100);
    p.show();
}

class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1的调用" << endl;
    } 
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2的调用" << endl;
    } 
};

template<class T>
class myClass
{
public:
    T obj;
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }
};
//成员函数 一开始不会创建出来，而是在运行的时候才去创建


void test02()
{
    myClass <Person1> m;
    m.func1();
    //m.func2(); //不能这样调用
}

int main()
{
    //test01();
    test02();
    return 0;
}