//
// Created by megha on 2019. 04. 23..
//

#ifndef AIRCRAFTCARRIER_F35_H
#define AIRCRAFTCARRIER_F35_H

#include "Aircraft.h"


class F35 : public Aircraft {
    F35(Type type, int ammo, int damage);
private:
    Type _type;
    int _ammo;
    int _damage;
};


#endif //AIRCRAFTCARRIER_F35_H
