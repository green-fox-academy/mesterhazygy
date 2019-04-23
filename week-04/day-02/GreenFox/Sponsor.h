//
// Created by megha on 2019. 04. 23..
//

#ifndef GREENFOX_SPONSOR_H
#define GREENFOX_SPONSOR_H

#include "Person.h"


class Sponsor : public Person {
public:
    Sponsor(std::string name, int age, Gender gender, std::string company);

    Sponsor();

    void introduce() override;

    void getGoal() override;

    void hire();

private:
    int _hiredStudents;
    std::string _company;
};


#endif //GREENFOX_SPONSOR_H
