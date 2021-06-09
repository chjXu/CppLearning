#include <iostream>
using namespace std;
/*
//定义一个加法
//直接定义为x+y的话，结果是错的
//总的来说，宏定义有以下缺陷
    1.结果错误，加上括号可能解决问题，也可能解决不了问题
    2.宏函数没有作用域
    3.故引出内联函数

*/
#define MyAdd(x,y) ((x)+(y))

#define MyCompare(a,b) a<b ? a:b

inline void compare(int a,int b){
    int ret = a<b? a : b;
    cout << "ret :::::" << ret <<endl;
}

//1.内联函数注意事项
inline void func();//声明内联函数
inline void func() { } //内联函数使用时，也要加上inline，不然系统默认和普通函数一样
/*  
//2.类中的成员函数默认添加inline关键字
//3.以下情况不考虑内联
    1）.不存在任何的循环语句
    2）.不存在过多的条件判断语句
    3）.函数体不能太过庞大
    4）.不能对函数进行取址操作
//4.一般好的编译器会内联小的、简单的函数
*/
void test01()
{
    int ret = MyAdd(10,20) *20;
    cout << "ret is " << ret <<endl;
}

void test02(){
    int a =10;
    int b =20;
    int ret_2 = MyCompare(++a,b);
    cout << "ret_2 is " << ret_2 << endl;
}

int main(){

    //test01();
    //test02();
    compare(10,20);
    return 0;
}