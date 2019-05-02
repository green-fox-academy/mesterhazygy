//
// Created by megha on 2019. 05. 02..
//

#include "Dog.h"

Dog::Dog(std::string name)
{
    _name = name;
    _healCost = rand() % 8 + 1;
}

Dog::Dog()
{
    _name = "dog";
}