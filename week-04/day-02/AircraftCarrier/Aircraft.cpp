//
// Created by megha on 2019. 04. 23..
//

#include "Aircraft.h"


Aircraft::Aircraft(Type type)
{
    _type = type;
}

void Aircraft::fight()
{
    damageOutput = _damage * _ammo;
    _ammo = 0;
}

int Aircraft::refill(int ammoRe)
{
    if (ammoRe >= _maxAmmo) {
        _ammo = _maxAmmo;
        ammoRe -= _maxAmmo;
    } else {
        _ammo += ammoRe;
        ammoRe = 0;
    }
    return ammoRe;
}

std::string Aircraft::getTypeString()
{
    switch (_type) {
        case F16:
            return "F16";
        case F35:
            return "F35";
    }
}

void Aircraft::getStatus()
{
    std::cout << "Type: " << getTypeString() << ", ammo: " << _ammo << ", damage: " << _damage << ", all damage: "
              << damageOutput << std::endl;
}

int Aircraft::getAmmo() const
{
    return _ammo;
}

int Aircraft::getDamage() const
{
    return _damage;
}
