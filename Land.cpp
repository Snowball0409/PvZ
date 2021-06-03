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

void Planting(const Plant plant)
{
    plant_ = plant;
}