#include <iostream>
using namespace std;
#include <string>

template <class T1, class T2>
class Person
{
    //友元函数类内实现
    friend void printPerson(Person<T1, T2> &p)
    {
        cout << "Name is: " << p.m_Name << " " << "Age is: " << p.m_Age << endl;
    }
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