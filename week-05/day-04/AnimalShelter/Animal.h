//
// Created by megha on 2019. 05. 02..
//

#ifndef ANIMALSHELTER_ANIMAL_H
#define ANIMALSHELTER_ANIMAL_H

#include <iostream>

class Animal {
public:

    bool isIsHealthy() const;

    void setIsHealthy(bool isHealthy);

    int getHealCost() const;

    void heal();

    bool isAdoptable();

    std::string toString();

protected:
    std::string _name;
    std::string _ownerName;
    int _healCost;
    bool _isHealthy = false;
};


#endif //ANIMALSHELTER_ANIMAL_H
