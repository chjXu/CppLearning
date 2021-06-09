#pragma once
#include <iostream>
using namespace std;

class myArray
{
private:
    int *pAddress;//指向真正存储数据的指针
    int m_Size;
    int m_Capacity;
public:
    myArray();//默认构造
    myArray(int capacity);
    myArray(const myArray& array);//拷贝构造
    ~myArray();

    //尾插法
    void push_back(int val);

    //根据索引获取值
    int getData(int index);

    //根据索引设置值
    void setData(int index,int val);

    //获取数组大小
    int getSize();
    //获取数组容量
    int getCapacity();
};
