#include <iostream>
#include "myString.h"
#include "myString.cpp"

using namespace std;

void test01()
{
    MyString str = "abc";
    /*
    cout << str << endl;

    cout << "请输入新的字符：" << endl;
    cin >> str;
    cout << "新的内容为：" << str << endl;
    */

    MyString str2(str);

    MyString str3 = "aa";

    str3 = str2;
    str3 = "aaaa";

    cout << "str3 = :" << str3 << endl;

    cout << "str3 第一个位置的字符是：" << str3[0] << endl;

    MyString str4 = " ";
    str4 = str2 + str3;
    cout << "str4=:" << str4 << endl;

    if(str3 == str4)
    {
        cout << "str3 == str4" << endl;
    }else
    {
        cout << "str3 != str4" << endl;
    }
    
}

int main()
{
    test01();
    return 0;
}