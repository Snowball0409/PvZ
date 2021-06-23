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
#include <climits>
#include <vector>
#include <ctime>
#include <cstdlib>

class Game
{
private:
    void GameSetUp();
    void PrintZombies() const;
    void PrintMap() const;
    void PrintPlants() const;
    void ZombiesMove();
    void PlayerMove();
    void PlayerPlant();
    bool UpdateGameStatus();
    bool Finish() const {return isWin_ || isLose_;}
    bool EnoughCost() const {return player_->Money() > plantMinCost_;}
    bool EmptyLand() const {return ((map_->GetPlant(player_->Locate()))->Type()) == EMPTY;}
    bool PlantActValid(int plantType);
    int GernateStep() const;
    bool success_, isWin_, isLose_;
    size_t numOfLand_, numOfZombie_, bombFlowerUsed_;;
    int defaultAction_, plantMinCost_;
    std::vector<Plant*> basicPlants_;
    std::vector<Zombie*> zombies_;
    Player *player_;
    Map *map_;
    static constexpr size_t DEFAULT_LAND = 8, DEFAULT_ZOMBIE = 3, NUM_OF_PLANT_TYPES = 4;
    static constexpr char fileName[] = "plants.txt";
public:
    Game();
    ~Game();
    void Play();
    bool IsWin() const {return isWin_;}
    bool IsLose() const {return isLose_;}
    void PrintLose() const;
    void PrintWin() const;
    bool Success() const {return success_;}
};

#endif