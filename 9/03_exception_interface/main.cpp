#include <iostream>
using namespace std;
//该代码能在Qt and linux环境下运行
//异常接口声明
void func() throw(int)  //throw()不抛出任何异常
{
    throw 1;
    //throw 3.14;
}

int main()
{
    try
    {
        func();
    }
    catch(int)
    {
        std::cout << "int" << endl;
    }
    catch(...)
    {
        cout << "else" << endl;
    }
    

    
    return 0;
}