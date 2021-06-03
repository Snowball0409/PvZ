#pragma once

#include<iostream>

class Plant{
    private:
        int price_ = 0;
        int hp_ = 0;
    public:
        int Price()const{return price_;}
        Plant();
        ~Plant();
        void Setup(int price, int hp);
        
};

class BombPlant: public Plant{
    private:
        int damage_ = 50;
    public:
        int Damage()const{return damage_;}
        BombPlant();
        ~BombPlant();

};

class CoinPlant: public Plant{
    private:
        int reward_ = 100;
        int visit_ = 2;
    public:
        int Reward()const{return reward_;}
        int Visit()const{return visit_;}
        CoinPlant();
        ~CoinPlant();
};

class HornPlant: public Plant{
    private:
        int damage_ = 10;
    public:
        int Damage()const{return damage_;}
        HornPlant();
        ~HornPlant();
};

class HealPlant: public Plant{
    private:
        int healPoint_ = 20;
    public:
        int HealPoint()const{return healPoint_;}
        HealPlant();
        ~HealPlant();
};