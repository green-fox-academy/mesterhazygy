//
// Created by megha on 2019. 04. 24..
//

#include "Mammal.h"

Mammal::Mammal(std::string name) : Animal()
{
    _name = name;
}

std::string Mammal::getName()
{
    return _name;
}

std::string Mammal::breed()
{
    return "pushing out miniature versions of itself. Pretty cool huh?";
}

void Mammal::eat()
{
    std::cout << "oi";
}