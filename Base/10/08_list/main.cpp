#include <iostream>
using namespace std;
/*
链表(list)，即双向链表容器，它不支持随机访问，访问链表元素要指针从链表的某个端点开始，插入和删除操作所花费的时间是固定的，和该 元素在链表中的位置无关。list在任何位置插入和删除动作都很快，不像vector只在末尾进行操作。

使用链表类模板需要创建list对象，创建list对象有以下几种方法：

（1）std::list<type>name;

该方法创建一个名为name空间的空list对象，该对象可容纳数据类型为type的数据。例如：为整型值创建一个空std::list对象可以使用这样的语句：

std::list<int>list;

（2）std::list<type>name(size);

该方法创建一个大小为size的list对象。

（3）std::list<type>name;(size,value);

该方法创建一个大小为size的list对象，并将对象的每个值设为value。

（4）std::list<type>name(mydeque);

该方法使用复制构造函数，用现有的链表mylist创建一个list对象。

（5）std::list<type>name(first,last);

该方法创建了元素在指定范围内的列表，first代表起始范围，last代表结束范围。

list对象的主要成员函数如下：

assign() 给list赋值

back() 返回最后一个元素

begin() 返回指向第一个元素的迭代器

clear() 删除所有元素

empty() 如果list是空的则返回true

end() 返回末尾的迭代器

erase() 删除一个元素

front() 返回第一个元素

get_allocator() 返回list的配置器

insert() 插入一个元素到list中

max_size() 返回list能容纳的最大元素数量

merge() 合并两个list

pop_back() 删除最后一个元素

pop_front() 删除第一个元素

push_back() 在list的末尾添加一个元素

push_front() 在list的头部添加一个元素

rbegin() 返回指向第一个元素的逆向迭代器

remove() 从list删除元素

remove_if() 按指定条件删除元素

rend() 指向list末尾的逆向迭代器

resize() 改变list的大小

reverse() 把list的元素倒转

size() 返回list中的元素个数

sort() 给list排序

splice() 合并两个list

swap() 交换两个list

unique() 删除list中重复的元素
*/

#include <list>
#include <string>
void printList(list<int> &L)
{
    for(list<int>::iterator it=L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


void test01()
{
    list<int> L(10,10);
    list<int> L2(L.begin(), L.end());
    L2.push_back(100);
    printList(L2);

    //逆向打印
    for(list<int>::reverse_iterator it=L2.rbegin(); it != L2.rend(); it++)
    {
        cout << *it << endl;
    }

    //list迭代器不支持随机访问
    //list<int>::iterator itBegin = L2.begin();
    //itBegin = itBegin + 1;

    //插入数据
    list<int>L3;
    L3.push_back(10);
    L3.push_back(30);
    L3.push_back(20);
    L3.push_front(100);
    L3.push_front(300);
    L3.push_front(200);
    printList(L3);
    //删除数据
    L3.pop_front();
    L3.pop_back();
    printList(L3);
    //insert
    L3.insert(L3.begin(), 1000);
    printList(L3);
    //remove
    L3.remove(10);
    printList(L3);

}

//
void test02()
{
    list<int>L3;
    L3.push_back(10);
    L3.push_back(30);
    L3.push_back(20);
    L3.push_front(100);
    L3.push_front(300);
    L3.push_front(200);

    cout << L3.size() << endl;

    L3.resize(10);
    printList(L3);

    L3.resize(3);
    printList(L3);

    list<int> L4;
    L4.assign(L3.begin(), L3.end());
    printList(L4);
}

bool myCompare(int v1,int v2)
{
    return v1 > v2;
}


//list反转排序
void test03()
{
    list<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(50);
    L.push_back(40);
    L.reverse();
    printList(L);

    // 如果不支持随机访问的迭代器， 不可以用系统提供的算法
    //如果不支持用系统提供的算法，那么这个类内部会提供
    //sort(L.begin(), L.end());
    L.sort();
    printList(L);
    L.sort(myCompare);
    printList(L);
}

//自定义数据类型
class Person
{
public:
    Person(string name, int age, int hight)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Hight = hight;
    }

    //重载==
    bool operator==(const Person &p)//不加const， 就出错
    {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Hight == p.m_Hight)
        {
            return true;
        }
        return false;
    }
    string m_Name;
    int m_Age;

    int m_Hight;
};

//Person 排序规则， 如果年龄 相同， 按照身高的升序排序
bool myComparePerson(Person &p1, Person &p2)
{
    /*
    if(p1.m_Age > p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }*/

    if(p1.m_Age == p2.m_Age)
    {
        return p1.m_Hight < p2.m_Hight;
    }
    else
    {
        return p1.m_Age > p2.m_Age;
    }
    
}    
    
void test05()
{
    list<Person> L;

    Person p1("A", 10, 165);
    Person p2("B", 20, 170);
    Person p3("C", 40, 169);
    Person p4("D", 60, 169);
    Person p5("E", 20, 169);
    
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);

    //需求，按照年龄大小降序输出
    //对于自定义数据类型，必须要指定排序规则
    L.sort(myComparePerson);

    for(list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "Name: " << it->m_Name << "  age: " << it->m_Age << "  height: " << it->m_Hight << endl;
    }

    cout << "-----------------------" << endl;
    //删除 p2,自定义类型，需要重载==
    L.remove(p2);
    for(list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "Name: " << it->m_Name << "  age: " << it->m_Age << "  height: " << it->m_Hight << endl;
    }
}

int main()
{
    //test01();
    //test02();
    //test03();
    test05();
    return 0;
}