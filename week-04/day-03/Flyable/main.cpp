#include <iostream>
#include "Flyable.h"
#include "Vehicle.h"
#include "Helicopter.h"
#include "Animal.h"
#include "Bird.h"

int main()
{
    Helicopter heli(12, 346, "lila");
    heli.land();
    Helicopter apache(2, 453, "fekete");
    apache.fly();
    Bird sas("piros");
    sas.takeOff();
    return 0;
}