#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>

constexpr int PLANT_NUMBER = 4;

enum plantType{
    COIN_PLANT,
    HORN_PLANT,
    BOMB_PLANT,
    HEAL_PLANT,
    EMPTY
};

static std::string plantName[PLANT_NUMBER]={"Mushroom","Hornflower","Bombflower","Healflower"};

class Plant{
    private:
        int price_;
        int hp_;
        enum plantType type_ = EMPTY ;
        std::string name_ = "Empty";
    public:
        int Price()const{return price_;}
        int Hp()const{return hp_;}
        enum plantType Type()const{return type_;}
        std::string Name()const{return name_;}
        Plant() : price_(0), hp_(0), type_(EMPTY),name_("Empty"){}
        virtual ~Plant();
        Plant(int price, int hp, enum plantType type, std::string name): price_(price), hp_(hp), type_(type), name_(name){}
        Plant(int price, enum plantType type): price_(price), hp_(MAX_HP[type]), type_(type), name_(plantName[type]){}
        void Healing(int healPoint);
        void Injured(int damage);
        static int MAX_HP[PLANT_NUMBER];
        virtual int Damage()const{return 0;}
        virtual int Visit()const{return 0;}
        virtual int Step()const{return 0;}
        virtual int Reward()const{return 0;}
        virtual int HealPoint()const{return 0;}
        virtual void Visiting(){}
        virtual void Show(){}
};

#endif