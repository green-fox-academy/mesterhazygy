//
// Created by megha on 2019. 04. 24..
//

#ifndef ANIMALS_BIRD_H
#define ANIMALS_BIRD_H

#include "Animal.h"


class Bird : public Animal {
public:
    Bird(std::string name);

    std::string getName() override;

    std::string breed() override;

    void eat();
};


#endif //ANIMALS_BIRD_H
