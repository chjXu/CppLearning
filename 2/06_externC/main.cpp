#include <iostream>
#include "test.h"
using namespace std;

//C++中想调用C中的方法

//extern "C" void show(); //show方法 按照C的方式做链接
//解决的问题就是在C++中调用C语言的函数

int main(){

    show(); //在C++函数是可以发生重载的，编译器会把这个函数名偷偷改变  _showv void

    return 0;
}