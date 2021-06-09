#include <iostream>
using namespace std;

class Animal
{
public:

    int m_age;
};

class Sheep:virtual public Animal
{
public:
    
};

class Tuo:virtual public Animal
{
public:

};

class Sheeptuo :public Sheep,public Tuo
{
public:
    
};

//菱形继承的解决方案 利用虚继承
//操作的是共享的一份数据
//vbptr虚基类指针

void test01()
{
    Sheeptuo st;
    st.Sheep::m_age = 10;
    st.Tuo::m_age = 20;

    //造成资源浪费
    cout << st.Sheep::m_age << endl;
    cout << st.Tuo::m_age << endl;
    //可以直接访问age，已经没有二义性了
    cout << st.m_age << endl;
}

void test02()
{
    Sheeptuo st;
    st.m_age = 100;
    //找sheep的偏移量，得对照虚基列表写
    cout << *(int *)((int *)*(int *)&st + 1) << endl; 
}

int main()
{
    test01();
    test02();
    return 0;
}