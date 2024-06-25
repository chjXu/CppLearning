//适配器
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

//1.
////第二步，继承
class MyPrint:public binary_function<int ,int, void>    //参数类型1,参数类型2， 返回值类型
{
public:
    //第三步，加const
    void operator()(int v, int start) const
    {
        cout << "v= " <<  v << "  start= "  << start << "  v+start= " << v+ start<< endl;
    }
};


void test01()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    //auto print = [](const int& val) {cout << val << endl;};
    //for_each(v.begin(), v.end(),print()); //c++11
    cout << "Please enter a num: " << endl;   
    int num;
    cin >> num;
    
    
    //for_each(v.begin(), v.end(),MyPrint()); //c++11 
    //适配器
    //第一步，绑定
    for_each(v.begin(), v.end(),bind2nd(MyPrint(), num)); //c++11
    for_each(v.begin(), v.end(),bind1st(MyPrint(), num));
}

//2.取反适配器
class greaterThenFive:public unary_function<int, void>
{
public:
    bool operator()(int v) const
    {
        return v > 5;
    }
};

void test02()
{
    //一元取反
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    //查找大于5的数字
    vector<int>::iterator pos =  find_if(v.begin(), v.end(), greaterThenFive());
    if(pos != v.end())
    {
        cout << *pos << endl;
    }
    else
    {
        cout << "Can't find" << endl;
    }
    //需求改为小于5的数字
    vector<int>::iterator pos2 =  find_if(v.begin(), v.end(), not1(greaterThenFive()));
    if(pos2 != v.end())
    {
        cout << *pos2 << endl;
    }
    else
    {
        cout << "Can't find" << endl;
    }


    vector<int>::iterator pos3 =  find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
    if(pos3 != v.end())
    {
        cout << *pos3 << endl;
    }
    else
    {
        cout << "Can't find" << endl;
    }
    
}

//3.函数指针适配器
void MyPrint3(int v, int start)
{
    cout << v + start << " ";
}

void test03()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }

    //将函数指针，适配为 函数对象
    //ptr_fun
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint3), 100));
}
#include <string>

//4.成员函数适配器
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "Name:" << m_Name << "   Age:" << m_Age << endl;
    }

    void plusAge()
    {
        this->m_Age += 1;
    }

    string m_Name;
    int m_Age;
};

void MyPrintPerson(Person &p)
{
    cout << "Name:" << p.m_Name << "   Age:" << p.m_Age << endl;
}
void test04()
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

    //for_each(v.begin(), v.end(), MyPrintPerson3);
    //成员函数适配器
    //mem_fun_ref   对象实体
    //mem_fun   对象指针
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main()
{
    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}