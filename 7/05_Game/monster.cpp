#include "monster.h"
#include "hero.h"

Monster::Monster()
{
    this->m_Hp = 500;
    this->m_Atk = 70;
    this->m_Def = 40;
    this->m_Name = "哥斯拉";
}

//攻击
void Monster::Attack(Hero *hero)
{
    if(this->m_Hold)
    {
        cout << "怪物" << this->m_Name << "is hold" << endl;
        return;
    }

    //计算攻击伤害
    int damage = (this->m_Atk - hero->m_Def) > 0 ? this->m_Atk - hero->m_Def : 1;

    hero->m_Hp -= damage;

    cout << "怪物" << this->m_Name << "攻击了英雄" << hero->m_Name << "造成了伤害" << damage << endl;
}