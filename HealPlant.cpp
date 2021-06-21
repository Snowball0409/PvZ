#include <iostream>
#include "Plant.h"
#include "HealPlant.h"

HealPlant::~HealPlant(){

}

std::ostream &operator<<(std::ostream &os, const HealPlant &rhs){
    os << "HealPlant $" <<rhs.Price()<<" HP: "<<rhs.MAX_HP[rhs.Type()]<<" - gives all your plants "
    <<rhs.HealPoint()<<" HP back"<<std::endl;
    return os;
}