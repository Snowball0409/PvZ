#include <iostream>
#include "Plant.h"
#include "CoinPlant.h"

CoinPlant::CoinPlant(){
    visit_ = 2;
    reward_ = 100;
}

CoinPlant::~CoinPlant(){

}

std::ostream &operator<<(std::ostream &os, const CoinPlant &rhs){
    os << "CoinPlant $" <<rhs.Price()<<" HP: "<<rhs.Hp()<<" - gives $"
    <<rhs.Reward()<<" every "<<rhs.Visit()<<" rounds"<<std::endl;
}
