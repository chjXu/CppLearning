#include <iostream>
using namespace std;
#include <set>
/*

//1.
结合容器（associative容器）是STL提供的容器一种，其中的元素都是经过排序的，它主要通过关 <键的方式> 来提高查询的效率，结合容器包括set,multiset,map,multimap,hashtable。

**set类模板又称为集合类模板，一个集合对象像键表一样顺序地存储一组值。**在一个集合中，集合元素既充当存储的数据，又充当数据的关键码。

可以使用下面的几种方法来创建set对象。

1.std::set<type,prdicate>name;

这种方法创建了一个名为name，并且包含type类型数据的set空对象，该对象使用谓词所指定的函数来对集合中的元素进行排序。例如，要给整数创建一个set对象，可以这样写：

set::set<int,std::less<int>>intset;

2.std::set<type,predicate>name(myset);

这种方法使用复制构造函数，从一个已存在的集合myset中生成一个set对象。

3.std::set<type,predicate>name(first,last);

这种方法从一定范围的元素中根据多重指示器所指示的起始与终止位置创建一个集合。

set类中的常用方法：

begin()     　　//返回set容器的第一个元素

end() 　　　　 //返回set容器的最后一个元素

clear()   　　 //删除set容器中的所有的元素

empty() 　　//判断set容器是否为空

max_size() 　//返回set容器可能包含的元素最大个数

size() 　　　//返回当前set容器中的元素个数

rbegin　　　　//返回的值和end()相同

rend()　　　　//返回的值和rbegin()相同


///2.
multiset使程序能顺序存储一组数据。与集合类类似，多重集合的元素既可以作为存储的数据又可以作为数据的关键字。然而，与集合类不同的是多重集合类可以包含重复的数据。下面列出了几种创建多重集合的方法：

1.std::multiset<type,prdicate>name;

这种方法创建了一个名为name，并且包含type类型数据的multiset空对象，该对象使用谓词所指定的函数来对集合中的元素进行排序。例如，要给整数创建一个multiset对象，可以这样写：

set::multiset<int,std::less<int> >intset;

2.std::multiset<type,predicate>name(mymultiset);

这种方法使用复制构造函数，从一个已存在的集合mymultiset中生成一个multiset对象。

3.std::multiset<type,predicate>name(first,last);

这种方法从一定范围的元素中根据多重指示器所指示的起始与终止位置创建一个集合。

multiset类中部分方法说明如下：

begin  返回一个迭代器，此迭代器指向 multiset 中的第一个元素。

cbegin  返回一个常量迭代器，此迭代器用于发现 multiset 中的第一个元素。

cend  返回一个常量迭代器，此迭代器用于发现 multiset 中最后一个元素之后的位置。

clear  清除 multiset 的所有元素。

count  返回 multiset 中其键与指定为参数的键匹配的元素数量。

crbegin  返回一个常量迭代器，此迭代器用于发现反向集中的第一个元素。

crend  返回一个常量迭代器，此迭代器用于发现反向集中最后一个元素之后的位置。

emplace  将就地构造的元素插入到 multiset。

emplace_hint  将就地构造的元素插入到 multiset，附带位置提示。

empty  测试 multiset 是否为空。

end  返回一个迭代器，此迭代器指向 multiset 中最后一个元素之后的位置。

equal_range  返回一对迭代器。 此迭代器对中的第一个迭代器指向 multiset 中其键大于指定键的第一个元素。 此迭代器对中的第二个迭代器指向 multiset 中其键等于或大于指定键的第一个元素。

erase  从 multiset 中的指定位置移除一个元素或元素范围，或者移除与指定键匹配的元素。

find  返回一个迭代器，此迭代器指向 multiset 中其键与指定键相等的元素的第一个位置。

get_allocator  返回用于构造 multiset 的 allocator 对象的副本。

insert  将一个元素或元素范围插入到 multiset。

key_comp  提供一个函数对象，此函数对象可比较两个排序键以确定 multiset 中两个元素的相对顺序。

lower_bound  返回一个迭代器，此迭代器指向 multiset 中其键等于或大于指定键的第一个元素。

max_size  返回 multiset 的最大长度。

rbegin  返回一个迭代器，此迭代器指向反向 multiset 中的第一个元素。

rend  返回一个迭代器，此迭代器指向反向 multiset 中最后一个元素之后的位置。

size  返回 multiset 中的元素数量。

swap  交换两个 multiset 的元素。

upper_bound  返回一个迭代器，此迭代器指向 multiset 中其键大于指定键的第一个元素。

value_comp  检索用于对 multiset 中的元素值进行排序的比较对象副本。

*/

//树的概念
//平衡二叉树，所有左子节点 与 右子节点的深度查找 不能大于1
void printSet(set<int> &s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}


void test01()
{
    set<int> s1;
    //关联式容器, key进行排序，从小到大
    s1.insert(10);
    s1.insert(0);
    s1.insert(4);
    s1.insert(7);
    s1.insert(3);
    printSet(s1);

    s1.erase(0);
    s1.erase(s1.begin());
    printSet(s1);
}

//set 查找操作
void test02()
{
    set<int> s1;
    //关联式容器, key进行排序，从小到大
    s1.insert(10);
    s1.insert(0);
    s1.insert(4);
    s1.insert(7);
    s1.insert(3);
    printSet(s1);

    //find(key)
    set<int>::iterator pos =  s1.find(1);
    if(pos != s1.end())
    {
        cout << *pos << endl;
    }
    else
    {
        cout << "can't find!" << endl;
    }

    //count(key)
    cout << s1.count(10) << endl;

    //lower_bound(key)  返回第一个key>=keyElem元素的迭代器
    set<int>::iterator it = s1.lower_bound(8);
    if(it != s1.end())
    {
        cout << *it << endl;
    }
    else
    {
        cout << "Can't find!" << endl;
    }
    //upper_bound(key)    返回第一个key>keyElem元素的迭代器
    set<int>::iterator it2 = s1.upper_bound(3);
    if(it != s1.end())
    {
        cout << *it2 << endl;
    }
    else
    {
        cout << "Can't find!" << endl;
    }
    //equal_range(keyElem)  返回容器中key与keyElem相等的上下限的两个迭代器
    pair<set<int>::iterator, set<int>::iterator> ret = s1.equal_range(3);
    //获取第一个值
    if(ret.first != s1.end())
    {
        cout << *(ret.first) << endl;
    }
    else
    {
        cout << "Can't find first!" << endl;
    }
    //获取第二个值
    if(ret.second != s1.end())
    {
        cout << *(ret.second) << endl;
    }
    else
    {
        cout << "Can't find second!" << endl;
    }
    
}

//set 容器，不容许插入重复的键值
void test03()
{
    set<int> s1;
    pair<set<int>::iterator, bool> ret = s1.insert(10);
    if(ret.second)
    {
        cout << "insert successed" << endl;
    }else
    {
        cout << "insert failed" << endl;
    }
    
    ret = s1.insert(10);
    if(ret.second)
    {
        cout << "second insert successed" << endl;
    }else
    {
        cout << "second insert failed" << endl;
    }

    printSet(s1);

    //multiset 允许插入重复值
    multiset<int> mul;
    mul.insert(10);
    mul.insert(10);
    
}

//set容器排序
//仿函数    set容器是不能跟前面的容器一样用函数名來排序
class myCompare
{
public:
    //重载（）
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};


void test04()
{
    set<int, myCompare> s1;

    s1.insert(10);
    s1.insert(0);
    s1.insert(4);
    s1.insert(7);
    s1.insert(3);

    for(set<int, myCompare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //从大到小
    //在插入之前就指定排序规则

}



//自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class myComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2) //const 不能忘
    {
        if(p1.m_Age > p2.m_Age)
        {
            return true;
        }
        return false;
    }
};

void test05()
{
    set<Person, myComparePerson> s1;
    Person p1("大娃",50);
    Person p2("二娃",40);
    Person p3("三娃",30);
    Person p4("四娃",20);

    //插入自定义数据类型，上来就应该指定排序规则
    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    //
    for(set<Person, myComparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << "Name: " <<(*it).m_Name << "  " << " Age: " << (*it).m_Age << endl;
    }
}
int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
    return 0;
}