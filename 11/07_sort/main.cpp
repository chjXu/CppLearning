#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <ctime>

/*
    merge   容器元素合并，并储存到另一容器中， 这两个容器 必须是有序的
*/ 
void test01()
{
    vector<int>v1;
    vector<int>v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
    }

    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << " ";});
}

/*
    sort    见前面
*/

/*
    random_shuffle 洗牌算法
*/
void test02()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }

    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
}
/*
    reverse
*/
void test03()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
}

int main()
{
    //test01();

    //srand((unsigned int) time(NULL));
    //test02();

    test03();


    return 0;
}