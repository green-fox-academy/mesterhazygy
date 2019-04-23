//
// Created by megha on 2019. 04. 23..
//

#include "F16.h"

F16::F16(Type type, int ammo, int damage) : Aircraft(type, ammo, damage)
{
    _type = Type::F16;
    _ammo = 0;
    _damage = 30;
}