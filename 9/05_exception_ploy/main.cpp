#include <iostream>
using namespace std;
//异常基类
class BaseException
{
public:
    virtual void printError()
    {

    }
};

class NullPointerException:public BaseException
{
public:
    virtual void printError()
    {
        cout << "NullPointer Exception" << endl;
    }
};

class OutofRangeException:public BaseException
{
public:
    virtual void printError()
    {
        cout << "OutofRangeException" << endl;
    }
};

void doWork()
{
    //throw NullPointerException();
    throw OutofRangeException();
}

void test01()
{
    try
    {
        doWork();
    }
    catch(BaseException &e)
    {
        e.printError();
    }
    
}

int main()
{
    test01();

    
    return 0;
}