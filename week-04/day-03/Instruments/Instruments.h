//
// Created by megha on 2019. 04. 24..
//

#ifndef INSTRUMENTS_INSTRUMENTS_H
#define INSTRUMENTS_INSTRUMENTS_H

#include <iostream>


class Instruments {
public:
    virtual void play() = 0;
protected:
    std::string _name;
};


#endif //INSTRUMENTS_INSTRUMENTS_H
