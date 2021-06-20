#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    game.GameSetUp();
    while (game.Success())
    {
        game.Play();
        if (game.IsWin())
        {
            game.PrintWin();
            break;
        }
        else if (game.IsLose())
        {
            game.PrintLose();
            break;
        }
    }
    return 0;
}