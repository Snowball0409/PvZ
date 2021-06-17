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

void Land::Visit(Player &player)
{
    //if plant exist&has visit method, visit
    plant_.Visiting(player);
}

void Land::Visit(Zombie &zombie)
{
    //if plant exist, battle
    
}

std::ostream& operator <<(std::ostream &os, const Land &land)
{
    //print plant info
    //os << land.plant_;
    return os;
}