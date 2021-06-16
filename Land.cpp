#include "Land.h"  
	
Land::Land()
{
	
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

std::ostream& Land::operator <<(std::ostream &os, const Land &land)
{
    os << land.plant_;
    return os;
}