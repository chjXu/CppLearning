#include <iostream>
using namespace std;
#include <string>

//4.让编译器看到Person声明
template <class T1, class T2> class Person;
//3.必须让编译器提前看到声明
template <class T1, class T2>void printPerson(Person<T1, T2> &p);


template <class T1, class T2>
class Person
{
    //友元函数类外实现 //2.利用空参数列表(加上<>)， 告诉编译器 模板函数的声明,否则为普通函数
    friend void printPerson<>(Person<T1, T2> &p); //普通函数
    //{
    //    cout << "Name is: " << p.m_Name << " " << "Age is: " << p.m_Age << endl;
    //}
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

//1.类外实现
template<class T1, class T2>
void printPerson(Person<T1, T2> &p)
{
    cout << "Name is: " << p.m_Name << " " << "Age is: " << p.m_Age << endl;
}

void test01()
{
    Person<string, int> p("Tom", 20);
    printPerson(p);
}


int main()
{

    test01();
    return 0;
}