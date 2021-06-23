#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>

constexpr char Game::fileName[];

Game::Game():success_{false}, isWin_{false}, isLose_{false},
numOfLands_{DEFAULT_LANDS}, numOfZombies_{DEFAULT_ZOMBIES}, bombFlowerUsed_{0},
defaultAction_{NUM_OF_PLANT_TYPES}, plantMinCost_{INT_MAX}
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
            //printf("plantType:%s plantName:%s plantCost:%d plantHp:%d ", plantType.c_str(), plantName.c_str(), plantCost, plantHp);
            switch (plantType[0])
            {
                case 'C':
                    int visit, reward;
                    iss >> visit >> reward;
                    //printf("visit:%d reward:%d\n", visit, reward);
                    //Plant::plantName[COIN_PLANT] = plantName;
                    Plant::MAX_HP[COIN_PLANT] = plantHp;
                    basicPlants_.push_back(new CoinPlant(plantCost, plantHp, reward, visit, plantName));
                    break;
                case 'S':
                    int dmg;
                    iss >> dmg;
                    //printf("dmg:%d\n", dmg);
                    //Plant::plantName[HORN_PLANT] = plantName;
                    Plant::MAX_HP[HORN_PLANT] = plantHp;
                    basicPlants_.push_back(new HornPlant(plantCost, plantHp, dmg, plantName));
                    break;
                case 'B':
                    //printf("\n");
                    //Plant::plantName[BOMB_PLANT] = plantName;
                    Plant::MAX_HP[BOMB_PLANT] = plantHp;
                    basicPlants_.push_back(new BombPlant(plantCost, plantHp, plantHp, plantName));
                    break;
                case 'H':
                    int health;
                    iss >> health;
                    //printf("health:%d\n", health);
                    //Plant::plantName[HEAL_PLANT] = plantName;
                    Plant::MAX_HP[HEAL_PLANT] = plantHp;
                    basicPlants_.push_back(new HealPlant(plantCost, plantHp, health, plantName));
                    break;
                default:
                    std::cout << "Unknown Plant Type " << plantType << std::endl;
                    break;
            }
        }
        GameSetUp();
        player_ = new Player(numOfLands_);
        for (size_t i = 0; i < numOfZombies_; ++i) {
            zombies_.push_back(new Zombie(numOfLands_));
        }
        map_ = new Map(numOfLands_, *player_, numOfZombies_, zombies_);
        success_ = true;
    }
    inputFile.close();
}

void Game::GameSetUp()
{
    std::cout
    << "-----------------------------\n"
    << "|          TEAM 2           |\n"
    << "|     Plants vs. Zombies    |\n"
    << "-----------------------------\n";
    std::string userInput;
    std::istringstream iss;
    std::cout << "Number of lands on the map (1-10, default: 8)...>";
    std::getline(std::cin, userInput);
    iss.str(userInput);
    iss >> numOfLands_;
    iss.clear();
    std::cout << "Number of zombies on the map (1-10, default: 3)...>";
    std::getline(std::cin, userInput);
    iss.str(userInput);
    iss >> numOfZombies_;
    iss.clear();
    if (numOfLands_ < MIN_LANDS || numOfLands_ > MAX_LANDS) {numOfLands_ = DEFAULT_LANDS;}
    if (numOfZombies_ < MIN_ZOMBIES || numOfZombies_ > MAX_ZOMBIES) {numOfZombies_ = DEFAULT_ZOMBIES;}
    std::cout
    << "=============================================================================\n"
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
        ++bombFlowerUsed_;
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
    if (!landPlant)
    {
        printf("Unknown Plant Type\n");
    }
    else if (player_->Planting(*landPlant))
    {
        printf("You have planted %s at land %d !\n", (landPlant->Name()).c_str(), player_->Locate());
        map_->Planting(landPlant, player_->Locate());
        ret = true;
    }
    else
    {
        std::cout << "Not Enough Money! Please input again !\n";
        system("Pause");
        std::cout << "\n\n";
    }
    return ret;
}

void Game::PlayerPlant()
{
    if (EmptyLand())
    {
        PrintMap();
        PrintZombies();
        PrintPlants();
        if (EnoughCost())
        {
            bool actInvalid = true;
            do {
                printf("Player $%d:\t Enter Your choice (4 to give up, default : %d)...>", player_->Money(), defaultAction_);
                size_t action = defaultAction_;
                std::string userInput;
                getline(std::cin, userInput);
                std::istringstream iss(userInput);
                iss >> action;
                if (action > NUM_OF_PLANT_TYPES) {action = defaultAction_;}
                if (action == NUM_OF_PLANT_TYPES)
                {
                    std::cout << "You give up!\n";
                    actInvalid = false;
                }
                else
                {
                    //plant
                    if (PlantActValid(action))
                    {
                        actInvalid = false;
                        defaultAction_ = action;
                    }
                }
            } while (actInvalid);   
        }
        else
        {
            //No money to plant
            printf("Player $%d:\tYou don't have enough money to plant anything !\n", player_->Money());
        }
        system("Pause");
        if (UpdateGameStatus()) {/*Game finish*/ return;}
        system("CLS");
    }
}

void Game::PrintMap() const 
{
    std::cout << *map_ << "---------------------------\n";
}

void Game::PrintZombies() const
{
    std::cout << "Zombie information:\n";
    for (size_t i = 0; i < zombies_.size(); ++i)
    {
        if (!zombies_[i]->IsDie())
        {
            std::cout << "[" << i << "] " << *zombies_[i] << '\n';
        }
    }
    std::cout << "===========================\n";
}

void Game::PrintPlants() const
{
    for (size_t i = 0; i < NUM_OF_PLANT_TYPES; ++i)
    {
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
            zombies_[i]->Move(GenerateStep(), numOfLands_);
            map_->Update(*zombies_[i], i);
            PrintMap();
            PrintZombies();
            map_->Visit(*zombies_[i], i);
            printf("Zombie [%d] moves to land %d.\n", i, zombies_[i]->Locate());
            if (UpdateGameStatus()) {/*Game finish*/ return;}
            system("Pause");
            system("CLS");
        }
    }
}

int Game::GenerateStep() const
{
    srand(time(NULL));
    int step = 0;
    while (step == 0)
    {
        step = rand() % numOfLands_;
    }
    return step;
}

void Game::PlayerMove()
{
    // std::cout << "player loc : " << player_->Locate() << "\n";
    player_->Move(GenerateStep(), numOfLands_);
    map_->Update(*player_);
    PrintMap();
    PrintZombies();
    // std::cout << "player loc : " << player_->Locate() << "\n";
    if (map_->Visit(*player_))
    {
        system("Pause");
    }
    system("CLS");
}

bool Game::UpdateGameStatus()
{
    bool noPlants = true, noZombies = true;
    // std::cout << "Zombie\n";
    for (size_t i = 0; i < zombies_.size(); ++i)
    {
        // std::cout << i << " :" << zombies_[i]->HealthPoint() << "\n";
        if (zombies_[i]->HealthPoint() > 0)
        {
            noZombies = false;
            break;
        }
    }
    if (noZombies) 
    {
        if (bombFlowerUsed_ <= numOfZombies_ / 2) {isWin_ = true;}
        else {isLose_ = true;}
        return true;
    }
    // std::cout << "Plant\n";
    for (size_t i = 0; i < numOfLands_; ++i)
    {
        // std::cout << i << ": " << (map_->GetPlant(i))->Type() << "\n";
        if ((map_->GetPlant(i)->Type()) != EMPTY)
        {
            noPlants = false;
            break;
        }
    }
    if (noPlants) 
    {
        isLose_ = true; 
        return true;
    }
    return false;
}

void Game::Play()
{
    PlayerPlant();
    if (Finish()) {return;}
    ZombiesMove();
    if (Finish()) {return;}
    PlayerMove();
}

void Game::PrintLose() const 
{   
    std::cout << "\n\n";
    if (bombFlowerUsed_ > numOfZombies_ / 2)
    {
        std::cout << "You lose the game since you cannot use that much bomb plants!\n";
    }
    else
    {
        std::cout << "Oh no.. You have no plant on the map ...\n";
    }
    system("Pause");
}

void Game::PrintWin() const
{
    std::cout << "\n\nCongratulations You have kill all zombies!\n";
    system("Pause");
}

Game::~Game()
{
    delete player_;
    for (size_t i = 0; i < zombies_.size(); ++i)
    {
        delete zombies_[i];
    }
    for (size_t i = 0; i < NUM_OF_PLANT_TYPES; ++i)
    {
        delete basicPlants_[i];
    }
    delete map_;
}