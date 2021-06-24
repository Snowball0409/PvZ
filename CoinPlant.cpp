#include <iostream>
#include "Plant.h"
#include "CoinPlant.h"



CoinPlant::~CoinPlant(){

}


void CoinPlant:: Visiting(){
    step_-=1;
    if(step_ == 0){
        //  player  reward
        step_ = visit_;
    }
}

void CoinPlant::Show()const{
    std::cout << Name() << " $" << Price() << " HP: " << MAX_HP[Type()] << " - gives $"
    << Reward() << " every " << Visit() << " rounds" <<std::endl;
}
