#ifndef COINPLANT_H
#define COINPLANT_H

#include <iostream>
#include "Plant.h"



class CoinPlant: public Plant{
    friend std::ostream &operator<<(std::ostream &os, const CoinPlant &rhs);
    private:
        int reward_;
        int visit_;
        int step_;
    public:
        int Reward()const{return reward_;}
        int Visit()const{return visit_;}
        int Step()const{return step_;}
        void Visiting();
        CoinPlant() : reward_(100), visit_(2), step_(2){}
        CoinPlant(int price, int hp, int reward, int visit) : Plant(price, hp, COIN_PLANT, plantName[COIN_PLANT]), reward_(reward), visit_(visit){}
        ~CoinPlant();
};

#endif