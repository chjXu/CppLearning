#include "knife.h"

Knife::Knife()
{
    this->m_BaseDamage = 30;
    this->m_WeaponName = "knife";
}

int Knife::getBaseDamage()
{
    return this->m_BaseDamage;
}

int Knife::getSuckBlood()
{   
    return 0;
}

bool Knife::getHold()
{
    return false;
}

bool Knife::getCrit()
{
    return false;
}