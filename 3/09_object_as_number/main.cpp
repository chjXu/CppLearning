#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
    Phone()
    {
        cout << "手机的默认构造函数的调用" << endl;
    }

    Phone(string name)
    {
        m_PhoneName = name;
        cout << "Phone的有参构造函数" << endl;
    }

    ~Phone()
    {
        cout << "手机的默认析构函数的调用" << endl;
    }


    string m_PhoneName;

};

class Game
{
public:
    Game()
    {
        cout << "Game的默认构造函数的调用" << endl;
    }

    Game(string name)
    {
        m_GameName = name;
        cout << "Game的有参构造函数" << endl;
    }

    ~Game()
    {
        cout << "Game的默认析构函数的调用" << endl;
    }

    string m_GameName;
};

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数的调用" << endl;
    }

    Person (string name,string phoneName,string gameName):m_Name(name),m_Phone(phoneName),m_Game(gameName)
    {
        //m_Name = name;
        cout << "Person的有参构造函数" << endl;  
    }

    void palygame()
    {
        cout << m_Name << "拿着" << m_Phone.m_PhoneName << "手机" << m_Game.m_GameName << "游戏" << endl;
    }

    ~Person()
    {
        cout << "Person的默认析构函数的调用" << endl;
    }

    string m_Name; //姓名
    Phone m_Phone; //手机
    Game m_Game; //游戏
};

//类对象作为成员的时候，构造顺序现将类对象一一构造，然后析构的顺序是相反的

void test01()
{
    //Person p;
    //p.m_Phone.m_PhoneName = "三星";
    //p.m_Game.m_GameName = "斗地主";
    Person p("狗蛋","苹果","王者");
    p.palygame();
}

int main()
{
    test01();
    return 0;
}