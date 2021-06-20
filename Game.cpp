#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
constexpr char Game::fileName[];
Game::Game():success_{false}, numOfZombie_{DEFAULT_ZOMBIE}, numOfLand_{DEFAULT_LAND}
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
            printf("plantType:%s, plantName:%s plantCost:%d plantHp:%d ", plantType.c_str(), plantName.c_str(), plantCost, plantHp);
            switch (plantType[0])
            {
                case 'C':
                    int visit, reward;
                    iss >> visit >> reward;
                    printf("visit:%d reward:%d\n", visit, reward);
                    plants_[COIN_PLANT] = new CoinPlant(plantCost, plantHp, reward, visit, plantName);
                    break;
                case 'S':
                    int dmg;
                    iss >> dmg;
                    printf("dmg:%d\n", dmg);
                    plants_[HORN_PLANT] = new HornPlant(plantCost, plantHp, dmg, plantName);
                    break;
                case 'B':
                    printf("\n");
                    plants_[BOMB_PLANT] = new BombPlant(plantCost, plantHp, plantHp, plantName);
                    break;
                case 'H':
                    int health;
                    iss >> health;
                    printf("health:%d\n", health);
                    plants_[HEAL_PLANT] = new HealPlant(plantCost, plantHp, health, plantName);
                    break;
                default:
                    std::cout << "Unknown Plant Type " << plantType << std::endl;
                    break;
            }
        }
        //waiting for plain virtual show()
        // for (int i = 0; i < NUM_OF_PLANT_TYPES; ++i) {
        //     std::cout << plants_[i] << "\n";
        // }
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
void Game::Play()
{
    map_->Show();
    std::cout << "---------------------------\n";
    for (size_t i = 0; i < zombies_.size(); ++i) {
        std::cout << *zombies_[i] << '\n';
    }
    std::cout << "===========================\n";
    //waiting for plain virtual show()
    // for (int i = 0; i < NUM_OF_PLANT_TYPES; ++i) {
    //     std::cout << plants_[i] << "\n";
    // }
    printf("Player $%d:\t Enter Your choice (4 to give up, default : 4)...>", player_->Money());
    int action = 0;
    std::string userInput;
    getline(std::cin, userInput);
    std::istringstream iss(userInput);
    iss >> action;
    if (action < 1 || action > DEFAULT_ACTION) {action = DEFAULT_ACTION;}
    if (action == DEFAULT_ACTION)
    {
        //checkGame
        system("Pause");
    }
    else
    {
        //plant
        system("Pause");
    }
}
Game::~Game()
{
    delete player_;
    for (size_t i = 0; i < zombies_.size(); ++i) {
        delete zombies_[i];
    }
    for (size_t i = 0; i < NUM_OF_PLANT_TYPES; ++i) {
        delete plants_[i];
    }
}