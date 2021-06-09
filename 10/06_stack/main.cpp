#include <iostream>
using namespace std;
#include <stack>
//先进后出
//stack没有迭代器
/*
    s.emplace;
    s.empty;
    s.pop;
    s.push;
    s.size;
    s.swap;
    s.top;
*/


void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (s.size() != 0)
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << "size: " << s.size() << endl;


    
}


int main()
{
    test01();
    return 0;
}