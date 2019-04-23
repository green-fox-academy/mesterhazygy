//
// Created by megha on 2019. 04. 23..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFT_H
#define AIRCRAFTCARRIER_AIRCRAFT_H

enum Type {
    F16,
    F35
};

class Aircraft {
public:
    Aircraft(Type type, int ammo, int damage);
    int damageOutput = 0;
    virtual void fight();
    virtual void refill(int ammoRe);

private:
    Type _type;
    int _ammo;
    int _damage;
};


#endif //AIRCRAFTCARRIER_AIRCRAFT_H
