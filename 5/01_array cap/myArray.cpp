#include "myArray.h"

myArray::myArray()
{
    cout << "构造函数调用" << endl;
    this->m_Capacity = 100;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

myArray::myArray(int capacity)
{
    cout << "有参构造函数调用" << endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

myArray::myArray(const myArray& array)
{
    cout << "拷贝构造调用" << endl;
    this->pAddress = new int[array.m_Capacity];
    this->m_Size = array.m_Size;
    this->m_Capacity = array.m_Capacity;

    for(int i=0;i<array.m_Size;i++)
    {
        this->pAddress[i] = array.pAddress[i];
    }
}

myArray::~myArray()
{
    if(this->pAddress != NULL)
    {
        cout << "析够函数调用" << endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}

void myArray::push_back(int val)
{
    //判断越界？用户自己处理
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
}

int myArray::getData(int index)
{
    return this->pAddress[index];
}

void myArray::setData(int index, int val)
{
    this->pAddress[index] = val;
}

int myArray::getSize()
{
    return this->m_Size;
}

int myArray::getCapacity()
{
    return this->m_Capacity;
}