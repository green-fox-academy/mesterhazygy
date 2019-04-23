//
// Created by megha on 2019. 04. 23..
//

#include "Mentor.h"

Mentor::Mentor(std::string name, int age, Gender gender, Level level) : Person (name, age, gender)
{
    _level = level;
}

Mentor::Mentor() : Person ()
{
    _level = INTERMEDIATE;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << getName() << " , a " << getAge() << " years old, " << getGenderString() << " , " << getLevelString() << " level mentor." << std::endl;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

std::string Mentor::getLevelString()
{
    switch (_level) {
        case JUNIOR:
            return "junior";
        case INTERMEDIATE:
            return "intermediate";
        case SENIOR:
            return "senior";
    }
}