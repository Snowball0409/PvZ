#ifndef LAND_H
#define LAND_H

#include "Plant.h"
	
class Land  
{
	private:
		Plant plant_;

	public:
		Land();
		~Land();
		Plant Plant();
		void Planting(const Plant plant);

};
#endif