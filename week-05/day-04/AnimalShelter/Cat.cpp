//
// Created by megha on 2019. 05. 02..
//

#include "Cat.h"

Cat::Cat(std::string name) : Animal()
{
    _name = name;
    _healCost = rand() % 7;
}

Cat::Cat()
{
    _name = "cat";
}
