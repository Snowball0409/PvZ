#include "Plant.h"
#include <iostream>
#include "BombPlant.h"


BombPlant::~BombPlant(){

}

void BombPlant:: Show()const{
    std::cout << Name() << " $" << Price() << " HP: " << MAX_HP[Type()] <<" - gives "
    << Damage() << " damage points" << std::endl;
}