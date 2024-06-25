#include <iostream>
using namespace std;
#include "myarray.hpp"
#include <string>

//cout int
void printArray(MyArray<int>& array)
{
    for(int i=0;i<array.getSize();i++)
    {
        cout << array[i] << endl;
    }
}


class Person
{
public:
    Person(){} //不写，会报错！！！！

    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//cout person
void printPerson(MyArray<Person>& array)
{
    for(int i=0;i<array.getSize(); i++)
    {
        cout << "Name is: " << array[i].m_Name << "  " << "Age is: " << array[i].m_Age << endl;
    }
}





int main()
{
    MyArray<int> arr(10);
    for(int i=0; i<10;i++)
    {
        arr.push_back(i+100);
    }
    printArray(arr);


    Person p1("A", 10);
    Person p2("B", 20);
    Person p3("C", 30);
    Person p4("D", 40);

    MyArray<Person> arr2(10);
    arr2.push_back(p1);
    arr2.push_back(p2);
    arr2.push_back(p3);
    arr2.push_back(p4);
    printPerson(arr2);

    return 0;
}