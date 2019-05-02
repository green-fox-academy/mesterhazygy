//
// Created by megha on 2019. 04. 24..
//

#include "Printer2D.h"

Printer2D::Printer2D(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}

std::string Printer2D::getSize()
{
    return std::to_string(_sizeX) + " X " + std::to_string(_sizeY);
}

void Printer2D::print()
{
    std::cout << "I'm printing something that's " << getSize() << " cm-s" << std::endl;
}