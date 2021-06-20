#include "Plant.h"
#include <iostream>
#include "BombPlant.h"


BombPlant::~BombPlant(){

}

std::ostream &operator<<(std::ostream &os, const BombPlant &rhs){
    os << "BombPlant $" <<rhs.Price()<<" HP: "<<rhs.MAX_HP[rhs.Type()]<<" - gives "
    <<rhs.Damage()<<" damage points"<<std::endl;
    return os;
}