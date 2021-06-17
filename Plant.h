#pragma once

#include <iostream>
#include <string>

class Plant{
    private:
        int price_;
        int hp_;
        std::string name_="Empty";
    public:
        int Price()const{return price_;}
        int Hp()const{return hp_;}
        Plant() : price_(0), hp_(0){}
        ~Plant();
        Plant(int price, int hp, std::string name);
      
};

