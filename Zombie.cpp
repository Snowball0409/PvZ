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

void Zombie::Move(const int loc)
{
    loc_ = loc;
}