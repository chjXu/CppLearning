#include <iostream>
#include <string>
using namespace std;
//自定义数据类型，不会内部做比较，所以需要重载

//==
class Person
{
    public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //重载==
    bool operator==(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
    //重载！=
    bool operator!=(Person &p)
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return false;
        }
        return true;
    }

    public:
    string m_Name;
    int m_Age;
};

void test01()
{
    Person p1("xiaoming",10);
    Person p2("xiaoqiang",15);
    Person p3("xiaoqiang",15);

    //int a=10;
    //int b=10;
    //if(a=b)
    //{
    //    cout << "相等" << endl;
    //}

    if(p3 == p2) //如果直接这样写肯定会报错，下一步操作==重载
    {
        cout << "p1 和 p2 相等！" << endl;
    }
    else
    {
        cout << "p1 和 p2 不相等！" << endl;
    }

    if(p1 != p2)
    {
        cout << "p1 和 p2 不相等！" << endl;
    }
    else
    {
        cout << "p1 和 p2 相等！" << endl;
    }
}

int main()
{
    test01();
    return 0;
}