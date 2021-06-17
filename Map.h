#ifndef MAP_H
#define MAP_H

#include "Land.h"
#include "Player.h"
#include "Zombie.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
	
class Map  
{
	private:
		Land* lands_;
		int playerLoc_;
		int* zombieLoc_;

		int landN_;
		int zombieN_;

	public:

		Map(const int landN, const Player &player, const int zombieN, const Zombie *zombies);
		~Map();

		void Update(Player &player);
		void Update(Zombie &zombie, const int index);
		void Visit(Player &player);
		void Visit(Zombie &zombie, const int index);
		static const int Random();
		void Show();
		void Planting(const Plant &plant, const int index);

};
#endif