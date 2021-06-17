#include <iostream>
#include "Plant.h"
#include "HornPlant.h"


HornPlant::~HornPlant(){

}

std::ostream &operator<<(std::ostream &os, const HornPlant &rhs){
    os << "HornPlant $" <<rhs.Price()<<" HP: "<<rhs.Hp()<<" - gives "
    <<rhs.Damage()<<" damage points"<<std::endl;
}