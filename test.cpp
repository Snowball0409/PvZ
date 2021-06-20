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
#include <vector>

using namespace std;

int main()
{
    //////////////////////////////////////////////////////////////////////////////////
    //create class
    cout << "Init class test..." << endl;
    /* Don't change yourself */
    int landN = 8;
    int zombieN = 3;
    int hp = 15;
    int damage = 5;
    int loc = 0;
    int price = 50;
    int money = 150;
    int reward = 25;
    int bombDamage = 50;
    int visit = 2;
    int healPoint = 20;
    /*************************/

    Plant p0(price, hp, EMPTY, "TestPlant");
    Plant p01;
    BombPlant p1(price, hp, bombDamage);
    CoinPlant p2(price, hp, reward, visit);
    HealPlant p3(price, hp, healPoint);
    HornPlant p4(price, hp, damage);

    Player player(money, loc);
    Player player2(landN);
    vector<Zombie*> zombies;
    for(size_t i = 0;i < zombieN;++i)
    {
        Zombie* z = new Zombie(hp, damage, loc);
        zombies.push_back(z);
    }
    Zombie zombie(landN);
    Land land;
    Map map(landN, player, zombieN, zombies);
    //////////////////////////////////////////////////////////////////////////////////
    //plant test
    cout << "//////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "Planting test..." << endl;
    try{
        //Data show
        cout << "Base: p0" << endl;
        cout << "Price: " << p0.Price() << " Except: " << price << endl;
        cout << "Hp: " << p0.Hp() << " Except: " << hp << endl;
        cout << "Type: " << p0.Type() << " Except: " << EMPTY << endl;
        cout << "Name: " << p0.Name() << " Except: TestPlant" << endl;

        //Injured
        p0.Injured(damage);
        cout << "HP: " << p0.Hp() << " Except: " << hp-damage << endl;
        p0.Injured(99999);
        cout << "HP: " << p0.Hp() << " Except: 0" << endl;

        //Healing
        p0.Healing(1);
        cout << "HP: " << p0.Hp() << " Except: " << hp-damage+1 << endl;
        p0.Healing(99999);
        cout << "HP: " << p0.Hp() << " Except: " << hp << endl;

        //Damage
        

        //Visit

        //Step

        //Reward

        //HealPoint

        //Visiting

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
        cout << "Except: Last < " << price << endl;

        //moving test
        player.Move(1, landN);
        cout << "Locate: " << player.Locate() << ", Except: " << (loc+1)%landN << endl;
        player.Move(7, landN);
        cout << "Locate: " << player.Locate() << ", Except: " << (loc+8)%landN << endl;

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
            if(!zombies[i]->IsDie())
            {
                cout << '[' << i << ']' << *zombies[i] << endl;
            }
        }

        //damaged
        zombie.Damaged(10);
        cout << "Zombie hp: " << zombie.HealthPoint() << ", Except: " << hp-10 << endl;

        //attack
        cout << "ATK: " << zombie.Damage() << ", Except: " << damage << endl;

        //isdie
        zombie.Damaged(1000);
        cout << "IsDie: " << boolalpha << zombie.IsDie() << ", Except: true" << endl; 

        //move
        zombie.Move(1, landN);
        cout << "Locate: " << zombie.Locate() << ", Except: " << (loc+1)%landN << endl;
        zombie.Move(7, landN);
        cout << "Locate: " << zombie.Locate() << ", Except: " << (loc+8)%landN << endl;

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
        cout << "Except: Map Data" << endl;

        //planting
        map.Planting(&p1, 0);
        map.Planting(&p2, 1);
        map.Planting(&p3, 2);
        map.Planting(&p4, 3);
        map.Show();
        cout << "Except: " << endl;
        cout << "[0]{*012}" << p1.Name() << endl;
        cout << "[1]{    }" << p2.Name() << endl;
        cout << "[2]{    }" << p3.Name() << endl;
        cout << "[3]{    }" << p4.Name() << endl;
        //Visit

        //Update

    }catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////
    return 0;
}
