//
// Created by megha on 2019. 04. 24..
//

#include "Violin.h"

Violin::Violin(int numberOfStrings) : StringedInstrument("Violin", numberOfStrings)
{

}
std::string Violin::sound()
{
    return "Screech";
}