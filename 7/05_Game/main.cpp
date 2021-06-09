#include <iostream>
#include <stdio.h>
#include <ctime>
#include "hero.cpp"
#include "monster.cpp"
#include "weapon.h"
#include "knife.cpp"
#include "DragonSword.cpp"
using namespace std;

void play()
{
    //创建怪物
    Monster *monster = new Monster;
    //创建英雄
    Hero *hero = new Hero;
    //创建武器
    Weapon *knife = new Knife;
    Weapon *dragonSword = new DragonSword;


    //让用户选择武器
    cout << "请选择武器" << endl;
    cout << "1. 赤手空拳" << endl;
    cout << "2. 小刀" << endl;
    cout << "3. 屠龙刀" << endl;

    int oper;
    cin >> oper;
    switch (oper)
    {
    case 1:
        cout << "真牛，不要武器！" << endl;
        break;
    case 2:
        hero->EquipWeapon(knife);
        break;
    case 3:
        hero->EquipWeapon(dragonSword);
        break;
    default:
        break;
    }

    getchar(); //输入缓冲区有个回车， 多获取一次值
    int round = 1;

    while(true)
    {
        getchar();

        //system("cls");

        cout << "-----当前是第" << round << "回合-------" << endl; 

        if(hero->m_Hp < 0)
        {
            cout << "hero dead!, Game over!" << endl;
            break;
        }

        hero->Attack(monster);
        if(monster->m_Hp < 0)
        {
            cout << "怪物 dead!, 过关！" << endl;
            break;
        }

        monster->Attack(hero);
        if(hero->m_Hp <= 0)
        {
            cout << "hero dead!, Game over!" << endl;
            break;
        }

        cout << "英雄剩余血量" << hero->m_Hp << endl;
        cout << "怪物剩余血量" << monster->m_Hp << endl;

        round++;
    }

    delete monster;
    delete hero;
    delete knife;
    delete dragonSword;
}

int main()
{
    srand((unsigned int)time(NULL));
    play();
    return 0;
}