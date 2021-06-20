#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>

constexpr int PLANT_NUMBER = 4;

enum plantType{
    HEAL_PLANT,
    COIN_PLANT,
    BOMB_PLANT,
    HORN_PLANT,
    EMPTY
};

const std::string plantName[PLANT_NUMBER]={"Healflower","Mushroom","Bombflower","Hornflower"};

class Plant{
    private:
        int price_;
        int hp_;
        enum plantType type_ = EMPTY;
        std::string name_ = "Empty";
    public:
        int Price()const{return price_;}
        int Hp()const{return hp_;}
        enum plantType Type()const{return type_;}
        std::string Name()const{return name_;}
        Plant() : price_(0), hp_(0), type_(EMPTY),name_("Empty"){}
        ~Plant();
        Plant(int price, int hp, enum plantType type, std::string name): price_(price), hp_(hp), type_(type), name_(name){}
        void Healing(int healPoint);
        void Injured(int damage);
        static int MAX_HP[PLANT_NUMBER];
        virtual int Damage(){return 0;}
        virtual int Visit(){return 0;}
        virtual int Step(){return 0;}
        virtual int Reward(){return 0;}
        virtual int HealPoint(){return 0;}
        virtual void Visiting(){}
};

#endif