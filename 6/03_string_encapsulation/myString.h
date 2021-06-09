#pragma once 
#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class MyString
{
    friend ostream &operator<< (ostream &cout, MyString &str);
    friend istream &operator>> (istream &cin, MyString &str);
public:
    MyString(const char *str); //有参构造
    MyString(const MyString &str); //拷贝构造

    ~MyString();

    //重载=
    MyString& operator=(const char *str);
    MyString& operator=(const MyString& str);

    //重载[]
    char& operator[](int index);

    //operator +
    MyString operator+(const char *str);
    MyString operator+(const MyString &str);

    //operator ==
    bool operator==(const char *str);
    bool operator==(const MyString &str);

private:
    char * pString; //指向堆区的指针
    int m_Size; //字符串大小
};