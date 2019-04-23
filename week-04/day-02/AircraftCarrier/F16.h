//
// Created by megha on 2019. 04. 23..
//

#ifndef AIRCRAFTCARRIER_F16_H
#define AIRCRAFTCARRIER_F16_H

#include "Aircraft.h"


class F16 : public Aircraft {
    F16(Type type);

private:
    Type _type;
    int _ammo;
    int _damage;
    int _maxAmmo;
};


#endif //AIRCRAFTCARRIER_F16_H
