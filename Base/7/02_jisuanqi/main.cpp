#include <iostream>

using namespace std;
//普通版//
/*
class Calculator
{
public:
    void setval(int v1, int v2)
    {
        this->value_1 = v1;
        this->value_2 = v2;
    }

    int getResult(string oper)
    {
        if(oper == "+")
        {
            return value_1 + value_2;
        }
        else if(oper == "-")
        {
            return value_1 - value_2;
        }
        else if(oper == "*")
        {
            return value_1 * value_2;
        }
        else if(oper == "/")
        {
            return value_1/value_2;
        }
        else
        {
            cout << "invalid number!" << endl;
        }
        
    }
    int value_1;
    int value_2;

};
*/

class AbstractCalculator
{
public:
    //虚函数 virtual int getResult(){return 0;}

    //纯虚函数
    //如果父类中有了 纯虚函数 子类继承父类 就必须要实现 纯虚函数
    //如果父类中 有了 纯虚函数， 这个父类 就无法实例化对象了
    //这个类有了纯虚函数， 通常又称为 抽象类

    virtual int getResult() = 0;
    void setval(int v1, int v2)
    {
        this->val1 = v1;
        this->val2 = v2;
    }


 
    int val1;
    int val2;
};
class A:public AbstractCalculator
{
public:
    virtual int getResult()
    {
        cout << " " << endl;
    }

};

//加法
class Plus: public AbstractCalculator
{
    virtual int getResult()
    {
        return val1 + val2;
    }

};

//减
class Sub: public AbstractCalculator
{
    virtual int getResult()
    {
        return val1 - val2;
    }
};

//假如现在需要乘法
class Mul: public AbstractCalculator
{
    virtual int getResult()
    {
        return val1 * val2;
    }
};

void test01()
{
    AbstractCalculator * abc;
    abc = new Plus;

    abc->setval(10,20);
    cout << abc->getResult() << endl;

    delete abc;

    abc = new Sub;
    abc->setval(1,2);
    cout << abc->getResult() << endl;
    delete abc;

    abc = new Mul;
    abc->setval(10,20);
    cout << abc->getResult() << endl;
    
}

void test02()
{
    //如果父类中 有了 纯虚函数， 这个父类 就无法实例化对象了
    //AbstractCalculator aaa;
    //AbstractCalculator *abc = new abstractCalculator;
}
//真正的开发中，有个开发原则 开闭原则
//对扩展开放  对修改关闭

int main()
{
    test01();
    test02();
    return 0;
}