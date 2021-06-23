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
		Plant* plant_;

	public:
		Land();
		~Land();
		Plant* GetPlant();
		void Planting(Plant* plant);
		bool Visit(Player &player, Land* lands, const int &landN);
		bool Visit(Zombie &zombie);
		void Update();
		void Replant();
		void Healing(Land* lands, const int &landN, const int &healPoint);

};
#endif