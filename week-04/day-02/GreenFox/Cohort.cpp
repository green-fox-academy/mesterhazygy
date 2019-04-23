//
// Created by megha on 2019. 04. 23..
//

#include "Cohort.h"

Cohort::Cohort(std::string name)
{
    _name = name;
    _students = {};
    _mentors = {};
}

void Cohort::addStudent(Student *stud)
{
    _students.push_back(stud);
}

void Cohort::addMentor(Mentor *men)
{
    _mentors.push_back(men);
}

void Cohort::info()
{
    std::cout << "The cohort " << _name << " has " << _students.size() << " students, " << _mentors.size()
              << " mentors." << std::endl;
}