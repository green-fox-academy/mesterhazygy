//
// Created by megha on 2019. 04. 24..
//

#include "Helicopter.h"

Helicopter::Helicopter(int fuel, int crew, std::string color) : Vehicle(fuel, crew, color)
{

}

void Helicopter::land()
{
    std::cout << "The " << _color << " helicopter with " << _crew << " people on board, and " << _fuel << " litres of gas, has landed." << std::endl;
}

void Helicopter::fly()
{
    std::cout << "The " << _color << " helicopter is in the air, with " << _crew << " people on board, and " << _fuel << " litres of gas." << std::endl;
}

void Helicopter::takeOff()
{
    std::cout << "The " << _color << " helicopter, with " << _crew << " people on board has taken off with " << _fuel << " litres of gas." << std::endl;
}