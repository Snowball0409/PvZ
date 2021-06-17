#include "Map.h"  
	
Map::Map(const int landN, const Player &player, const int zombieN, const Zombie *zombies)
{
	lands_ = new Land[landN];
	playerLoc_ = player.Locate();
	zombieLoc_ = new int[zombieN];
	for(int i = 0;i < zombieN;++i)
	{
		zombieLoc_[i] = zombies[i].Locate();
	}
}
	
Map::~Map()
{
	
}

void Map::Update(Player &player)
{
	//update locate
	playerLoc_ = player.Locate();
}

void Map::Update(Zombie &zombie, const int index)
{
	//update locate
	zombieLoc_[index] = zombie.Locate();
}

void Map::Visit(Player &player)
{
	lands_[playerLoc_].Visit(player);
}

void Map::Visit(Zombie &zombie, const int index)
{
	lands_[zombieLoc_[index]].Visit(zombie);
}

void Map::Planting(const Plant &plant, const int index)
{
	//plant on index land
	lands_[index].Planting(plant);
}

void Map::Show()
{
	for(int i = 0;i < sizeof(lands_)/sizeof(Land);++ i)
	{
		std::cout << "[" << i << "]" << "{";
		std::cout << (playerLoc_==i)?"*":" ";
		for(int j = 0;j < sizeof(zombieLoc_)/sizeof(int);++ j)
		{
			std::cout << (zombieLoc_[j]==i)?std::to_string(j):" ";
		}
		std::cout << lands_[i] << std::endl;
	}
}