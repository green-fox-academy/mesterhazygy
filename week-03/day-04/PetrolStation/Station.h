//
// Created by megha on 2019. 04. 18..
//

#ifndef PETROLSTATION_STATION_H
#define PETROLSTATION_STATION_H
#include "Car.h"
#include <iostream>


class Station {
public:
    Station(int stationGas);

    void fill(Car);
protected:
    int _stationGas;
};


#endif //PETROLSTATION_STATION_H
