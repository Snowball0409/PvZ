#include "Land.h"  
	
Land::Land()
{

}
	
Land::~Land()
{
	
}

Plant& Land::GetPlant()
{
    return plant_;
}

void Land::Planting(const Plant plant)
{
    //plant on empty land
    plant_ = plant;
}

void Land::Visit(Player &player)
{
    //if plant exist&has visit method, visit
    /* Visit plant */
}

void Land::Visit(Zombie &zombie)
{
    //if plant exist, battle
    if(plant_.Name()!="Empty")
    {
        /*battle*/
        std::cout << "Zombie eats plant " << plant_.Name() << "and causes damage " << zombie.Damage() << " .";
        this->Update();
    }
}

void Land::Update()
{
    //if plant dead, delete it and print messeage
    if(plant_.Hp()<=0)
    {
        std::cout << "Plant " << plant_.Name() << " is dead!" << std::endl;
        /*delete plant and recreate*/
    }
}

std::ostream& operator <<(std::ostream &os, const Land &land)
{
    //print plant info
    //os << land.plant_;
    return os;
}