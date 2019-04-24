//
// Created by megha on 2019. 04. 24..
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H

#include "StringedInstrument.h"


class BassGuitar : public StringedInstrument {
public:
    BassGuitar(int numberOFStrings = 4);
    std::string sound() override;

private:
};


#endif //INSTRUMENTS_BASSGUITAR_H
