//
// Created by megha on 2019. 04. 24..
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar(int numberOfStrings) : StringedInstrument("Electric Guitar", numberOfStrings)
{

}

std::string ElectricGuitar::sound()
{
    return "Twang";
}
