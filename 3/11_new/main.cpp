#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "构造函数的调用"  << endl;
    }

  
    Person(int a)
    {
        cout << "有参构造函数的调用"  << endl;
    }

    ~Person()
    {
        cout << "析构函数的调用" << endl;
    }
};



void test01()
{
    //Person p1;   //栈区开辟
    Person * p2 = new Person; //在堆区开辟
    //所有new出来的对象 都会返回该类型的指针
    //malloc 返回 void× 还要强制转换
    //malloc 会调用构造吗？ 不会 new 会调用构造
    //new 运算符 malloc 函数
    //释放 堆区空间
    //new 与 delete共用   malloc 与 free用
    delete p2;
}

void test02()
{
    void *p = new Person; //一般不这样写
    //当用void× 接受new出来的指针，会出现释放的问题
    delete p; //无法释放
}

void test03()
{
    //通过new开辟数组 一定会调用默认构造函数，所以一定要提供默认构造

    Person * pArray = new Person[10];

    //Person pArray2[2] = {Person(1),Person(2)} //在栈上开辟数组，可以指定有参构造

    //释放new出来的数组 delete []
    delete [] pArray;
}

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}