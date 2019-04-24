//
// Created by megha on 2019. 04. 24..
//

#include "Scanner.h"
#include <iostream>

Scanner::Scanner(int speed)
{
    _speed = speed;
}

void Scanner::scan()
{
    std::cout << "I'm scanning a document at " << _speed << " ppm." << std::endl;
}