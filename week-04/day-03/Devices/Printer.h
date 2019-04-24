//
// Created by megha on 2019. 04. 24..
//

#ifndef DEVICES_PRINTER_H
#define DEVICES_PRINTER_H

#include <iostream>

class Printer {
public:
    virtual std::string getSize() = 0;
    virtual void print() = 0;
};

#endif //DEVICES_PRINTER_H
