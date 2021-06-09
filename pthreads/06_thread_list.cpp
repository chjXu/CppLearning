#include <iostream>
#include <thread>
#include <list>
#include <mutex>
using namespace std;

class A
{
public:
	//把收到的玩家消息（命令）入到一个队列的线程
	void inMseRevcQueue()
	{
		for (int i = 0; i < 10000; ++i)
		{
			cout << "inMseRevcQueue()插入一个元素" << i << endl;
			mseRecvQueue.push_back(i);//假设i就是收到的命令
		}
	}
	//把数据从消息队列中取出的线程
	void outMseRevcQueue()
	{
		for (int i = 0; i < 10000; i++)
		{
			if (!mseRecvQueue.empty())
			{
				int command = mseRecvQueue.front();//取第一个元素
				mseRecvQueue.pop_front();//删除第一个元素
			}
			else
			{
				cout << "outMseRevcQueue()执行，但是当前消息队列为空" << i << endl;
			}
		}
	}
protected:
private:
	mutex my_mutex;
	list<int> mseRecvQueue;//玩家命令队列
};

int main()
{
	A myobj;
	thread myInObj(&A::inMseRevcQueue, &myobj);
	thread myOutObj(&A::outMseRevcQueue, &myobj);//第二个参数引用，保证线程里是同一个对象

	myInObj.join();
	myOutObj.join();

    
	return 0;
}
