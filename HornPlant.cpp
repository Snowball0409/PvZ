#include <iostream>
#include "Plant.h"
#include "HornPlant.h"


HornPlant::~HornPlant(){

}

void HornPlant::Show(){
    std::cout << "HornPlant $" << Price() << " HP: " << MAX_HP[Type()] << " - gives "
    << Damage() << " damage points" << std::endl;
}