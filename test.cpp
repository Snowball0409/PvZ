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
    //////////////////////////////////////////////////////////////////////////////////
    //create class
    cout << "Init class test..." << endl;
    int landN = 8;
    int zombieN = 3;
    Plant p0;
    BombPlant p1;
    CoinPlant p2;
    HealPlant p3;
    HornPlant p4;

    Player player;
    Zombie zombies[3];
    Zombie zombie(15,5);//don't change
    Land land;
    Map map(landN, player, zombieN, zombies);
    //////////////////////////////////////////////////////////////////////////////////
    //plant test
    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Planting test..." << endl;
    try{

    }catch(const exception e)
    {
        cerr << e.what() << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////
    //player test
    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Player test..." << endl;
    try{
        //planting test
        while(player.Planting(p0))cout << "Plant: " << p0.Name() << ", Last: " << player.Money() << endl;

        //moving test
        player.Move(1, landN);
        cout << "Locate: " << player.Locate() << ", Except: 1" << endl;
        player.Move(7, landN);
        cout << "Locate: " << player.Locate() << ", Except: 0" << endl;

    }catch(const exception e)
    {
        cerr << e.what() << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////
    //zombie test
    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Zombie test..." << endl;
    try{
        //zombie show
        for(size_t i = 0;i < 3;++ i)
        {
            if(!zombies[i].IsDie())
            {
                cout << '[' << i << ']' << zombies[i] << endl;
            }
        }

        //damaged
        zombie.Damaged(10);
        cout << "Zombie hp: " << zombie.HealthPoint() << ", Except: 5" << endl;

        //attack
        cout << "ATK: " << zombie.Damage() << ", Except: 5" << endl;

        //isdie
        zombie.Damaged(1000);
        cout << "IsDie: " << boolalpha << zombie.IsDie() << ", Except: true" << endl; 

        //move
        zombie.Move(1, landN);
        cout << "Locate: " << zombie.Locate() << ", Except: " << (zombie.Locate()+1)%landN << endl;
        zombies[0].Move(7, landN);
        cout << "Locate: " << zombie.Locate() << ", Except: " << (zombie.Locate()+7)%landN << endl;

    }catch(const exception e)
    {
        cerr << e.what() << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////
    //map test
    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Map test..." << endl;
    try{
        //map show
        map.Show();

        //planting
        map.Planting(p1, 0);
        map.Show();
        cout << "Except: [0]{*    }" << p1.Name();

        //Visit

        //Update

    }catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////
    return 0;
}
