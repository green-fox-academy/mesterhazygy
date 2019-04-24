//
// Created by megha on 2019. 04. 24..
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H

#include <iostream>

class Vehicle {
public:
    Vehicle(int fuel, int crew, std::string color);
protected:
    int _fuel;
    int _crew;
    std::string _color;
};


#endif //FLYABLE_VEHICLE_H
