#include <iostream>
using namespace std;
#include "myArray.h"
#include "myArray.cpp"

void test01()
{
    //堆区创建数组
    myArray *array = new myArray(30);
    myArray *array2 = new myArray(*array);
    myArray array3 = *array;

    

    for(int i=0;i<10;i++)
    {
        array2->push_back(i);
    }
    //获取数据测试
    for(int i=0;i<10;i++)
    {
        cout << array2->getData(i)<< endl;
    }

    //设置值的测试
    array2->setData(0,100);

    cout << array2->getData(0) << endl;

    //获取数组大小
    cout << array2->getSize() << endl;
    //获取数组容量
    cout << (*array2).getCapacity() << endl;



    delete array;
}


int main(){

    test01();
    return 0;
}
