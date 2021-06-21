#include "Plant.h"
#include <iostream>
#include "BombPlant.h"


BombPlant::~BombPlant(){

}

void BombPlant:: Show(){
    std::cout << "BombPlant $" << Price() << " HP: " << MAX_HP[Type()] <<" - gives "
    << Damage() << " damage points" << std::endl;
}