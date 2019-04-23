//
// Created by megha on 2019. 04. 23..
//

#ifndef GREENFOX_PERSON_H
#define GREENFOX_PERSON_H

#include <iostream>

enum Gender {
    FEMALE,
    MALE
};


class Person {
public:
    Person(const std::string &name, int age, Gender gender);

    Person();

    const std::string &getName() const;

    int getAge() const;

    Gender getGender() const;

    virtual void introduce();

    virtual void getGoal();

    std::string getGenderString();

private:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GREENFOX_PERSON_H
