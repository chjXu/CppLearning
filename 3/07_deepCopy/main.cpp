#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

class Person
{
public:
    Person()
    {}
    //初始化属性
    Person(char* name,int age)
    {
        m_Name = (char *) malloc(strlen(name) + 1);
        strcpy(m_Name,name);

        m_age = age;
    }
    //拷贝构造 系统会提供默认的拷贝构造，而且是简单的值拷贝 （浅拷贝）
    //自己提供拷贝构造，原因简单的浅拷贝会释放堆区空间2次，导致挂掉
    //深拷贝
    Person(const Person& p)
    {
        m_age = p.m_age;
        m_Name = (char *) malloc (strlen(p.m_Name) + 1);
        strcpy(m_Name,p.m_Name);
    }
    
    ~Person()
    {
        cout << "析构函数调用" << endl;
        if(m_Name != NULL)
        {
            free(m_Name);
            m_Name = NULL;
        }
    }
    //姓名
    char* m_Name;
    //年龄
    int m_age;
};

void test01()
{
    Person p1("地发",10);
    Person p2(p1); //浅拷贝

}

int main()
{
    test01();
    return 0;
}