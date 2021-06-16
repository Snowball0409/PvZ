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

int Zombie::Damage() const
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

int Zombie::Locate() const
{
    return loc_;
}

int Zombie::HealthPoint() const
{
    return hp_;
}