//
// Created by megha on 2019. 04. 24..
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "Vehicle.h"
#include "Flyable.h"

class Helicopter : public Vehicle, Flyable{
public:
    Helicopter(int fuel, int crew, std::string color);
    void land() override;
    void fly() override;
    void takeOff() override;
};


#endif //FLYABLE_HELICOPTER_H
