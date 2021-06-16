#pragma once

#include<iostream>

class Plant{
    private:
        int price_ = 0;
        int hp_ = 0;
    public:
        int Price()const{return price_;}
        int Hp()const{return hp_;}
        Plant();
        ~Plant();
        Plant(int price, int hp);
        
};

