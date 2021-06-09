#include <iostream>
using namespace std;
#include <queue>
//先进先出，queue容器允许从一端新增元素，从另一端移除

void test01()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while (!q.empty())
    {
        cout << q.front() << "  " << q.back() << endl;
        
        q.pop();
    }
    cout << "size: " << q.size() << endl;
}


int main()
{
    test01();
    return 0;
}