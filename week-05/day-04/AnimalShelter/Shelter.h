//
// Created by megha on 2019. 05. 02..
//

#ifndef ANIMALSHELTER_SHELTER_H
#define ANIMALSHELTER_SHELTER_H

#include <iostream>
#include <vector>
#include "Animal.h"
#include <map>


class Shelter : public Animal {
public:
    Shelter();
    int rescue(Animal*);
    std::string addAdopter();
    virtual void heal() override;
    void findNewOwner();

    const std::vector<Animal *> &getAnimals() const;

    int getBudget() const;

    void earnDonation(int);

    const std::vector<std::string> &getAdopters() const;

private:
    std::vector<Animal*> _animals;
    int _budget;
    std::vector<std::string> _adopters;
};


#endif //ANIMALSHELTER_SHELTER_H
