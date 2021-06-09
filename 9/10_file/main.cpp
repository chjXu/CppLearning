#include <iostream>
using namespace std;
#include <fstream>

void test01()
{
    //以输出的方式打开文件
    //ofstream ofs("./test.txt", ios::out | ios::trunc);

    ofstream ofs;
    ofs.open("./test.txt", ios::out | ios::trunc);
    if(!ofs.is_open())
    {
        cout << "open failed" << endl;
    }

    ofs <<"姓名：abc" << endl;
    ofs <<"年龄：100" << endl;
    ofs <<"性别：男" << endl;
    ofs.close();
}

//read
void test02()
{
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    if(!ifs.is_open())
    {
        cout << "open failed" << endl;
    }
    //1.
    /*char buf[1024];
    while (ifs >> buf)  //按行读
    {
        cout << buf << endl;
    }*/
    
    //2.
    /*char buf[1024];
    while (!ifs.eof())   //eof是否读到尾？
    {
        ifs.getline(buf, sizeof(buf));
        cout << buf << endl;
    }*/
    
    //3.不推荐
    char c;
    while (c=ifs.get() != EOF)
    {
        cout << c;
    }
    
    ifs.close();
}

int main()
{
    //test01();
    test02();
    
    return 0;
}