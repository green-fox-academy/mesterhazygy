//
// Created by megha on 2019. 04. 18..
//

#ifndef PETROLSTATION_CAR_H
#define PETROLSTATION_CAR_H

#include "Station.h"


class Car {
public:
    Car(int gasAmount);

    bool isFull();
    virtual void fill() override;

    int getGasAmount() const;

    int getCapacity() const;

protected:
    int _gasAmount;
    int _capacity;
};


#endif //PETROLSTATION_CAR_H
