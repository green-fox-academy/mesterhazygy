//
// Created by megha on 2019. 04. 23..
//

#include "Person.h"


Person::Person(const std::string &name, int age, Gender gender)
{
    _name = name;
    _age = age;
    _gender = gender;
}

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

const std::string &Person::getName() const
{
    return _name;
}

int Person::getAge() const
{
    return _age;
}

Gender Person::getGender() const
{
    return _gender;
}

void Person::introduce()
{
    std::cout << "Hi, my name is " << _name << ", a " << _age << " years old " << getGenderString() << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

std::string Person::getGenderString()
{
    switch (_gender) {
        case FEMALE:
            return "female";
        case MALE:
            return "male";
    }
}
