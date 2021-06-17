#include "Plant.h"
#include "Land.h"
#include "Map.h"
#include "Player.h"
#include "Zombie.h"
#include "BombPlant.h"
#include "CoinPlant.h"
#include "HealPlant.h"
#include "HealPlant.h"
#include "HornPlant.h"

#include <iostream>

using namespace std;

int main()
{
    //create class
    Plant p0;
    BombPlant p1;
    CoinPlant p2;
    HealPlant p3;
    HornPlant p4;

    Player player;
    Zombie zombie[3];
    Land land;
    Map map(8, player, 3, zombie);

    //map show
    try{
        map.Show();
    }catch(const exception& e)
    {
        e.what();
    }

    return 0;
}
