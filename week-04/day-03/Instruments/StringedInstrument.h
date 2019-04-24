//
// Created by megha on 2019. 04. 24..
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H

#include "Instruments.h"


class StringedInstrument : public Instruments {
public:
    StringedInstrument(const std::string &name, int numberOfStrings);
    virtual std::string sound() = 0;
    void play() override;
protected:
    int _numberOfStrings;
};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
