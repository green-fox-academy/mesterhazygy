//
// Created by megha on 2019. 04. 24..
//

#ifndef DEVICES_PRINTER2D_H
#define DEVICES_PRINTER2D_H

#include "Printer.h"


class Printer2D : public Printer {
public:
    Printer2D(int sizeX, int sizeY);
    std::string getSize() override;
    void print();
private:
    int _sizeX;
    int _sizeY;
};


#endif //DEVICES_PRINTER2D_H
