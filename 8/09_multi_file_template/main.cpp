#include <iostream>
using namespace std;
#include "Person.hpp"

//建议 模板不要分文件编写 即.h and .cpp 文件
//可以把.cpp文件里的实现加到.h文件中， 然后改为.hpp文件


int main()
{

    //#include“Person.h” 无法调用，可用#include “Person.cpp” (不推荐)
    Person<string, int> person("MT", 20);
    person.show();
    
    
    
    return 0;
}