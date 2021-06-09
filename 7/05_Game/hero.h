#pragma once
#include <iostream>
#include <string>
#include "weapon.h"
using namespace std;

class Monster;

class Hero
{
public:
    string m_Name; //人名
    int m_Atk;  //攻击力    
    int m_Def;  //防御力
    int m_Hp;   //血量
    
    Hero();

    Weapon *weapon; //武器

    void EquipWeapon(Weapon *weapon);

    void Attack(Monster *monster);
};