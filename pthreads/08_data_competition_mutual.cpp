#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;
mutex m;
/*
//并没有很好的解决竞争问题
void share_print(string msg, int id)
{
    //m.lock();   //加锁
    lock_guard<mutex> guard(m);
    cout << msg << id << endl;
    //如果这儿抛出异常，则m将永远被锁，此时不推荐lock
    //m.unlock(); //解锁
}
*/

class LofFile
{
public:
    LofFile(){
        f.open("log.txt");
    }

    void share_print(string id, int value)
    {
        lock_guard<mutex> locker(m_mutex);
        f << id << value  << endl;
    }

private:
    mutex m_mutex;
    ofstream f;
};

void function_1(LofFile &log)
{
    //cout << "Hello world!" << endl;
    for(int i=0; i>-10; i--)
    {
        //cout << "from func_1:" << i << endl;
        log.share_print("from func_1", i);
    }
}


int main()
{
    LofFile log;
    thread t1(function_1,ref(log));  //从func1里打印数字
    for(int i=0; i<10; i++)
    {
        //cout << "from main: " << i << endl;
        log.share_print("from main", i);
    }

    t1.join();

    //这里会出现2个线程抢占cout资源
    //创建share_print， 把函数输出改为调用

    return 0;
}