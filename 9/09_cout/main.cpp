#include <iostream>
using namespace std;
//cout.put()
void test01()
{
    cout.put('a');

    char buf[1024] = "hello world";
    cout.write(buf, sizeof(buf));
}

int main()
{
    test01();

    
    return 0;
}