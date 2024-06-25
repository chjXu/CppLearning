#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
//谓词
//一元谓词
class GreaterThen20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //查找第一个大于20的数字
    //第三个参数是 函数对象 匿名对象
    vector <int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
    if(pos != v.end())
    {
        cout << *pos << endl;
    }
    else
    {
        cout << "Can't find" << endl;
    }
    
}

//二元谓词
class MyCompare
{
public:
    bool operator()(int va1, int va2)
    {
        return va1 > va2;
    }
};

void test02()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    sort(v.begin(), v.end(), MyCompare());

    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
}


int main()
{
    //test01();
    test02();
    return 0;
}