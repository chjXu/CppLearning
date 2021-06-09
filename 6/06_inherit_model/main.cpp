#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son :public Base
{
public:
    int m_D;
};

class Base2
{
public:
    Base2(int a)
    {   
        this->m_A = a;
        cout << "有参构造调用" << endl;
    }

    int m_A;
};

class Son2: public Base2
{
public:
    Son2(int a):Base2(a)
    {

    }
};

void test01()
{
    cout << sizeof(Son) << endl; //结果为16,所以子类会继承父类的所有成员
}

void test02()
{
    Son2 s2(1000);
}

int main()
{
    test01();
    test02();
    return 0;
}