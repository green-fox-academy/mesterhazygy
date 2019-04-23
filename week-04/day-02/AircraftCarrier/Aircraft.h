//
// Created by megha on 2019. 04. 23..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

#include <iostream>

enum Type {
    F16,
    F35
};

class Aircraft {
public:
    Aircraft(Type type);

    int getAmmo() const;

    int getDamage() const;

    int damageOutput = 0;

    virtual void fight();

    virtual int refill(int ammoRe);

    std::string getTypeString();

    void getStatus();

private:
    Type _type;
    int _ammo;
    int _damage;
    int _maxAmmo;
};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
