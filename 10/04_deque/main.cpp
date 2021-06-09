#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
/*
双端队列(deque)是一种随机的数据类型，提供了在序列两端快速插入和删除操作的功作，它可以在需要的时候修改其自身的大小，主要完成标准C++数据结构中队列的功能。

使用双端队列类模板需要创建deque对象，创建deque对象有以下几种方法：

（1）std::deque<type>name;

该方法创建一个名为name空间的空deque对象，该对象可容纳数据类型为type的数据。例如：为整型值创建一个空std::deque对象可以使用这样的语句：

std::deque<int>deque;

（2）std::deque<type>name(size);

该方法创建一个大小为size的deque对象。

（3）std::deque<type>name;(size,value);

该方法创建一个大小为size的deque对象，并将对象的每个值设为value。

（4）std::deque<type>name(mydeque);

该方法使用复制构造函数，用现有的双端队列mydeque创建一个deque对象。

（5）std::deque<type>name(first,last);

该方法创建了元素在指定范围内的双端队列，first代表起始范围，last代表结束范围。

deque的成员函数和vector的成员函数用法基本一样

1.构造函数

explicit deque ( const Allocator& = Allocator() );

explicit deque ( size_type n, const T& value= T(), const Allocator& = Allocator() );

template <class InputIterator>

deque ( InputIterator first, InputIterator last, const Allocator& = Allocator() );

deque ( const deque<T,Allocator>& x );

2.虚构函数

~deque ( );

3.重载了=符号

deque<T,Allocator>& operator= ( const deque<T,Allocator>& x );

4.deque::begin()

iterator begin ();

const_iterator begin () const;

5.deque::end()

iterator end ();

const_iterator end () const;

6.deque::rbegin()

reverse_iterator rbegin();

const_reverse_iterator rbegin()  const;

7.deque::rend()

reverse_iterator rend();

const_reverse_iterator rend() const;

8.deque::size()

size_type size() const;

9.deque::max_size()

size_type max_size () const;

10.deque::resize()

void resize ( size_type sz, T c = T() );

11.deque::empty()

bool empty ( ) const;

12.deque::operator[] //用于下标访问元素

reference operator[] ( size_type n );

const_reference operator[] ( size_type n ) const;

13.deque::at()

const_reference at ( size_type n ) const;

reference at ( size_type n );

14.deque::front()

reference front ( );

const_reference front ( ) const;

15.deque::back()

reference back ( );

const_reference back ( ) const;

16.deque::assign()

template <class InputIterator>

void assign ( InputIterator first, InputIterator last );

void assign ( size_type n, const T& u );

17.deque::push_back()

void push_back ( const T& x );

18.deque::push_front() //从前面插入元素

void push_front ( const T& x );

19.deque::pop_back()

void pop_back ( );

20.deque::pop_front() //从首位置删除元素

void pop_front ( );

21.deque::insert()

iterator insert ( iterator position, const T& x );

void insert ( iterator position, size_type n, const T& x );

template <class InputIterator>

void insert ( iterator position, InputIterator first, InputIterator last );

22.deque::erase()

iterator erase ( iterator position );

iterator erase ( iterator first, iterator last );

23.deque::swap()

iterator erase ( iterator position );

iterator erase ( iterator first, iterator last );

24.deque::clear()

void clear ( );
*/

void printDeque(const deque<int> &d)    //const_iterator只读迭代器
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        //*it = 10000;
        cout << *it << " ";
    }
    cout << endl;
}
//1.基础操作
void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    printDeque(d);
    
    deque<int> d2(d.begin(), d.end());
    d2.push_back(10000);
    d.swap(d2);
    printDeque(d);

    if(d2.empty())
    {
        cout << "is_empty" << endl;
    }
    else
    {
        cout << "isn't_empty   " << d.size() << endl;
    }
    
}

//2.
void test02()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.push_front(100);  //头插
    d.push_front(200);
    printDeque(d);

    //头删 尾删
    d.pop_back();
    d.pop_front();
    printDeque(d);

    cout << "front  " << d.front() << endl;
    cout << "back  " << d.back() << endl;

    //插入
    deque<int> d2;
    d2.push_back(50);
    d2.push_back(60);
    d2.insert(d2.begin(), d.begin(), d.end());
    printDeque(d2);

}

//排序规则
bool myCompare(int v1, int v2)
{
    return v1>v2;
}

void test03()
{
    deque<int> d;
    d.push_back(20);
    d.push_back(5);
    d.push_back(10);
    d.push_back(30);
    d.push_back(50);
    printDeque(d);

    //sort
    sort(d.begin(),d.end());
    printDeque(d);

    sort(d.begin(), d.end(),myCompare);
    printDeque(d);
}

int main()
{
    //test01();
    //test02();

    test03();
    return 0;
}