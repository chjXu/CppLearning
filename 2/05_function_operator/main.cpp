#include <iostream>
using namespace std;

//函数重载
//C++中 函数名可以重复
//必须在同一个作用域
//函数的参数个数不同，或则类型不同，或则顺序不同
void func()
{
    cout << "无参数的func" << endl;
}

void func(int a)
{
    cout << "有参数的func(int a)" << endl;
}

//返回值可以作为函数重载的条件么？？？     不可以
int func(double a)
{
    cout << "有参数的func(double a)" << endl;
    return 1;
}

//下面的情况会出现二异性的问题
//void func(double a)
//{
//    cout << "有参数的func(double a)" << endl;
//}

void test01()
{
    func(1);
}


//当函数重载碰到默认参数的时候，要注意避免二异性的问题
void func2(int a,int b=10)
{

}

void func2(int a)
{

}

void test02()
{
//    func2(10);
}


//引用的重载版本
void func3(int &a) //引用必须要引用合法的内存空间
{

}

void func3(const int &a)//const 也可以作为重载的的条件 int tmp =10; const int &a = 10;
{

}

void test03()
{
    //int a = 10;
    func3(10);
}

int main(){

    test01();
    //test02();

    return 0;
}