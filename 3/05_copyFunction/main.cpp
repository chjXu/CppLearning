#include <iostream>
using namespace std;

class Person
{
public:
    Person() {cout << "默认构造函数" << endl;} //默认、无参构造函数
    ~Person() {cout << "默认析构函数" << endl;} //析构函数
    Person(int a){cout << "有参构造函数" << endl;} //有参构造函数
    Person(const Person& p) {m_Age = p.m_Age ;cout << "拷贝构造函数" << endl;} //拷贝构造函数

    int m_Age;
};

//拷贝函数调用时机
//1.用已经创建好的对象来初始化新的对象
void test01()
{
    Person p1;
    p1.m_Age = 10;

    Person p2(p1);
    cout << "p2.m_Age: " << p2.m_Age << endl;
}

//2.值传递的方式给函数参数传值
void doWork(Person& p1) //Person p1 = Person(p)
{
    cout << "p1.m_Age: " << p1.m_Age << endl;
}

void test02()
{
    Person p;
    p.m_Age = 100;

    doWork(p);
}

//3.以值的方式返回局部对象
Person doWork2()
{
    Person p1;
    return p1;
}

void test03()
{
    Person p = doWork2();
}

//Release下优化程序什么样？
/*
Person p; //不调用构造函数
doWork2(p);

void doWork2(Person& p)
{
    Person p1; //调用构造函数
}
*/

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}