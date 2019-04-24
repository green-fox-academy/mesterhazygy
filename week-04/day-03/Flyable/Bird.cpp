//
// Created by megha on 2019. 04. 24..
//

#include "Bird.h"

Bird::Bird(std::string color) : Vehicle(20, 30, color)
{
    _color = color;
}

std::string Bird::getName()
{
    return _name;
}

std::string Bird::breed()
{
    return "laying eggs";
}

void Bird::eat()
{
    std::cout << "oi";
}

void Bird::land()
{
    std::cout << "The " << _color << " colored bird has landed." << std::endl;
}

void Bird::fly()
{
    std::cout << "The " << _color << " colored bird is in the air." << std::endl;
}

void Bird::takeOff()
{
    std::cout << "The " << _color << " colored bird has taken off." << std::endl;
}