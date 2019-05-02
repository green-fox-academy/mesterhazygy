//
// Created by megha on 2019. 05. 02..
//

#include "Parrot.h"

Parrot::Parrot(std::string name)
{
    _name = name;
    _healCost = rand() % 6 + 4;
}

Parrot::Parrot()
{
    _name = "parrot";
}
