//
// Created by megha on 2019. 04. 23..
//

#include "F35.h"

F35::F35(Type type) : Aircraft(type)
{
    _ammo = 0;
    _damage = 50;
    _maxAmmo = 12;
}