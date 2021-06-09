#include <iostream>
using namespace std;
//创建主席类
//需求 单列模式 为了创建类中的对象，并保证只有一个对象实例
class ChairMan
{
//构造函数私有化
private:
    static ChairMan * singleMan;
    ChairMan(const ChairMan& c);
   
    ChairMan()
    {
        cout << "创建国家主席" << endl;
    }
public:
    //static ChairMan * singleMan;
    //提供get
    static ChairMan* getInstance()
    {
        return singleMan;
    }
};
ChairMan * ChairMan::singleMan = new ChairMan;
void test01()
{
    //这儿创建三个对象，与单例需求不同，解决方法将构造函数私有化
    /*
    ChairMan c1;
    ChairMan *c2 = new ChairMan;
    ChairMan *c3 = new ChairMan;
    */
   
   //ChairMan * cm = ChairMan::singleMan;
   //ChairMan::singleMan = NULL;
   
   ChairMan* cm1 = ChairMan::getInstance();
   ChairMan* cm2 = ChairMan::getInstance();
   if(cm1 == cm2)
   {
       cout << "cm1 = cm2" << endl;
   }
   else
   {
       cout << "cm1 != cm2" << endl;
   }
   /*ChairMan* cm3 = new ChairMan(*cm2);
    if(cm3 == cm2)
   {
       cout << "cm3 = cm2" << endl;
   }
   else
   {
       cout << "cm3 != cm2" << endl;
   }*/

}
int main()
{
    //cout << "main调用" << endl;//主席先于main的调用
    test01();
    return 0;
}
