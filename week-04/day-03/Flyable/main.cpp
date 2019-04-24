#include <iostream>
#include "Flyable.h"
#include "Vehicle.h"
#include "Helicopter.h"

int main()
{
    Helicopter heli(12, 346, "lila");
    heli.land();
    Helicopter apache(2, 453, "fekete");
    apache.fly();
    return 0;
}