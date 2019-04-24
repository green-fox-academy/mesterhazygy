//
// Created by megha on 2019. 04. 24..
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H

#include "StringedInstrument.h"


class Violin : public StringedInstrument {
public:
    Violin(int numberOfStrings = 4);
    std::string sound() override;
};


#endif //INSTRUMENTS_VIOLIN_H
