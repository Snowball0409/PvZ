#pragma once

#include <iostream>
#include "Plant.h"



class CoinPlant: public Plant{
    friend std::ostream &operator<<(std::ostream &os, const CoinPlant &rhs);
    private:
        int reward_ = 100;
        int visit_ = 2;
    public:
        int Reward()const{return reward_;}
        int Visit()const{return visit_;}
        CoinPlant();
        CoinPlant(int price, int hp, int reward, int visit) : Plant(price, hp), reward_(reward), visit_(visit){}
        ~CoinPlant();
};