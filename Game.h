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
    static constexpr char fileName[] = "plants.txt";
    int plantMinCost_, defaultAction_;
    size_t bombFlowerUsed_;
    void GameSetUp();
    void PrintZombies() const;
    void PrintMap() const;
    void PrintPlants() const;
    void ZombiesMove();
    void PlayerMove();
    void PlayerPlant();
    bool UpdateGameStatus();
    int GernateStep() const;
    bool success_;
    bool isWin_;
    bool isLose_;
    bool Finish() const {return isWin_ || isLose_;}
    size_t lastAction_;
    bool EnoughCost() const {return player_->Money() > plantMinCost_;}
    bool EmptyLand() const {return ((map_->GetPlant(player_->Locate()))->Type()) == EMPTY;}
    bool PlantActValid(int plantType);
    static constexpr size_t DEFAULT_LAND = 8, DEFAULT_ZOMBIE = 3, NUM_OF_PLANT_TYPES = 4;
public:
    Game();
    void Play();
    bool IsWin() const {return isWin_;}
    bool IsLose() const {return isLose_;}
    void PrintLose() const {std::cout << "Oh no.. You have no plant on the map ...\n"; system("Pause");}
    void PrintWin() const {std::cout << "Congratulations You have kill all zombies!\n"; system("Pause");}
    ~Game();
    std::vector<Plant*> basicPlants_;
    Player *player_;
    std::vector<Zombie*> zombies_;
    Map *map_;
    size_t numOfLand_, numOfZombie_;
    bool Success() const {return success_;}
};
#endif