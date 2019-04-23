#include <iostream>
#include "Aircraft.h"
#include "F16.h"
#include "F35.h"

int main()
{
    Aircraft lol(F16);
    //lol.refill(20);
    lol.getStatus();

    return 0;
}