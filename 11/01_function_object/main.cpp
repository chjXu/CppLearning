#include <iostream>
using namespace std;

class MyPrint   //仿函数
{
public:
    void operator()(int num)
    {
        cout << "num: " << num << endl;
        count++;
    }

    int count = 0;
};

void myPrint2(int num)
{
    cout << "num2: " << num << endl;
}

void test01()
{
    MyPrint myPrint;
    myPrint(111);

    //myPrint2(111);
    MyPrint()(1000);
}
//函数对象超出普通函数，内部可以保存状态
void test02()
{
    MyPrint myPrint;
    myPrint(11);
    myPrint(11);
    myPrint(11);
    myPrint(11);
    myPrint(11);
    cout << myPrint.count << endl;
}
//函数对象作为参数传递
void doPrint(MyPrint print, int num)
{
    print(num);
}

void test03()
{
    doPrint(MyPrint(), 20);
}

int main()
{   
    //test01();
    //test02();
    test03();
    return 0;
}