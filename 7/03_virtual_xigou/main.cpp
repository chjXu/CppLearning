#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speaking!" << endl;
    }
   
/*
    virtual ~Animal()
    {
        cout << "Animal xigou!" << endl;
    }
*/

    //纯虚析构
    //纯虚析构，需要声明，还要实现。 类内声明，类外实现
    //如果函数中出现 纯虚析构函数， 那么这个类也算抽象类
    //抽象类 不可实例化
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    cout << "Animal 纯虚析构!" << endl;
}

class Cat:public Animal
{
public:
    Cat(const char* name)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, m_Name);
    }

    virtual void speak()
    {
        cout << "Cat speaking!" << endl;
    }

    //普通析构， 是不会调用子类的析构， 所以导致释放不干净
    //利用虚析构(父类)来解决这个问题
    ~Cat()
    {
        cout << "Cat xigou!" << endl;
        if(this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }
    char * m_Name;
};



void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();

    delete animal;
}

int main()
{
    test01();
    return 0;
}