#include <iostream>
#include <string>
using namespace std;
//对于属性，建议大家都设置为私有，自己提供对外接口进行 set 和 get.

class Person
{
    public:
    //设置年龄
    //void setAge(int age)
    //{
    //    mAge = age;
    //}
    //写年龄
    void setAge(int age)
    {
        if(age < 0 || age > 100)
        {
            cout << "你这个老妖精" << endl;
            return;
        }
        mAge = age;
    }

    //获取年龄 读权限
    int getAge()
    {
        return mAge;
    }

    //读姓名
    string getName()
    {   
        return m_Name;
    }
    //写姓名
    void setName(string name)
    {
        m_Name = name;
    }

    //写姓名
    void setLover(string lover)
    {
        m_lover = lover;
    }
    private: //内外不可访问
        int mAge = 0;//年龄 只读
        string m_lover;//读写权限
        string m_Name;//只写
};

void test01()
{
    Person p1;
    //p1.mAge;
    //p1.setAge(10);
    p1.setName("老王");
    p1.setAge(120);
    cout << "p1的姓名是: " << p1.getName() << endl;

    //年龄
    cout << "p1的年龄是: " << p1.getAge() << endl;

    //情人 只能设置
    p1.setLover("藏进");

}

int main(){

    test01();

    return 0;
}