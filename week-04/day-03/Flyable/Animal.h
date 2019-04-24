//
// Created by megha on 2019. 04. 24..
//

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H

#include <iostream>

enum Gender {
    FEMALE,
    MALE
};


class Animal {
public:
    virtual std::string getName() = 0;

    virtual std::string breed() = 0;

    virtual void eat() = 0;

protected:
    std::string _name;
    int _age;
    Gender _gender;

};


#endif //ANIMALS_ANIMAL_H
