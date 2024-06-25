#include "DragonSword.h"

DragonSword::DragonSword()
{
    this->m_BaseDamage = 50;
    this->m_WeaponName = "DragonSword";
    this->suckRate = 20;
    this->holdRate = 30;
    this->critRate = 35;
}

int DragonSword::getBaseDamage()
{
    return this->m_BaseDamage;
}

int DragonSword::getSuckBlood()
{   
    if(isTrigger(suckRate))
    {
        return this->m_BaseDamage * 0.5; //按照武器伤害的一半吸血
    }
    return 0;
}

bool DragonSword::getHold()
{
    if(isTrigger(holdRate))
    {
        return true;
    }
    return false;
}

bool DragonSword::getCrit()
{
    if(isTrigger(critRate))
    {
        return true;
    }
    return false;
}

bool DragonSword::isTrigger(int rate)
{
    //通过isTrigger判断是否触发特效
    //随机0～100的数字
    int num = random()%100 + 1;
    if(num <= rate)
    {
        return true;
    }
    return false;
}