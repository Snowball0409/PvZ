#include <iostream>
#include "Plant.h"
#include "HealPlant.h"

HealPlant::~HealPlant(){

}

void HealPlant:: Show()const{
    std::cout << Name() << " $" << Price() << " HP: " << MAX_HP[Type()] << " - gives all your plants "
    << HealPoint() << " HP back" <<std::endl;
}