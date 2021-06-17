#ifndef LAND_H
#define LAND_H

#include "Plant.h"
#include "Player.h"
#include "Zombie.h"
#include <iostream>
	
class Land  
{
	friend std::ostream& operator <<(std::ostream &os, const Land &land);

	private:
		Plant plant_;

	public:
		Land();
		~Land();
		Plant& Plant();
		void Planting(const Plant plant);
		void Visit(Player &player);
		void Visit(Zombie &zombie);
		void Update();

};
#endif