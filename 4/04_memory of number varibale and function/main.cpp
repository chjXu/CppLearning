#include <iostream>
#include <string>
using namespace std;

class Person
{
    int m_A;//非静态成员变量，属于对象身上
    void func(){};
    static int m_B;//静态成员变量，不属于对象身上
    static void func2(){};
    double m_C; //参数对齐，不够8,直接给8  12错误  16正确
    //结论：只有非静态成员变量，才属于对象身上
};

void test01()
{
    //空类大小为1,每个实例都有自己独一无二的地址，char维护这个地址
    //Person[10] p[0] p[1]
   cout << "size of (Person) = " << sizeof(Person) << endl;
}

void test02()
{
    //this 指针指向被调用的成员函数所属的对象
    //this永远指向当前对象
    //this 隐含每个类的非静态成员函数中
    Person p1;
    p1.func(); //编译器会偷偷 加入 一个 this指针  Person× this

    Person p2;
    p2.func();
}

int main()
{
    test01();
    return 0;
}