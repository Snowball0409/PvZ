#include "Map.h"  
	
Map::Map(const int landN, const Player &player, const int zombieN, const std::vector<Zombie*> &zombies)
{
	lands_ = new Land[landN];
	playerLoc_ = player.Locate();
	zombieLoc_ = new int[zombieN];
	for(size_t i = 0; i < zombieN; ++i)
	{
		zombieLoc_[i] = zombies[i]->Locate();
	}

	landN_ = landN;
	zombieN_ = zombieN;
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
	lands_[playerLoc_].Visit(player, lands_, landN_);
}

void Map::Visit(Zombie &zombie, const int index)
{
	lands_[zombieLoc_[index]].Visit(zombie);
}

void Map::Planting(Plant* plant, const int index)
{
	//plant on index land
	lands_[index].Planting(plant);
}

void Map::Show()
{
	for(size_t i = 0; i < landN_; ++ i)
	{
		std::cout << "[" << i << "]" << "{";
		(playerLoc_==i)?std::cout << "*":std::cout << " ";
		for(size_t j = 0; j < zombieN_; ++ j)
		{
			(zombieLoc_[j]==i)?std::cout << std::to_string(j):std::cout << " ";
		}
		std::cout << "}";
		std::cout << lands_[i] << std::endl;
	}
}