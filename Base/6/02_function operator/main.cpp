#include <iostream>
#include <string>
using namespace std;
//注意事项：
//不能重载&& 和 ||，因为无法实现短路规则
//= [] -> 只能通过成员函数进行重载
//<< 和 >> 只能通过全局函数配合友元函数进行重载


//()重载
class MyPrint
{
    public:
    //第一个()重载，第二个()可以传参
    void operator() (string text) {
        cout << text << endl;
    }
};

class Myadd
{
    public:
    int operator() (int a, int b)
    {
        return a+b;
    }
};

void test01()
{
    MyPrint myPrint;
    myPrint("hello world！");// 仿函数
    Myadd myadd;
    cout << myadd(1,2) << endl;

    cout << Myadd()(1,1) << endl; //匿名对象
}

int main()
{
    test01();
    return 0;
}