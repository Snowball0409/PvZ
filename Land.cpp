#include "Land.h"  
	
Land::Land()
{
    plant_ = new Plant();
}
	
Land::~Land()
{
	
}

Plant* Land::GetPlant()
{
    return plant_;
}

void Land::Planting(Plant* plant)
{
    //planting on empty land
    Plant* tmp = plant_;
    plant_ = plant;
    delete tmp;
}

bool Land::Visit(Player &player, Land* lands, const int &landN)
{
    //if plant exist&has visit method, visit, and return true
    switch(plant_->Type())
    {
        case COIN_PLANT:
            //check reward
            plant_->Visiting();
            if(plant_->Step() == plant_->Visit())
            {
                //get reward
                player.Reward(plant_->Reward());
                std::cout << "You have earned $" << plant_->Reward() << "! Now you have $" << player.Money() << std::endl;
            }
            else
            {
                //visit message
                std::cout << "You still need " << plant_->Visit()-plant_Step << " visit to earn money." << std::endl; 
            }
                
            break;
        case HEAL_PLANT:
            this->Healing(lands, landN, plant_->HealPoint());
            break;
        default:
            //do nothing
            return false;
    }
    return true;
}

void Land::Healing(Land* lands, const int &landN, const int &healPoint)
{
    //healing
    for(size_t i = 0;i < landN;++i)
    {
        if(lands[i].plant_->Type() != EMPTY)
        {
            lands[i].plant_->Healing(healPoint);
        }
    }
}

bool Land::Visit(Zombie &zombie)
{
    //if plant exist, battle and return true
    if(plant_->Type()!=EMPTY)
    {
        //plant attack zombie
        switch(plant_->Type())
        {
            case HORN_PLANT:
                zombie.Damaged(plant_->Damage());
                std::cout << plant_->Name() << " gives " << plant_->Damage() << " damages to the zombie!" << std::endl;
                break;
            case BOMB_PLANT:
                zombie.Damaged(plant_->Damage());
                plant_->Injured(plant_->Hp());
                std::cout << plant_->Name() << " gives " << plant_->Damage() << " damages to the zombie!" << std::endl;
                this->Update();
                break;
            default:
                break;

        }
        if(!zombie.IsDie()&&plant_->Type()!=EMPTY)
        {
            //if zombie not die& plant not dead, attack plant
            plant_->Injured(zombie.Damage());
            std::cout << "Zombie eats plant " << plant_->Name() << "and causes damage " << zombie.Damage() << " ." << std::endl;
            this->Update();
        }
        return true;
    }
    return false;
}

void Land::Update()
{
    //if plant dead, delete it and print messeage
    if(plant_->Hp()<=0)
    {
        std::cout << "Plant " << plant_->Name() << " is dead!" << std::endl;
        this->Replant();
    }
}

void Land::Replant()
{
    //recreate plant
    Plant* tmp = plant_;
    plant_ = new Plant();
    delete tmp;
}

std::ostream& operator <<(std::ostream &os, const Land &land)
{
    //print plant info
    switch(land.plant_->Type())
    {
        case COIN_PLANT:
            //coin plant
            os << land.plant_->Name() << " HP: " << land.plant_->Hp() << "( " << land.plant_->Step() << " more visits)";
            break;
        case EMPTY:
            //empty plant
            os << "Empty";
            break;
        default:
            //other plant
            os << land.plant_->Name() << " HP: " << land.plant_->Hp();
            break;
    }
    return os;
}