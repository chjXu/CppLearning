#include <iostream>
#include <string>
#include "Person.hpp"
//#include "Person.cpp"
using namespace std;

//建议  模板不要做分文件编写，写到一个类中即可,类内进行声明和实现，最后把后缀名改为.hpp 约定俗成
int main()
{
    Person<string, int> p("猪八戒", 10);
    p.showPerson();
    return 0;
}