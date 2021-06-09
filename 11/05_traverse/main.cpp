#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
/*
    遍历算法:
    for_each    //常用
    transform
*/
//1.for_each 基本用法
class myPrint
{
public:
    void operator()(int v)
    {
        cout << v << endl;
    }
};

void test01()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), myPrint());
}

//2.for_each 可以保存内部记录
class myPrint2
{
public:
    void operator()(int v)
    {
        cout << v << endl;
        m_count++;
    }
    int m_count;
};

void test02()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }

    myPrint2 print2 =  for_each(v.begin(), v.end(), myPrint2());
    cout << print2.m_count << endl;
}

//3.for_each 可以绑定参数进行输出
#include <functional>
class myPrint3:public binary_function<int, int, void>
{
public:
    void operator()(int v, int start) const
    {
        cout << v+start << endl;
    }
    int m_count;
};

void test03()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), bind2nd(myPrint3(), 1000));
}

//transform
//1.
class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }
};

void test04()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    } 
    vector<int> vTarget;    //目标容器,必须分配内存
    vTarget.resize(10);
    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << " ";});
}

//2.把2个容器搬运到第3个容器中
class Transform2
{
public:
    int operator()(int val1, int val2)
    {
        return val1 + val2;
    }
};

void test05()
{
    vector<int>v1;
    vector<int>v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
        v2.push_back(200+i);
    } 
    vector<int> vTarget;    //目标容器,必须分配内存
    vTarget.resize(10);
    transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), Transform2());
    for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << " ";});
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