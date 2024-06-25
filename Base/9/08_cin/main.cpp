#include <iostream>
using namespace std;

void test01()
{
    char c = cin.get();
    cout << "c=" << c << endl;

    char d = cin.get();
    cout << "d=" <<  d << endl;
}

void test02()
{
    char buf[1024];
    cin.get(buf,1024);
    cout << buf << endl;

    char c = cin.get(); //获取回车
    if(c = '\n')
    {
        cout << "换行还在缓冲区" << endl;
    }else
    {
        cout << "不在缓冲区" << endl;
    }
    cout << buf << endl;
    
}

//cin.getline()  把换行符读取并扔掉
void test03()
{
    char buf[1024];
    cin.getline(buf,1024);
    
    char c = cin.get();
    if(c = '\n')
    {
        cout << "换行还在缓冲区" << endl;
    }else
    {
        cout << "不在缓冲区" << endl;
    }
    //cout << buf << endl;
}

//cin.ignore()
void test04()
{
    cin.ignore();//没有参数 代表忽略一个字符
    cin.ignore(2);//忽略2个字符

    char c = cin.get();
    cout << "c=" << c << endl;
}

//cin.peek()
void test05()
{
    char c = cin.peek();    //偷看一眼第一个字符，在放回缓冲区
    cout << "c=" << c << endl;

    c = cin.get();
    cout << "c=" << c << endl;
}

//cin.putback()
void test06()
{
    char c = cin.get();
    cin.putback(c);

    char buf[1024];
    cin.getline(buf, 1024);
    cout << buf << endl;
}
//案例1 判断用户输入的是字符串 还是数字
void test07()
{
    cout << "请输入：" << endl;
    //
    char c = cin.peek();
    if(c >= '0' && c <= '9')
    {
        int num;
        cin >> num;
        cout << "Num: " << num << endl;
    }
    else
    {
        char buf[1024];
        cin >> buf;
        cout << "Str:" << buf << endl;
    }
    
}
//案例2 让用户输入 1 到 10的数字，如果输入有误，请重新输入
void test08()
{
    cout << "please enter a num:" << endl;
    int num;
    while (true)
    {
        cin >> num;
        if(num > 0 && num <= 10)
        {
            cout << "Num is : " << num << endl;
            break;
        }

        cout << "please enter again!" << endl;

        

        //重置标志位
        cin.clear();
        cin.sync();

        //cout << "标志位: " << cin.fail() << endl;   //标志位0为正常，1不正常
    }
    
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