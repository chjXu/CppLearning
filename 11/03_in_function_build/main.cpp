#include <iostream>
using namespace std;
//内建函数对象头文件
#include <functional>
#include <vector>
#include <algorithm>

void test01()
{
    //template<class T> T negate<T> //取反仿函数
    negate<int> n;
    cout << n(10) << endl;  //-10

    //plus  template<class T> T plus<T>
    plus<int> p;
    cout << p(10,10) << endl;

    //template<class T> bool greater<T> //大于
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl;});    //这是C++11标准，需要用g++ -std=c++11 main.cpp编译
}

int main()
{
    test01();
    return 0;
}