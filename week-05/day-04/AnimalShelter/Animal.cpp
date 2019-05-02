//
// Created by megha on 2019. 05. 02..
//

#include "Animal.h"


bool Animal::isIsHealthy() const
{
    return _isHealthy;
}

void Animal::setIsHealthy(bool isHealthy)
{
    _isHealthy = isHealthy;
}

void Animal::heal()
{
    bool temp = isIsHealthy();
    temp = true;
    setIsHealthy(temp);
}



bool Animal::isAdoptable()
{
    if (!_isHealthy)
        return false;
    else
        return true;
}

std::string Animal::toString()
{
    if (!_isHealthy){
        std::cout << _name << " is not healthy(" << getHealCost() << " $), and is not adoptable." << std::endl;
    }
    else {
        std::cout << _name << " is healthy and adoptable." << std::endl;
    }
}

int Animal::getHealCost() const
{
    return _healCost;
}