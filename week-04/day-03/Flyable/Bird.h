//
// Created by megha on 2019. 04. 24..
//

#ifndef ANIMALS_BIRD_H
#define ANIMALS_BIRD_H

#include "Animal.h"
#include "Vehicle.h"
#include "Flyable.h"

class Bird : public Animal, Vehicle, Flyable {
public:
    Bird(std::string color);

    std::string getName() override;

    std::string breed() override;

    void land() override;

    void fly() override;

    void takeOff() override;

    void eat();
};


#endif //ANIMALS_BIRD_H
