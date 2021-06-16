#include <iostream>
#include "Plant.h"
#include "HealPlant.h"

HealPlant::HealPlant(){
    healPoint_ = 20;
}

HealPlant::~HealPlant(){

}

std::ostream &operator<<(std::ostream &os, const HealPlant &rhs){
    os << "HealPlant $" <<rhs.Price()<<" HP: "<<rhs.Hp()<<" - gives all your plants "
    <<rhs.HealPoint()<<" HP back"<<std::endl;
}