#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#include <iterator>
/*
    copy
*/
void test01()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }

    vector<int>vCopy;
    vCopy.resize(v.size());
    copy(v.begin(), v.end(), vCopy.begin());
    //for_each(vCopy.begin(), vCopy.end(), [](int val){cout << val << " ";});
    copy(vCopy.begin(), vCopy.end(), ostream_iterator<int>(cout," "));
}

/*
    replace/replace_if
*/
class MyCompare
{
public:
    bool operator()(int v)
    {
        return v > 3;
    }
};

void test02()
{
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    
    replace(v.begin(), v.end(), 3,300);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));

    //把大于3的数字全替换掉
    replace_if(v.begin(), v.end(), MyCompare(), 30000);
    cout << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
}

/*
    swap
*/
void test03()
{
    vector<int>v1;
    vector<int>v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
    }
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout," "));
    swap(v1, v2);
    cout << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout," "));
}


int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}