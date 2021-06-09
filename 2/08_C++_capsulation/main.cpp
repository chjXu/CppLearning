#include <iostream>
#include <string.h>
using namespace std;

struct Person
{
    /* data */
    char mName[60];

    int mAge;

    void PersonEat()
    {
        cout << mName << "吃人饭" <<endl;
    }
};

struct Dog
{
    /* data */
    char mName[60];

    int mAge;

    void DogEat()
    {
        cout << mName << "吃狗粮" <<endl;
    }
};

//C++中的封装 严格类型转换检测，让属性和行为绑在一起
//1.属性和行为作为一个整体来表示生活中的事物
//2.控制权限 public protected private
void test01()
{
    Person p1;
    strcpy(p1.mName,"老王");
    p1.PersonEat();
   // p1.DogEat();
}

//struct 和 class 是一个意思，惟一的不同 默认权限 ，struct 是public，class是 private.
class Animal
{
    void eat()
    {
        nAge = 100;
    }

        int nAge;
    public:
        int mHigh;

    protected: //保护权限，类内部可以访问，（当前的子类可以访问），类外部不能访问
        int mWeight;
    
    void setWeigh()
    {
        mWeight = 100;
    }
};

void test02()
{
    Animal an;
    //所谓私有权限，就是私有成员(属性，函数) 在类的内部可以访问，外部不能访问
    //an.eat();
    an.mHigh = 1000;
    //保护权限内外不能访问
    //an.mWight();
}
//所谓公共权限，就是外部和内部都可以访问

//public 类内 类外 都可以访问
//protected 类内可以访问 类外 不可以访问（子类可以访问）
//private 类内可以访问，类外 不可以访问（子类不可以访问）

int main(){

    test01();

    return 0;
}