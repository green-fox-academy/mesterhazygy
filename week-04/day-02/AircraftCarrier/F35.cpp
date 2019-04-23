//
// Created by megha on 2019. 04. 23..
//

#include "F35.h"

F35::F35(Type type, int ammo, int damage) : Aircraft(type, ammo, damage)
{
    _type = Type::F35;
    _ammo = 0;
    _damage = 50;
}