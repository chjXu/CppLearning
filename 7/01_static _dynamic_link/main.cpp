//静态和动态的区别就是函数地址的早绑定（静态）和晚绑定（动态）
/*
*多态原理解析：
*   1.当父类中有了虚函数后，内部结构发生了改变
*   2.产生一个vfprt（虚函数表指针），指向虚函数表
*   3.父类中结构， vfprt 记录&Animal::speak（）
*   4.子类中结构， 进行继承
*   5.构造函数中 会将虚函数表指针 指向自己的虚函数表
*   6.如果发生了重写，会替换掉虚函数列表中原有的speak，改为 &Cat::speak（）
*   7.cat eat fish (编译器的调用过程)
*/
#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak() //父类virtual关键字 必须写 
    {
        cout << "animal speak" << endl;
    }

    virtual void eat()
    {
        cout << "animal eat!" << endl;
    }
};

class Cat:public Animal
{
public:
    virtual void speak()  //子类virtual关键字 可写可不写
    {
        cout << "cat speak!" << endl;
    }

    virtual void eat()
    {
        cout << "cat eat fish!" << endl;
    }
};

//调用dospeak， speak的地址早就绑定好了
//静态联编，编译阶段就确定好了地址
//如果调用猫的speak，就不能提前绑定地址了
void dospeak(Animal &animal) 
{
    animal.speak();
}

//动态联编，就是把静态联编的函数变成虚函数，发生了多态
//父类的引用或指针 指向子类对象


//如果发生继承，编译器允许进行类型转换
void test01()
{
    Animal animal;
    Cat cat;
    dospeak(animal);
    dospeak(cat);
}

void test02()
{
    Animal *animal = new Cat; //父类的指针指向子类
    //cout << sizeof(Animal) << endl;
    animal->speak();


    //cat eat add
    ((void(*)()) (*((int*)*(int*)animal+1)))();

}

int main()
{
    //test01();
    test02();
    return 0;
}