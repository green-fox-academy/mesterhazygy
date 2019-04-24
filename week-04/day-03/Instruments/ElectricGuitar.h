//
// Created by megha on 2019. 04. 24..
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H

#include "StringedInstrument.h"


class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar(int numberOfStrings = 6);
    std::string sound() override;
private:
};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
