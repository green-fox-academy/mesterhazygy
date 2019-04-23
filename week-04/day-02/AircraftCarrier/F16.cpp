//
// Created by megha on 2019. 04. 23..
//

#include "F16.h"

F16::F16(Type type) : Aircraft(type)
{
    _ammo = 0;
    _damage = 30;
    _maxAmmo = 8;
}