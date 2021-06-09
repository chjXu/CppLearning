#include <iostream>
using namespace std;

void mySwapint(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//类型很多，但逻辑相似
//类型参数化 ，泛型编程 -- 模板技术

template <class T> //告诉编译器 下面出现T不要报错 ，T是一个通用的类型 .等价与 template<typename T>
void mySwap(T &a,T &b)
{
    T tem = a;
    a = b;
    b= tem;
}

void test01()
{
    int a=10;
    int b=20;

    //mySwapint(a,b);
    //1.自动类型推导
    mySwap(a,b);

    //2.显示指定类型
    mySwap <int> (a,b);

    //模板必须要指定T，才可以运行

    cout << "a =  " << a << endl;
    cout << "b =  " << b << endl;
}



int main()
{
    test01();
    return 0;
}