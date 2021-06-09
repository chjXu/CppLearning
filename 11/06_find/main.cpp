#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

/*
    查找算法：
    find
*/
//1.
void test01()
{
    vector<int> v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if(pos != v.end())
    {
        cout << *pos << endl;
    }else
    {
        cout << "Can't find " << endl;
    }
    
}

//2. find对自定义数据
#include <string>
#include <functional>
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
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }

    string m_Name;
    int m_Age;
};

void test02()
{
    vector<Person> v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
    if(pos != v.end())
    {
        cout << (*pos).m_Name << "  " << (*pos).m_Age << endl;
    }
    else
    {
        cout << "Can;t find " << endl;
    }
    
}

class myCompare:public binary_function<Person*, Person*, bool>
{
public:
    bool operator()(Person *p1, Person *p2) const
    {
        if(p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age)
        {
            return true;
        }
        return false;
    }
};

void test03()
{
    vector<Person*> v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    Person *p = new Person("b",20);
    //vector<Person>::iterator pos = find(v.begin(), v.end(), p);
    vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(myCompare(), p));
    if(pos != v.end())
    {
        cout << (*pos)->m_Name << "  " << (*pos)->m_Age << endl;
    }
    else
    {
        cout << "Can't find " << endl;
    }
}

/*
    adjacent_find
    1.返回迭代器位置
    2.查找相邻重复元素

    binary_search
    1.统计元素出现次数
    2.在无序序列中不可用

    count/count_if
*/

int main()
{   
    //test01();
    //test02();
    test03();
    return 0;
}