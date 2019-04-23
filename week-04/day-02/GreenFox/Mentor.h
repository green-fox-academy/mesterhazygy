//
// Created by megha on 2019. 04. 23..
//

#ifndef GREENFOX_MENTOR_H
#define GREENFOX_MENTOR_H

#include "Person.h"

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person {
public:
    Mentor(std::string name, int age, Gender gender, Level level);
    Mentor();
    void introduce() override;
    void getGoal() override;
    std::string getLevelString();

private:
    Level _level;
};


#endif //GREENFOX_MENTOR_H
