#ifndef MAP_H
#define MAP_H

#include "Land.h"
#include "Player.h"
#include "Zombie.h"
#include "Plant.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <vector>
	
class Map  
{
	friend std::ostream& operator <<(std::ostream& os, const Map &map);

	private:
		Land* lands_ = NULL;
		int playerLoc_ = 0;
		int* zombieLoc_ = NULL;

		const int landN_ = 0;
		const int zombieN_ = 0;

	public:

		Map(const int landN, const Player &player, const int zombieN, const std::vector<Zombie*> &zombies);
		~Map();

		void Update(Player &player);
		void Update(Zombie &zombie, const int index);
		bool Visit(Player &player);
		bool Visit(Zombie &zombie, const int index);
		static const int Random();
		void Planting(Plant* plant, const int index);
		Plant* GetPlant(const int index);

};
#endif