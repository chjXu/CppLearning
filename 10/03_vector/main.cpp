#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

struct res{
	int t1;
	int t2;
};

void printfVector(vector<int> &v){
        for(vector<int>::iterator it=v.begin(); it!=v.end();it++){
                cout << *it << endl;
        }
}

void testResize(){
	vector<res> v;
	v.resize(3);
	cout << "当前v的大小:" << v.size() << endl;
	for(int i=0; i<1000; i++){
		v.push_back(i);
	}
	printfVector(v);
}

void min(const vector<vector<int> >& num,int a[])
{
	int min_value = num[0][0];
	for(int i=0; i< num.size(); i++)
	{
		for(int j=0; j < num[i].size(); j++)
		{
			if(min_value > num[i][j]){
				min_value = num[i][j];
				a[0] = i;
				a[1] = j;
			}		
		}
	}

}

void test01()
{
   vector<vector<int> > v;
	vector<int> tmp;
        for(int i=0; i<5; i++){
		tmp.clear();
		for(int j=i; j<5; j++)
		{
			tmp.push_back(i+j);
		}
	v.push_back(tmp);
	}

	for(vector<vector<int> >::iterator it=v.begin();it!=v.end();it++)
	{
		for(int i=0; i< (*it).size(); ++i)
		{
			cout << (*it)[i] << " ";
		}
		cout << endl;
	}
	int b[2];
	min(v,b);
	cout << b[0] << b[1] << endl;
	//auto smallest = std::min_element(v.begin(), v.end());
	//cout << "min_element is:" << *smallest << endl;

   //cout << "min element is " << *smallest<< " at position " <<std::distance(v.begin(), smallest) << endl;
}

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test02()
{
    vector<int> v;
    int arr[] = {2,3,4,1,9};
    vector<int> v1(arr,arr+ sizeof(arr)/sizeof(int));

    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);

    vector<int> v3(10,100);
    printVector(v3);

    //赋值使用
    vector<int> v4;
    v4.assign(v3.begin(),v3.end());
    printVector(v4);

    //交换
    v4.swap(v2);
    printVector(v4);

    cout << "v4容器大小" << v4.size() << endl;

    if(v4.empty())
    {
        cout << "v4为空" << endl;
    }
    else
    {
        cout << "v4不为空" << endl;
    }
    
    //v4 23419
    v4.resize(10,-1);//默认为0,现在为-1
    printVector(v4); 
    v4.resize(3);//只有3个位置，超出的部分被删除
    printVector(v4);
}

//巧用swap收缩空间
void test03()
{
    vector<int> v;
    for(int i = 0;i < 10000;i++)
    {
        v.push_back(i);
    }
    cout << "v的容量" << v.capacity() << endl;
    cout << "v的大小" << v.size() << endl;

    v.resize(10);
    cout << "v的容量" << v.capacity() << endl;
    cout << "v的大小" << v.size() << endl;

    //巧用swap
    vector<int>(v).swap(v);
    //vector<int>(v)初始化匿名对象
    
    cout << "v的容量" << v.capacity() << endl;
    cout << "v的大小" << v.size() << endl;
}

void test04()
{
    vector<int>v;
    v.reserve(100000);

    int *p = NULL;
    int num = 0;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << num << endl;
    //开辟100000次数据用了多少次空间
}

void test05()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    cout << v.front() << endl;//第一个值
    cout << v.back() << endl;//最后一个值

    //插入
    v.insert(v.begin(),2,100); //迭代器  N个数  具体插入的内容
    printVector(v);

    //尾删
    v.pop_back();
    printVector(v);

    v.erase(v.begin());//删除
    printVector(v);

    v.erase(v.begin(),v.end());//清空
    if(v.empty())
    {
        cout << "空" << endl;
    }

    v.clear();//清空
}

void test06()
{
    //逆序遍历
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }

    printVector(v);

    for(vector<int>::reverse_iterator it = v.rbegin();it != v.rend();it++)
    {
        cout << *it << endl;
    }
    
    //vector迭代器是随机访问的迭代器 支持跳跃式访问
    vector<int>::iterator itBegin = v.begin();
    itBegin = itBegin + 3;
    //如果上述写法不报错，这个迭代器式是随机访问迭代器
}

int main()
{
    testResize();
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    return 0;
}
