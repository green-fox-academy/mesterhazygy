//
// Created by megha on 2019. 04. 23..
//

#ifndef GREENFOX_STUDENT_H
#define GREENFOX_STUDENT_H

#include "Person.h"


class Student : public Person {
public:
    Student(std::string name, int age, Gender gender, std::string prevOrganization);
    Student();

    void introduce() override;
    void getGoal() override;
    void skipDays(int numOfDays);

private:
    std::string _prevOrganization;
    int _skippedDays;
};


#endif //GREENFOX_STUDENT_H
