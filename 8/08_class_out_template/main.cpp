#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    T1 m_Name;
    T2 m_Age;

    Person(T1 name, T2 age);
    //{
    //    this->m_Name = name;
    //    this->m_Age = age;
    //}

    void show();
    //{
    //    cout << "Name is: " << this->m_Name << " " << "Age is: " << this->m_Age << endl;
    //}
};

//以下是模板类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::show()
{
    cout << "Name is: " << this->m_Name << " " << "Age is: " << this->m_Age << endl;
}

void test01()
{
    Person<string, int> person("MT", 18);
    person.show();
}


int main()
{

    test01();
    return 0;
}