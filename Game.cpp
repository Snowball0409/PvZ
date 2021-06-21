#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
constexpr char Game::fileName[];
Game::Game():success_{false}, numOfZombie_{DEFAULT_ZOMBIE}, numOfLand_{DEFAULT_LAND}, plantMinCost_{INT_MAX}, lastAction_{NUM_OF_PLANT_TYPES}
{
    std::ifstream inputFile(fileName, std::ios::in);
    if (!inputFile)
    {
        std::cout << "Open " << fileName << " Error\n";
    }
    else
    {   
        for (size_t i = 0; i < NUM_OF_PLANT_TYPES; ++i) {
            std::string line, plantType, plantName, plantCostStr;
            int plantHp, plantCost;
            getline(inputFile, line);
            std::istringstream iss(line);
            iss >> plantType >> plantName >> plantCostStr  >> plantHp;
            plantCost = stoi(plantCostStr.substr(1));
            plantMinCost_ = std::min(plantMinCost_, plantCost);
            // printf("plantType:%s plantName:%s plantCost:%d plantHp:%d ", plantType.c_str(), plantName.c_str(), plantCost, plantHp);
            switch (plantType[0])
            {
                case 'C':
                    int visit, reward;
                    iss >> visit >> reward;
                    printf("visit:%d reward:%d\n", visit, reward);
                    basicPlants_.push_back(new CoinPlant(plantCost, plantHp, reward, visit, plantName));
                    break;
                case 'S':
                    int dmg;
                    iss >> dmg;
                    printf("dmg:%d\n", dmg);
                    basicPlants_.push_back(new HornPlant(plantCost, plantHp, dmg, plantName));
                    break;
                case 'B':
                    printf("\n");
                    basicPlants_.push_back(new BombPlant(plantCost, plantHp, plantHp, plantName));
                    break;
                case 'H':
                    int health;
                    iss >> health;
                    printf("health:%d\n", health);
                    basicPlants_.push_back(new HealPlant(plantCost, plantHp, health, plantName));
                    break;
                default:
                    std::cout << "Unknown Plant Type " << plantType << std::endl;
                    break;
            }
            basicPlants_[i]->Show();
        }
        GameSetUp();
        player_ = new Player(numOfLand_);
        for (size_t i = 0; i < numOfZombie_; ++i) {
            zombies_.push_back(new Zombie(numOfLand_));
        }
        map_ = new Map(numOfLand_, *player_, numOfZombie_, zombies_);
        success_ = true;
    }
    inputFile.close();
}
void Game::GameSetUp()
{
    std::cout
    << "------------------------------\n"
    << "|     Plants vs. Zombies     |\n"
    << "------------------------------\n";
    std::string userInput;
    std::istringstream iss;
    std::cout << "Number of lands on the map (1-10, default: 8)...>";
    std::getline(std::cin, userInput);
    iss.str(userInput);
    iss >> numOfLand_;
    iss.clear();
    std::cout << "Number of zombies on the map (1-10, default: 3)...>";
    std::getline(std::cin, userInput);
    iss.str(userInput);
    iss >> numOfZombie_;
    iss.clear();
    if (numOfLand_ < 1 || numOfLand_ > 10) {numOfZombie_ = DEFAULT_ZOMBIE;}
    if (numOfZombie_ < 1 || numOfZombie_ > 10) {numOfLand_ = DEFAULT_LAND;}
    std::cout
    << "=========================================================\n"
    << "Plants vs Zombies Rule:\n"
    << "How to win:\n"
    << "  (1) All zombies are dead.\n"
    << "  (2) At least one plant is live.\n"
    << "  (3) The number of dead bomb plants cannot exceed the number of zombies.\n\n"
    << "How to lose:\n"
    << "  All plants are dead.\n"
    << "=============================================================================\n";
    system("Pause");
    system("CLS");
}

bool Game::PlantActValid(int plantType)
{
    bool ret = false;
    Plant *landPlant = NULL;
    switch (plantType)
    {
    case COIN_PLANT:
        landPlant = new CoinPlant(basicPlants_[COIN_PLANT]->Price(), basicPlants_[COIN_PLANT]->Hp(), 
        basicPlants_[COIN_PLANT]->Reward(), basicPlants_[COIN_PLANT]->Visit(), 
        basicPlants_[COIN_PLANT]->Name());
        break;
    case HEAL_PLANT:
        landPlant = new HealPlant(basicPlants_[HEAL_PLANT]->Price(), basicPlants_[HEAL_PLANT]->Hp(), 
        basicPlants_[HEAL_PLANT]->HealPoint(), basicPlants_[HEAL_PLANT]->Name());
        break;
    case BOMB_PLANT:
        landPlant = new BombPlant(basicPlants_[BOMB_PLANT]->Price(), 
        basicPlants_[BOMB_PLANT]->Hp(), basicPlants_[BOMB_PLANT]->Damage(), basicPlants_[BOMB_PLANT]->Name());
        break;
    case HORN_PLANT:
        landPlant = new HornPlant(basicPlants_[HORN_PLANT]->Price(), 
        basicPlants_[HORN_PLANT]->Hp(), basicPlants_[HORN_PLANT]->Damage());
        break;
    default:
        break;
    }
    if (player_->Planting(*landPlant))
    {
        printf("You have planted %s at land %d !\n", (landPlant->Name()).c_str(), player_->Locate());
        map_->Planting(landPlant, player_->Locate());
        ret = true;
    }
    else
    {
        std::cout << "Not Enough Money! Please input again!\n";
        system("Pause");
    }
    return ret;
}
void Game::PlayerPlant()
{
    if (EnoughCost())
    {
        bool optInValid = true;
        do {
            printf("Player $%d:\t Enter Your choice (4 to give up, default : %d)...>", player_->Money(), lastAction_);
            size_t action = 0;
            std::string userInput;
            getline(std::cin, userInput);
            std::istringstream iss(userInput);
            iss >> action;
            if (action >= NUM_OF_PLANT_TYPES) {action = lastAction_;}
            printf("Action : %d\n", action);
            if (action == NUM_OF_PLANT_TYPES)
            {
                //checkGame
                std::cout << "You give up!\n";
                optInValid = false;
            }
            else
            {
                //plant
                if (PlantActValid(action))
                {
                    optInValid = false;
                    lastAction_ = action;
                }
            }
        }
        while (optInValid);
    }
    else
    {
        std::cout << "You don't have enough money to plant anything!";
    }
    system("Pause");
    system("CLS");
}
void Game::PrintMap() const 
{
    std::cout << *map_ << "---------------------------\n";
}
void Game::PrintZombies() const
{
    std::cout << "Zombie information:\n";
    for (size_t i = 0; i < zombies_.size(); ++i) {
        std::cout << "[" << i << "] " << *zombies_[i] << '\n';
    }
    std::cout << "===========================\n";
}
void Game::PrintPlants() const
{
    //waiting for plain virtual show()
    for (int i = 0; i < NUM_OF_PLANT_TYPES; ++i) {
        printf("[%d] ", i);
        basicPlants_[i]->Show();
    }
    printf("\n");
}
void Game::ZombiesMove()
{
    for (size_t i = 0; i < zombies_.size(); ++i)
    {
        if (!zombies_[i]->IsDie())
        {
            srand(time(NULL));
            zombies_[i]->Move(rand(), numOfLand_);
            map_->Update(*zombies_[i], i);
            PrintMap();
            PrintZombies();
            map_->Visit(*zombies_[i], i);
            printf("Zombie [%d] moves to land %d.\n", i, zombies_[i]->Locate());
            system("Pause");
            system("CLS");
        }
    }
}
void Game::PlayerMove()
{
    srand(time(NULL));
    player_->Move(rand(), numOfLand_);
    map_->Update(*player_);
    map_->Visit(*player_);
}
void Game::Play()
{
    PrintMap();
    PrintZombies();
    PrintPlants();
    PlayerPlant();
    ZombiesMove();
    PlayerMove();
    system("CLS");
}
Game::~Game()
{
    delete player_;
    for (size_t i = 0; i < zombies_.size(); ++i) {
        delete zombies_[i];
    }
    for (size_t i = 0; i < NUM_OF_PLANT_TYPES; ++i) {
        delete basicPlants_[i];
    }
    delete map_;
}