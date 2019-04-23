//
// Created by megha on 2019. 04. 23..
//

#include "Aircraft.h"


Aircraft::Aircraft(Type type, int ammo, int damage)
{
    _type = type;
    _ammo = ammo;
    _damage = damage;
}

void Aircraft::fight()
{
    int damageOutput = _damage * _ammo;
    _ammo = 0;
}

void Aircraft::refill(int ammoRe)
{
    _ammo += ammoRe;
}