#include "Plant.h"
#include <iostream>
#include "BombPlant.h"



BombPlant::BombPlant(){
    damage_ = 50;
}

BombPlant::~BombPlant(){

}

std::ostream &operator<<(std::ostream &os, const BombPlant &rhs){
    os << "BombPlant $" <<rhs.Price()<<" HP: "<<rhs.Hp()<<" - gives "
    <<rhs.Damage()<<" damage points"<<std::endl;
}