#ifndef EMPTY_H
#define EMPTY_H

#include <iostream>
#include "Plant.h"

class Empty: public Plant{
    public:
        Empty(): Plant(){std::cout << "It's empty!" << std::endl;}
}

#endif