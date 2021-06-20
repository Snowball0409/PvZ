#ifndef GAME_H
#define GAME_H
#include "Game.h"
#include "Player.h"
#include "Zombie.h"
#include "Map.h"
#include "BombPlant.h"
#include "CoinPlant.h"
#include "HealPlant.h"
#include "HornPlant.h"
#include <vector>
class Game
{
private:
    static constexpr char fileName[] = "plants.txt";
    void GameSetUp();
    bool success_;
    static constexpr size_t NUM_OF_PLANT_TYPES = 4, DEFAULT_LAND = 8, DEFAULT_ZOMBIE = 3, DEFAULT_ACTION = 4;
public:
    Game();
    void Play();
    ~Game();
    Plant *plants_[NUM_OF_PLANT_TYPES];
    Player *player_;
    std::vector<Zombie*> zombies_;
    Map *map_;
    size_t numOfLand_, numOfZombie_;
    bool Success() const {return success_;}
};
#endif