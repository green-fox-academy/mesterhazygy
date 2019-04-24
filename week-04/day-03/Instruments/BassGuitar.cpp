//
// Created by megha on 2019. 04. 24..
//

#include "BassGuitar.h"

BassGuitar::BassGuitar(int numberOFStrings) : StringedInstrument("Bassguitar", numberOFStrings)
{

}

std::string BassGuitar::sound()
{
    return "Duum-duum-duum";
}