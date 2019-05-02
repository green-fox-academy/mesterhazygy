//
// Created by megha on 2019. 04. 24..
//

#ifndef DEVICES_PRINTER3D_H
#define DEVICES_PRINTER3D_H

#include <string>
#include "Printer.h"


class Printer3D : public Printer {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize() override;
    void print() override;
private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;
};


#endif //DEVICES_PRINTER3D_H
