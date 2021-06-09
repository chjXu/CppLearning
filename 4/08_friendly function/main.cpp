#include <iostream>
#include <string>
using namespace std;

class Building
{
    //让全局函数能够访问 私有变量  友元函数
    friend void goodGay(Building *building);
public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }
    //客厅
    string m_SittingRoom;

private:
    //卧室
    string m_BedRoom;
};

void goodGay(Building *building)
{
    cout << "好鸡友正在访问" << building->m_SittingRoom << endl;
    cout << "好鸡友正在访问" << building->m_BedRoom << endl;
}

void test01()
{
    Building *building = new Building;
    goodGay(building);
}


int main()
{
    test01();
    return 0;
}