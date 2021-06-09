#include <iostream>
using namespace std;
#include <map>
/*
map对象按顺序存储一组值，其中每个元素与一个检索关键码关联。map与set和multiset不同，set和multiset中元素既被作为存储的数据又被称作为数据的关键值，而map类型中元素的数据和关键值是分开的。创建map类模板的方法如下：

1.map<key,type,predicate>name;

这种方法创建了一个名为name，并包含type类型数据的map空对象。该对象使用谓词所指定的函数来对集合中的元素进行排序。例如，要给整数创建一个空map对象，可以这样写：

std::map<int,int,std::less<int> >intmap;

2.map<key,type,predicate>name(mymap);

这种方法使用了复制构造函数，从一个已存在的映射mymap中 生成一个map对象。

3.map<key,type,predicate>name(first,last);

这种方法从一定范围的元素中根据多重指示器所指示的起始与终止位置创建一个映射。

下面通过一些操作来实现对map对象的应用。

map的基本操作函数：

C++ Maps是一种关联式容器，包含“关键字/值”对

begin() 返回指向map头部的迭代器

clear(） 删除所有元素

count() 返回指定元素出现的次数

empty() 如果map为空则返回true

end() 返回指向map末尾的迭代器

equal_range() 返回特殊条目的迭代器对

erase() 删除一个元素

find() 查找一个元素

get_allocator() 返回map的配置器

insert() 插入元素

key_comp() 返回比较元素key的函数

lower_bound() 返回键值>=给定元素的第一个位置

max_size() 返回可以容纳的最大元素个数

rbegin() 返回一个指向map尾部的逆向迭代器

rend() 返回一个指向map头部的逆向迭代器

size() 返回map中元素的个数

swap() 交换两个map

upper_bound() 返回键值>给定元素的第一个位置

value_comp() 返回比较元素value的函数
*/
#include <string>
void test01()
{
    map<int, int> m;
    //插入值有4种方式
    //1.
    m.insert(pair<int, int>(1, 10));
    //2.推荐
    m.insert(make_pair(2, 20));
    //3. 不推荐
    m.insert(map<int, int>::value_type(3, 30));
    //4.
    m[4] = 40;

    for(map<int ,int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key " << it->first << "  value " << it->second << endl;
    }
}

void test02()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    m.erase(2);

    for(map<int ,int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key " << it->first << "  value " << it->second << endl;
    }

    //find(key)
    map<int, int>::iterator pos = m.find(4);
    if(pos != m.end())
    {
        cout << pos->first << "  " << pos->second << endl;
    }
    else
    {
        cout << "Can't find! " << endl;
    }
    
    //其他可参考set
}

//排序规则
class myCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test03()
{
    map<int, int, myCompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    for(map<int ,int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key " << it->first << "  value " << it->second << endl;
    }
}

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}