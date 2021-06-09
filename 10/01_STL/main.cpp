#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm> //算法头文件
//迭代器 遍历功能 理解为指针
//普通的指针也是一种迭代器
void test01()
{
    int array[5] = {1,3,5,6,8};

    int * p =array; //指针指向数组首地址 &array[0]

    for(int i=0;i<5;i++)
    {
        //cout << array[i] << endl;
        cout << *(p++) << endl;
    }
}

void myPrint(int v)
{
    cout << v << endl;
}

//容器
void test02()
{
    vector<int> v;
    //向vctor写书据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //遍历
    //1.利用迭代器
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    /*while (itBegin != itEnd)
    {
        cout << *itBegin << endl;

        itBegin++;
    }*/
    
    //2.for循环
    //for(int i=0;i< 10;i++)
    /*for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout << *it << endl;
    }*/

    //3.利用算法
    for_each(v.begin(),v.end(),myPrint);
}

//操作自定义的数据类型
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

void test03()
{
    vector<Person> v;
    Person p1("爱嗲的",20);
    Person p2("ajdjd",10);
    Person p3("dhuqdh",5);
    Person p4("ad",1);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //遍历
    for(vector<Person>::iterator it = v.begin();it != v.end();it++)
    {
        cout << "姓名：" << (*it).m_Name << " " << "年龄：" << (*it).m_Age << endl;//等价于下
        cout << "姓名：" << it->m_Name << " " << "年龄：" << it->m_Age << endl;
    }

}

//存放自定义数据类型的指针
void test04()
{
    vector<Person *> v;
    Person p1("爱嗲的",20);
    Person p2("ajdjd",10);
    Person p3("dhuqdh",5);
    Person p4("ad",1);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    //遍历
    for(vector<Person *>::iterator it = v.begin();it != v.end();it++)
    {
        cout << "姓名：" << (*it)->m_Name << " " << "年龄：" << (*it)->m_Age << endl;
        //*it就是vector<...> 括号中的...
       
    }
}

//容器嵌套
void test05()
{
    vector<vector<int> > v;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;

    for(int i=0;i<5;i++)
    {
        v1.push_back(i);
        v2.push_back(i + 10);
        v3.push_back(i + 100);
    }
    //将小容器放到大容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //遍历
    for(vector<vector<int> >::iterator it = v.begin();it != v.end();it++)
    {
        for(vector<int>::iterator vit = it->begin();vit != it->end();vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
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