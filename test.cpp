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
    cout << "Init class test..." << endl;
    Plant p0;
    BombPlant p1;
    CoinPlant p2;
    HealPlant p3;
    HornPlant p4;

    Player player;
    Zombie zombies[3];
    Zombie zombie(0,5);
    Land land;
    Map map(8, player, 3, zombies);

    //map show
    cout << "Show data test..." << endl;
    try{
        //map show
        map.Show(); 

        //zombie show
        for(size_t i = 0;i < 3;++ i)
        {
            if(!zombies[i].IsDie())
            {
                cout << '[' << i << ']' << zombies[i] << endl;
            }
        }
        cout << zombie << endl;

    }catch(const exception& e)
    {
        e.what();
    }

    return 0;
}
