#include <iostream>
using namespace std;

//分类
//按照参数进行分类  无参构造函数（默认构造函数） 有参构造函数
//按照类型进行分类  普通构造函数  拷贝构造函数

class Person
{
public: //构造和析构必须写在public中才可以调用
    Person() {cout << "默认构造函数" << endl;} //默认、无参构造函数
    ~Person() {cout << "默认析构函数" << endl;} //析构函数
    Person(int a){cout << "有参构造函数" << endl;} //有参构造函数
    Person(const Person& p) { m_Age = p.m_Age;cout << "拷贝构造函数" << endl;} //拷贝构造函数

    int m_Age;
};

void test01()
{
    //构造函数的调用方式
    //1.括号法调用
    
    Person p1(1);
    p1.m_Age = 10;
    Person p2(p1);
    cout << p2.m_Age << endl;
    
    //Person p3; //默认构造函数 不要加（） Person p3（）; //编译器认为这是函数的声明

    //2.显示法调用
    Person p4 = Person(100);
    Person p5 = Person(p4);
    
    //Person(100); //叫匿名对象，匿名对象特定，如果编译器发现对象是匿名的，那么在这行代码结束后就释放这个对象

    //不能用拷贝构造函数 初始化匿名对象
    Person(p5); //如果这样写，编译器认为你写成了 Person p5; 对象的声明，如果写成右值，那么可以
    Person p6 = Person(p5); //这个相当于 Person p6(p5);

    Person p7 = 100; //相当于调用了Person p7 = Person(100),隐式类型转换
    Person p8 = p7; //相当于 Person p8 = Person(p7)
}

int main()
{
    test01();
    return 0;
}