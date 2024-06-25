#include <iostream>
using namespace std;
/*
设计一个学生类，属性有学号和姓名，可以给姓名和学号赋值，可以显示学生的姓名和学号
*/
class Student
{

public:
    //设置姓名和学号
    void setname(string name)
    {
        m_Name = name;
    }
    void setid(int id)
    {
        m_Id = id;
    }

    void showinfo()
    {
        cout << "姓名：" << m_Name << "  " << "学号：" << m_Id <<endl;
    }

    string m_Name;
    int m_Id;

};
void test01(){
//实例化--通过类来创建对象的过程
    Student s;
    s.setname("张三");
    s.setid(1);
    s.showinfo();
    cout << "name is:  " << s.m_Name << "number is： " << s.m_Id << endl;
 }
int main(){

    test01();

    return 0;
}