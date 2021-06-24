#include "Zombie.h"  

Zombie::Zombie(int landN):hp_(15),damage_(15)
{
	//random init locate
    loc_ = rand()%landN;
}
	
Zombie::Zombie(int &hp, const int &damage, int &loc):hp_(hp),damage_(damage),loc_(loc)
{
	
}
	
Zombie::~Zombie()
{
	
}

void Zombie::Damaged(const int damage)
{
    hp_ -= damage;
}

bool Zombie::IsDie()
{
    if(hp_ <= 0)
        loc_ = -1;
        return true;
    return false;
}

void Zombie::Move(const int offset, const int max)
{
    loc_ += offset;
    if(loc_ >= max)loc_ %= max;
}

int Zombie::Damage() const
{
    return damage_;
}

int Zombie::Locate() const
{
    return loc_;
}

int Zombie::HealthPoint() const
{
    return hp_;
}

std::ostream &operator <<(std::ostream &os, const Zombie &zombie)
{
    os << "Damage: " << zombie.damage_ << " ";
    os << "HP: ";
    for(int i = 0;i < zombie.hp_;++ i) os << "*";
    return os;
}