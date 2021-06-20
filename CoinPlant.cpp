#include <iostream>
#include "Plant.h"
#include "CoinPlant.h"



CoinPlant::~CoinPlant(){

}

std::ostream &operator<<(std::ostream &os, const CoinPlant &rhs){
    os << "CoinPlant $" <<rhs.Price()<<" HP: "<<rhs.MAX_HP[rhs.Type()]<<" - gives $"
    <<rhs.Reward()<<" every "<<rhs.Visit()<<" rounds"<<std::endl;
}

void CoinPlant:: Visiting(){
    step_-=1;
    if(step_ == 0){
        //  player  reward
        step_ = visit_;
    }
}
