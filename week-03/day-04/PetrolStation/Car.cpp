//
// Created by megha on 2019. 04. 18..
//

#include "Car.h"

Car::Car(int gasAmount)
{
    _gasAmount = gasAmount;
    _capacity = 30;
}

int Car::getGasAmount() const
{
    return _gasAmount;
}

int Car::getCapacity() const
{
    return _capacity;
}

bool Car::isFull()
{
    if (_gasAmount = _capacity){
        return true;
    } else
        return false;
}

void Car::fill()
{
    while(! isFull()){
        _gasAmount++;
        std::cout << "Filling car!" << std::endl;
    }
}