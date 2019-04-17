//
// Created by megha on 2019. 04. 17..
//

#include "Animal.h"
#include <iostream>

Animal::Animal(int thirst, int hunger)
{
    _thirst = thirst;
    _hunger = hunger;
}

void Animal::setThirst(int thirst)
{
    _thirst = thirst;
}

void Animal::setHunger(int hunger)
{
    _hunger = hunger;
}

int Animal::getThirst() const
{
    return _thirst;
}

int Animal::getHunger() const
{
    return _hunger;
}

void Animal::eat()
{
    _hunger --;
}

void Animal::drink()
{
    _thirst --;
}

void Animal::play()
{
    _hunger ++;
    _thirst ++;
}
