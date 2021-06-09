#include <iostream>
#include <thread>
#include <string>

using namespace std;

void function_1()
{
    cout << "Hello world!" << endl;

    cout << "from func_1:" << "Hello world" << endl;

}

class Factor
{
public:
    void operator()(string msg)
    {
        cout << "from t2: " << msg << endl;
        msg = "I love vs";
    }
};

int main()
{
    string s = "I love C++";
    cout << this_thread::get_id() << endl;
    thread t1(function_1);  //从func1里打印数字
    cout << t1.get_id() << endl;
    thread t2(Factor(),move(s));  //用引用的方式效率高
    cout << t2.get_id() << endl;
    //t1.detach();  
    try{

        cout << "from main:" << s << endl;
        
    }
    catch(...)
    {
        t1.join();
        t2.join();
        throw;
    }

    thread t3 = move(t2);   //移动完成后，t2为空
    cout << t3.get_id() << endl;
    t1.join();    //等待线程完成
    //t2.join();
    t3.join();

    thread::hardware_concurrency(); //根据硬件设备分配线程数

    return 0;
}