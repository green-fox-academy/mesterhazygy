//
// Created by megha on 2019. 04. 17..
//
#include <iostream>
#include "Counter.h"

Counter::Counter(int original)
{
    _original = original;
    a = original;
}

Counter::Counter()
{
    _original = 0;
    a = _original;
}

int Counter::getOriginal() const
{
    return _original;
}

void Counter::adder(int userNum)
{
    _original += userNum;
}

void Counter::add()
{
    ++_original;
}

int Counter::get()
{
    return _original;
}

void Counter::reset()
{
    _original = a;
}



