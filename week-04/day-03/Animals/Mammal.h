//
// Created by megha on 2019. 04. 24..
//

#ifndef ANIMALS_MAMMAL_H
#define ANIMALS_MAMMAL_H

#include "Animal.h"

class Mammal : public Animal {
public:
    Mammal(std::string name);

    std::string getName() override;

    std::string breed() override;

    void eat();
};


#endif //ANIMALS_MAMMAL_H
