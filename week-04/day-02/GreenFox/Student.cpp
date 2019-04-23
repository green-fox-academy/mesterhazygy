//
// Created by megha on 2019. 04. 23..
//

#include "Student.h"

Student::Student(std::string name, int age, Gender gender, std::string prevOrganization) : Person(name, age, gender)
{
    _prevOrganization = prevOrganization;
    _skippedDays = 0;
}

Student::Student() : Person()
{
    _prevOrganization = "The School of Life";
    _skippedDays = 0;
}

void Student::introduce()
{
    std::cout << "Hi, my name is " << getName() << ", I'm " << getAge() << " years old " << getGenderString()
              << " from " << _prevOrganization
              << " and I skipped " << _skippedDays << " days." << std::endl;
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::skipDays(int numOfDays)
{
    _skippedDays += numOfDays;
}
