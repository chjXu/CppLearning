#include <iostream>
using namespace std;

//1.普通函数与函数模板区别
template<class T>
T myPlus(T a,T b)
{
    return a+b;
}

int myPlus2(int a,int b)
{
    return a+b;
}

void test01()
{
    int a=10;
    int b=20;
    char c='c';
    //myPlus(a,c); //类型推导不出来，函数模板不可以进行隐式类型分解
    cout << myPlus2(a,c) << endl; //普通函数可以进行隐式类型转换
}

//2.普通函数和模板的调用规则
template<class T>
void print(T a,T b)
{
    cout << "模板" << endl;
}

template<class T>
void print(T a,T b,T c)
{
    cout << "模板" << endl;
}

//通过模板产生的函数 叫模板函数
void print(int a,int b, int c)
{
    cout << "模板函数" << endl;
}

void print(int a,int b)
{
    cout << "普通" << endl;
}

void test02()
{
    int a = 10;
    int b = 20;
    //int c = 30;

    //1.如果出现重载，优先使用普通函数调用,如果没有实现，会出现错误
    //print(a,b);

    //2.如果想强制调用模板，那么可以使用空参数列表
    print<>(a,b);

    //3.函数模板也可以重载
    //print<>(a,b,c);

    //4.如果函数模板可以产生更好的匹配，那么优先调用函数模板
    char c = 'c';
    char d = 'd';
    print(c,d);
}

int main()
{
    //test01();
    test02();
    return 0;
}