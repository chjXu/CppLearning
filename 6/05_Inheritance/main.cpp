#include <iostream>

using namespace std;
//总结：不管公有、保护、私有继承方式，基类中的私有属性，都不可以继承下去
//公有继承 ：
    //父类中是public,子类中还是public
    //父类中是protected,子类中还是protected
//保护继承：
    //父类中是public,子类中是protected
    //父类中是protected,子类中还是protected
//私有继承
    //父类中是public,子类中是private
    //父类中是protected,子类中还是private  

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
///////////////////////////////////公有继承///////////////////////////////
class Son1 :public Base1
{
public:
    void func()
    {
        //cout << m_C << endl; //不可访问私有变量
        cout << m_A << endl; //基类中公有，可继承，为public
        cout << m_B << endl; //基类中保护，可继承，为protected 类外保护
    }
};
/////////////////////////////////保护继承///////////////////////////
class Son2 :protected Base2
{   
public:
    void func2()
    {
        //cout << m_C << endl; //不可访问私有变量
        cout << m_A << endl;    //基类中公有，可继承，为protected
        cout << m_B << endl;    //基类中保护，可继承，为protected
    }

};

////////////////////////////////私有继承////////////////////////////
class Son3 :private Base3
{
public:
    void func3()
    {
        cout << m_A << endl;//基类中公有，可继承，为private
        cout << m_B << endl;//基类中保护，可继承，为private
        //cout << m_C << endl;//不可访问私有变量
    }
};

void test01()
{
    Son1 son1;
    son1.func();
    son1.m_A;
    //son1.m_B; //不可访问
    //son1.m_C; //不可访问
}

void test02()
{
    Son2 son2;
    son2.func2();
    //son2.m_A; //不可访问
    //son2.m_B; 不可访问
    //son2.m_C; //不可访问
}

void test03()
{
    Son3 son3;
    son3.func3();
    //son3.m_A;//不可访问
    //son3.m_B;//不可访问
    //son3.m_C;//不可访问
}


int main()
{
    test01();
    test02();
    test03();

    return 0;
}