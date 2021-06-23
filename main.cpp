#include "Game.h"
#include <iostream>
using namespace std;
int main()
{
    Game game;
    if (game.Success())
    {
        while (1)
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
    }
    else
    {
        system("Pause");
    }
    return 0;
}