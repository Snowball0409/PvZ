#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
constexpr char Game::fileName[];
Game::Game():success_{false}
{
    std::ifstream inputFile(fileName, std::ios::in);
    if (!inputFile)
    {
        std::cout << "Open " << fileName << " Error\n";
    }
    else
    {
        std::string line;
        while (getline(inputFile, line))
        {
            //std::cout << line;
            /*Set plant's Attributes*/
        }
        GameSetUp();
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
    int numLand = 8, numZombie = 3;
    std::string userInput;
    std::istringstream iss;
    std::cout << "Number of lands on the map (1-10, default: 8)...>";
    std::getline(std::cin, userInput);
    iss.str(userInput);
    iss >> numLand;
    iss.clear();
    std::cout << "Number of zombies on the map (1-10, default: 3)...>";
    std::getline(std::cin, userInput);
    iss.str(userInput);
    iss >> numZombie;
    iss.clear();
    //std::cout << numLand << " " << numZombie << "\n";
    /* Set Map */
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
}
Game::~Game()
{
}