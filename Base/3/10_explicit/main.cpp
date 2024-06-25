#include <iostream>
#include <string>
using namespace std;

class Mystring
{
public:
    Mystring()
    {

    }
    
    explicit Mystring(int a)
    {
        mSize = a;
    }

    char* mStr;
    int mSize;
};

//类对象作为成员的时候，构造顺序现将类对象一一构造，然后析构的顺序是相反的

void test01()
{
    Mystring str = "abc";
    Mystring str2(10);
    Mystring str3 = 10; //用作什么？ str3字符串为10？ 字符串长度为10？
    //隐式类型转换 Mystring str3 = Mystring(10)
    //explicit关键字，作用：防止隐式类型转换
}

int main()
{
    test01();
    return 0;
}