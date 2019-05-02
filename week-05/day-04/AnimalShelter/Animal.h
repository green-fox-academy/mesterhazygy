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

    virtual void heal() = 0;

    bool isAdoptable();

    std::string toString();

    const std::string &getName() const;

protected:
    std::string _name;
    std::string _ownerName;
    int _healCost;
    bool _isHealthy = false;
};


#endif //ANIMALSHELTER_ANIMAL_H
