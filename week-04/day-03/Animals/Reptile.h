//
// Created by megha on 2019. 04. 24..
//

#ifndef ANIMALS_REPTILE_H
#define ANIMALS_REPTILE_H

#include "Animal.h"


class Reptile : public Animal {
public:
    Reptile(std::string name);

    std::string getName() override;

    std::string breed() override;

    void eat() override;
};


#endif //ANIMALS_REPTILE_H
