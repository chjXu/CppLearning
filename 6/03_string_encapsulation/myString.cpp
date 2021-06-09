#include "myString.h"

ostream& operator<< (ostream &cout,MyString &str)
{
    cout << str.pString;
    return cout;
}

istream& operator>> (istream &cin, MyString &str)
{
    //先判断 原始中是否有内容，如果有清空
    if(str.pString != NULL)
    {
        delete[] str.pString;
        str.pString =NULL;
    }

    //让用户输入内容
    char buf[1024];
    cin >> buf;

    //赋值
    str.pString = new char[strlen(buf) + 1];
    strcpy(str.pString, buf);
    str.m_Size = strlen(buf);

    return cin;

}

MyString::MyString(const char *str)
{
    this->pString = new char[strlen(str) + 1];//一般我们是不知道字符的长度，通常为结束符‘\0’分配一个字节,所以加1.
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
}

MyString::MyString(const MyString &str)
{
    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString, str.pString);
    this->m_Size = str.m_Size;

}

MyString::~MyString()
{
    if(this->pString != NULL)
    {
        delete[] this->pString;
        this->pString = NULL;
    }
}

MyString& MyString::operator=(const char *str)
{
    if(this->pString != NULL)
    {
        delete[] this->pString;
        this->pString = NULL;
    }

    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString, str);

    return *this;
}

MyString& MyString::operator=(const MyString& str)
{
    if(this->pString != NULL)
    {
        delete[] this->pString;
        this->pString = NULL;
    }

    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString, str.pString);

    return *this;
}

char& MyString::operator[](int index)
{
    return this->pString[index];
}

MyString MyString::operator+(const char *str)
{
    //计算返回字符串的大小
    int newSize = this->m_Size + strlen(str) + 1;

    char * tmp = new char[newSize];

    memset(tmp,0,newSize);

    //拼接字符串
    strcat(tmp,this->pString);
    strcat(tmp,str);

    MyString newStr(tmp);
    delete[] tmp;
    return newStr;

}

MyString MyString::operator+(const MyString &str)
{
    //计算返回字符串的大小
    int newSize = this->m_Size + strlen(str.pString) + 1;

    char * tmp = new char[newSize];

    memset(tmp,0,newSize);

    //拼接字符串
    strcat(tmp,this->pString);
    strcat(tmp,str.pString);

    MyString newStr(tmp);
    delete[] tmp;
    return newStr;
}

bool MyString::operator==(const char *str)
{
    if(strcmp(this->pString,str) == 0 && this->m_Size == strlen(str))
    {
        return true;
    }else
    {
        return false;
    }
    
}

bool MyString::operator==(const MyString &str)
{
    if(strcmp(this->pString,str.pString) == 0 && this->m_Size == strlen(str.pString))
    {
        return true;
    }else
    {
        return false;
    }
}