//
// Created by megha on 2019. 05. 02..
//

#ifndef ANIMALSHELTER_CAT_H
#define ANIMALSHELTER_CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    Cat(std::string name);

    Cat();

    virtual void heal() override;

};


#endif //ANIMALSHELTER_CAT_H
