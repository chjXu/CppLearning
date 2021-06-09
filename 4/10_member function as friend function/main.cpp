#include <iostream>
#include <string>
using namespace std;

//只让visit可以访问私有属性
class Building;
class GoodGay
{
public:
    GoodGay();

    void visit();
    void visit2();
private:
    Building * building;
};

class Building
{
    //让全局函数能够访问 私有变量  友元函数
    friend void GoodGay::visit();
     
public:
    Building();
    //客厅
    string m_SittingRoom;

private:
    //卧室
    string m_BedRoom;
};

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "好鸡友正在访问" << building->m_SittingRoom << endl;
    cout << "好鸡友正在访问" << building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
    cout << "好鸡友正在访问" << building->m_SittingRoom << endl;
    //cout << "好鸡友正在访问" << building->m_BedRoom << endl;
}



Building::Building()
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}
void test01()
{
    GoodGay g1;
    g1.visit();
    g1.visit2();
}


int main()
{
    test01();
    return 0;
}