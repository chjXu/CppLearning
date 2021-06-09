#include <iostream>
using namespace std;

class MyException
{
public:
    MyException()
    {
        cout << "MyException 默认构造" << endl;
    }

    MyException(const MyException &e)
    {
        cout << "MyException 拷贝构造" << endl;
    }

    ~MyException()
    {
        cout << "MyException 析构" << endl;
    }
};

void doWork()
{
    throw MyException();
}

void test01()
{
    try
    {
        doWork();
    }
    catch(MyException &e)
    {
        cout << "异常捕获" << endl;
    }
    
}
int main()
{
    test01();

    
    return 0;
}