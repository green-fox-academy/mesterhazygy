//
// Created by megha on 2019. 04. 24..
//

#include "StringedInstrument.h"

StringedInstrument::StringedInstrument(const std::string &name, int numberOfStrings)
{
    _name = name;
    _numberOfStrings = numberOfStrings;
}

void StringedInstrument::play()
{
    std::cout << _name << ", a " << _numberOfStrings << " stringed instrument that goes " << sound() << std::endl;
}
