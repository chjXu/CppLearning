#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>

void test01()
{
    string str; //默认构造
    string str2(str); //拷贝构造
    string str3 = str;

    string str4 = "abcd";
    string str5(10,'a');
    cout << str4 << endl;
    cout << str5 << endl;

    //基本赋值
    str ="hello";
    str2 = str4;

    //string assign(const char*,int n)
    str3.assign("abcdef",4);
    cout << str3 << endl;

    //string assign(const string &s,int start,int n)
    string str6;
    str6.assign(str,2,5);
    cout << str6 << endl;

    
}

void test02()
{
    string s = "hello world";
    for(int i=0;i<s.size();i++)
    {
        //cout << s[i] << endl;
        cout << s.at(i) << endl;
    }

    //[]和at区别 []访问越界 会直接挂掉  at会抛出异常
    try
    {
        cout << s.at(100) << endl;
    }
    catch(out_of_range & e)
    {
        cout << e.what() << endl;
    }
    
}

void test03()
{
    //1.string 拼接
    string s1 = "我";
    string s2 = "爱北京";
    s1 += s2;
    //cout << s1 << endl;
    
    s1.append("天安门");
    //cout << s1 << endl;

    //2.find查找和替换
    string s = "abcdefg";
    int pos = s.find("bcf");//找不到返回-1
    cout << "pos= " << pos << endl;

    int pos2= s.rfind("bc");//rfind虽然是从后往前查，但是结果不会变的
    cout << "pos2= " << pos2 << endl;

    //替换
    string s3 = "hello";
    s3.replace(1,3,"111111111");
    cout << s3 << endl;
}

void test04()
{
    //1.比较
    string s1 = "abc";
    string s2 = "abb";
    if(s1.compare(s2) == 0)
    {
        cout << "s1=s2" << endl;
    }
    else if (s1.compare(s2)==1)
    {
        cout << "s1>s2" << endl;
    }
    else
    {
        cout << "s1<s2" << endl;
    }
    
}

void test05()
{
    //子串
    string s1 = "abcd";
    string s2 = s1.substr(1,3);
    cout << "s2 = " << s2 << endl;

    //需求 查找一个邮件的 用户名
    string email = "zhangtao@sina.com";
    int pos = email.find("@");
    string s3 = email.substr(0,pos);
    cout << s3 << endl;
}

void test06()
{
    //插入和删除
    string s1 = "hello";
    s1.insert(1,"111");
    cout << s1 << endl;
    s1.erase(1,3);//位置 ， 个数
    cout << s1 << endl;
}

void func(string s)
{
    cout << s << endl;
}

void fuc2(char *s)
{
    cout << s << endl;
}
void test07()
{
    string s = "abc";
    const char * p = s.c_str();
    func(p);//const char * 隐式类型转化成string
    string s2(p);
    //func2(s2);//string 不能隐式转化成char *

}

void test08()
{
    //将小写字母写成大写
    string s= "abcDeFg";
    /*
    for(int i=0;i<s.size();i++)
    {
        s[i] = toupper(s[i]);
    }
    cout << s << endl;*/

    for(int i=0;i<s.size();i++)
    {
        s[i] = tolower(s[i]);
    }
    cout << s << endl;
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();
    return 0;
}