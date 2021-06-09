#include <iostream>
using namespace std;
#include <typeinfo>


template<class NameType,class AgeType> //类模板可以默认类型
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

//1.指定传入类型
void doWork(Person<string,int> & p)
{
    p.show();
}
void test01()
{
    Person<string,int> p("MT",10);
    doWork(p);
}

//2.参数模板化
template<class T1,class T2>
void doWork2(Person<T1,T2> &p)
{
    //如何查看类型
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    p.show();
}

void test02()
{
    Person<string,int> p("待贼",18);
    doWork2(p);
}

//3.整体类型化
template<class T>
void doWork3(T &p)
{
    cout << typeid(T).name() << endl;
    p.show();
}
void test03()
{
    Person<string,int> p("猎人",50);
    doWork3(p);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}