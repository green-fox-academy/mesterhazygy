//
// Created by megha on 2019. 04. 23..
//

#ifndef GREENFOX_COHORT_H
#define GREENFOX_COHORT_H

#include <iostream>
#include <vector>
#include "Student.h"
#include "Mentor.h"

class Cohort {
public:
    Cohort(std::string name);

    void addStudent(Student *);

    void addMentor(Mentor *);

    void info();

private:
    std::string _name;
    std::vector<Student *> _students;
    std::vector<Mentor *> _mentors;
};


#endif //GREENFOX_COHORT_H
