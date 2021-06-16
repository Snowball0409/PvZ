#include "Land.h"  
	
Land::Land()
{
	//create empty plant
}
	
Land::~Land()
{
	
}

Plant Land::GetPlant()
{
    return plant_;
}

void Land::Planting(const Plant plant)
{
    plant_ = plant;
}

void Visit(Player &player)
{
    //if plant exist&has visit method, visit
}

void Visit(Zombie &zombie)
{
    //if plant exist, battle
}

std::ostream& Land::operator <<(std::ostream &os, const Land &land)
{
    //print plant info
    os << land.plant_;
    return os;
}