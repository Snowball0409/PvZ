#include "Zombie.h"  
	
Zombie::Zombie():hp_(15),damage_(15)
{
	
}
	
Zombie::~Zombie()
{
	
}

void Zombie::Damaged(const int damage)
{
    hp_ -= damage;
}

const int Zombie::Damage()
{
    return damage_;
}

bool Zombie::IsDie()
{
    if(hp_ <= 0)
        return true;
    return false;
}

void Zombie::Move(const int offset, const int max)
{
    loc_ += offset;
    if(loc_ > max)loc_ %= max;
}

const int Zombie::Locate()
{
    return loc_;
}

const int Zombie::HealthPoint()
{
    return hp_;
}