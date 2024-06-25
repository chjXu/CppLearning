#include <iostream>
using namespace std;

class MyException   //自定义异常
{
public:
    void printError()
    {
        cout << "自定义异常" << endl;
    }
};

//栈解旋
class Person
{
public:
    Person()
    {
        cout << "Person class" << endl;
    }
    ~Person()
    {
        cout << "delete person" << endl;
    }
};

int myDevide(int a, int b)
{
    if(b==0)
    {
        //return -1;

        //抛出异常
        //throw 3.14;

        //栈解旋
        //从try开始 到throw抛出异常之前 所有栈上的对象 都会被释放, 这个过程称为栈解旋
        //构造和析构的顺序相反
        Person p1;  //开辟到栈上
        Person p2;

        throw MyException(); //匿名对象
    }
    return a/b;
}



void test01()
{
    int a = 10;
    int b = 0;

    //int ret = myDevide(10,0);   //返回-1,无法区分

    //C++中异常处理
    try
    {
        myDevide(a, b);
    }
    catch(const std::exception& e)  //包含int， double， char ...等异常捕获
    {
        std::cerr << e.what() << '\n';
    }
    catch(MyException e)
    {
        e.printError();
    }

    
    
}

int main()
{
    test01();    
    return 0;
}