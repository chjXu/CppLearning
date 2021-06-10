#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <pthread.h>

using namespace std;
using namespace chrono;
#define NUM_THREAD 2

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    bool operator==(const Person &p)
    {
        if(this->m_Age = p.m_Age && this->m_Name == p.m_Name)
        {
            return true;
        }
        return false;
    }

    ~Person(){};
    int m_Age;
    string m_Name;
};

void printPerson(const vector<Person> &P)
{
    for(vector<Person>::const_iterator it=P.begin(); it!=P.end();it++)
    {
        cout << (*it).m_Name << "  " << it->m_Age << "  ";
    }
    cout << endl;
}

/*
创建多线程，第一个线程用来按照年龄大小排序（从大到小），第二个也按照年龄大小排序（从小到大）
*/
bool myComparePerson(Person &p1, Person &p2)
{
    if(p1.m_Age > p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool myComparePerson2(Person &p1, Person &p2)
{
    if(p1.m_Age < p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void* sortPerson(void* t)
{
    long tid = (long)t;
    cout << "Thread with id: " << tid << "Sort" << endl;
    sort(p.begin(), p.end(), myComparePerson);
    cout << 
} 


void test01()
{
    vector<Person> P;
    Person p1("one",20);
    Person p2("two",10);
    Person p3("three",5);
    Person p4("four",30);
    Person p5("five",25);
    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);
    P.push_back(p4);
    P.push_back(p5);

    printPerson(P);

    sort(P.begin(),P.end(),myComparePerson);
    printPerson(P);

    sort(P.begin(),P.end(),myComparePerson2);
    printPerson(P);
}


int main()
{


    return 0;
}