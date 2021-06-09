#include <iostream>
using namespace std;
#include <string>
//创建对组
void test01(){
    //first
    pair<string, int> p(string("Tom"), 100);

    //取值
    cout << "Name  " << p.first << endl;
    cout << "Age  " << p.second << endl;

    //second
    pair<string, int> p2 = make_pair("Jerry", 200);
    cout << "Name  " << p2.first << endl;
    cout << "Age  " << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}